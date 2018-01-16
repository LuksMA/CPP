#include "ITR.h"

ITR::ITR(DataGeneration &data, int d)
{
    depth = d;
    var_Type = data.getVarType();
    sample_Size = data.getSampleSize();
    var_Size = data.getVariateSize();
    action_Size = data.getActionSize();
    y_Size = data.getYSize();
    lookup = combine(var_Size, depth);
    T0 = data.getSumT0();

    init();

    for(int i=0; i<var_Size; ++i)
    {
        info[i].load_DataInfo(i,var_Type[i],data.getDataSet()[i]);
    }
    load_CutSize();
    load_X(data.getDataSet());
    load_Action(data.getActions());
    load_Y(data.getY());

    init_TableX();
    load_table_X(data.getDataSet());
}

ITR::~ITR()
{
    //dtor
    cleanAll();
}

void ITR::init()
{
    var_X = new int*[sample_Size] {};
    var_A = new int*[sample_Size] {};
    var_Y = new double*[sample_Size];
    table_X = new bool**[var_Size] {};
    cut_Size = new int[var_Size] {};
    info = new DataInfo[var_Size];

    for(int i=0; i<sample_Size; ++i)
    {
        var_X[i] = new int[var_Size] {};
        var_A[i] = new int[action_Size] {};
        var_Y[i] = new double[y_Size] {};
    }
}

void ITR::init_TableX()
{
    for(int i=0; i<var_Size; ++i)
    {
        table_X[i] = new bool*[cut_Size[i]] {};
        for(int j=0; j<cut_Size[i]; ++j)
        {
            table_X[i][j] = new bool[sample_Size] {};
        }
    }
}



/// Get
int ITR::getSampleSize()
{
    return sample_Size;
}
int ITR::getVarSize()
{
    return var_Size;
}
int ITR::getActionSize()
{
    return action_Size;
}
int ITR::getYSize()
{
    return y_Size;
}

/// Print
void ITR :: print_X()
{
    for(int i=0; i<sample_Size; ++i)
    {
        for(int j=0; j<var_Size; ++j)
        {
            cout<<var_X[i][j]<<' ';
        }
        cout<<endl;
    }
}

void ITR :: print_Action()
{
    for(int i=0; i<sample_Size; ++i)
    {
        for(int j=0; j<action_Size; ++j)
        {
            cout<<var_A[i][j]<<' ';
        }
        cout<<endl;
    }
}

void ITR :: print_Y()
{
    for(int i=0; i<sample_Size; ++i)
    {
        for(int j=0; j<y_Size; ++j)
        {
            cout<<var_Y[i][j]<<' ';
        }
        cout<<endl;
    }
}

void ITR :: print_All()
{
    for(int i=0; i<sample_Size; ++i)
    {
        cout<<"X: ";
        for(int x=0; x<var_Size; ++x)
        {
            cout<<var_X[i][x]<<' ';
        }
        cout<<" Action: ";
        for(int y=0; y<action_Size; ++y)
        {
            cout<<var_A[i][y]<<' ';
        }
        cout<<" Y: ";
        for(int z=0; z<y_Size; ++z)
        {
            cout<<var_Y[i][z]<<' ';
        }
        cout<<endl;
    }
}

void ITR :: print_Range()
{
    cout<<"Cut range:\n";
    for(int i=0; i<var_Size; ++i)
        cout<<cut_Size[i]<<' ';
}

void ITR :: print_Type()
{
    cout<<"Covariant type:\n";
    for(int i=0; i<var_Size; ++i)
    {
        cout<<var_Type[i]<<' ';
    }
}

void ITR :: print_CutTable()
{
    for(int i=0; i<var_Size; ++i)
    {
        cout<<"Var: "<<i
            <<"\tType: "<<var_Type[i]
            <<"\tCut Size: "<<cut_Size[i]
            <<endl;
        cout<<"\t ";

        for(int xi=0; xi<sample_Size; ++xi)
        {
            cout<<var_X[xi][i]<<' ';
        }
        cout<<endl;
        for(int j=0; j<cut_Size[i]; ++j)
        {
            if(var_Type[i]==2)
            {
                cout<<info[i].getRange(j)<<":";
                info[i].printSet(j);
            }
            else
            {
                cout<<info[i].getRange(j)<<":\t";
            }
            for(int k=0; k<sample_Size; ++k)
            {
                cout<<table_X[i][j][k]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

void ITR :: print_VarInfo(int i)
{
    info[i].printVarInfo();
}

void ITR :: print_VarInfo()
{
    for(int i=0; i<var_Size; ++i)
    {
        info[i].printVarInfo();
        cout<<endl;
    }
}


void ITR :: print_Combinations()
{
    int no = 0;
    for(auto x : lookup)
    {
        cout<<no++<<": ";
        cout<<"[ ";
        for(const auto &row : x)
            cout<<row<<' ';
        cout<<']'<<endl;
    }
}


/// Load
void ITR :: load_CutSize()
{
    for(int i=0; i<var_Size; ++i)
        cut_Size[i] = info[i].getCutSize();
}


void ITR :: load_X(vector<vector<int>> x)
{
    for(int i=0; i<sample_Size; ++i)
    {
        for(int j=0; j<var_Size; ++j)
        {
            var_X[i][j] = x[j][i];
        }
    }
}

void ITR :: load_Action(vector<vector<int>> a)
{
    for(int i=0; i<sample_Size; ++i)
    {
        for(int j=0; j<action_Size; ++j)
        {
            var_A[i][j] = a[j][i];
        }
    }
}

void ITR :: load_Y(vector<vector<double>> y)
{
    for(int i=0; i<sample_Size; ++i)
    {
        for(int j=0; j<y_Size; ++j)
        {
            var_Y[i][j] = y[j][i];
        }
    }
}


void ITR :: load_table_X(vector<vector<int>> x)
{
    init_TableX();
    for(int i=0; i<var_Size; ++i)
    {
        for(int j=0; j<sample_Size; ++j)
        {
            for(int k=0; k<cut_Size[i]; ++k)
            {
                table_X[i][k][j] = (var_Type[i] == 2)?info[i].nomContains(x[i][j],k):x[i][j] < info[i].getRange(k);
            }
        }
    }
}

void ITR :: cleanAll()
{
    for(int i=0; i<sample_Size; ++i)
    {
        delete [] var_X[i];
        delete [] var_A[i];
        delete [] var_Y[i];
    }
    delete var_X;
    delete var_A;
    delete var_Y;

    for(int i=0; i<var_Size; ++i)
    {
        for(int j=0; j<cut_Size[i]; ++j)
        {
            delete [] table_X[i][j];
        }
        delete [] table_X[i];
    }
    delete table_X;
    delete [] cut_Size;
    delete [] info;
}


void ITR :: DepthPrint()
{
    int v_size = pow(2,depth+1);
    int sum_size = pow(2,depth);

    double* v = new double[v_size] {};
    double* sum = new double[sum_size] {};
    int* var_No = new int[depth]{};
    int* cut_No = new int[depth]{};
//    bool** x = new bool*[depth]{};
    bool** x = new bool*[3];
    int* comb = new int[depth]{};
    int* row_A;
    double* row_Y;
//    for(int i=0; i<depth; ++i){
//        x[i] = new bool[sample_Size];
//    }


    double bestLocal = 0;
    int bestIndexLocal = 0;
    int max_comb;
    int temp;
    int index;
    int comb_temp;

    for(auto const &vec : lookup)   // loop over variable combinations
    {
        for(int c=0; c<depth; ++c)
        {
            comb[c] = cut_Size[vec[c]];
            var_No[c] = vec[c];
        }

        max_comb = 1;
        for(int m=0; m<depth; ++m)   // maximum counting
        {
            max_comb *= comb[m];
        }

        for(int i=0; i<max_comb; ++i)  // Given variables, loop cuts combinations
        {
            temp = i;
            for(int j=0; j<depth; ++j)
            {
                index = temp % comb[j];
                temp /= comb[j];
                x[j] = table_X[var_No[j]][index];
                cut_No[j] = index;
            }
            std::fill_n(v,v_size,0.0);

            for(int p=0; p<sample_Size; ++p)
            {
                row_Y = var_Y[p];
                row_A = var_A[p];
                v[x[0][p]*8+x[1][p]*4+x[2][p]*2 + *row_A] +=  *row_Y;
            }

            for(int k=0; k<sum_size; ++k){
                sum[k] = v[2*k+1] - v[2*k];
            }

            const auto ptr = max_element(sum,sum+sum_size);
            double temp_res = *ptr + T0;

            bestLocal = temp_res;
            bestIndexLocal = distance(sum, ptr);

        } // end cut loop
        cout<<bestLocal*2/sample_Size<<" Index: "
            <<"["<<var_No[0]<<" "<<cut_No[0]<<" "
            <<"] ["<<var_No[1]<<" "<<cut_No[1]<<" "
            <<"] ["<<var_No[2]<<" "<<cut_No[2]<<" "
            <<"]"<<bestIndexLocal<<endl;
    } // end lookup loop



    delete [] v;
    delete [] sum;
    delete [] comb;
//    for(int i=0; i<depth; ++i){
//        delete [] x[i];
//    }
//    delete [] x;
}

void ITR :: threeDepthPrint()
{
    double v[16];   // 0000 to 1111
    double sum[8];

    bool*  x1c;
    bool*  x2c;
    bool*  x3c;
    int* row_A;
    double* row_Y;

    double bestLocal;
    int bestIndexLocal;
    int indexi, indexj, indexk;
    int cuti, cutj, cutk;


    for(int i=0; i<var_Size; ++i)   // loop1
    {
        for(int j=i+1; j<var_Size; ++j)    // loop2
        {
            for(int k=j+1; k<var_Size; ++k)    // loop3
            {
                bestLocal = 0.0;
                bestIndexLocal = 0;
                indexi = 0, indexj = 0, indexk = 0;
                cuti = 0, cutj = 0, cutk = 0;

                for(int xi=0; xi<cut_Size[i]; ++xi) // loop4
                {
                    x1c = table_X[i][xi];
                    for(int xj=0; xj<cut_Size[j]; ++xj)        // loop5
                    {
                        x2c = table_X[j][xj];
                        for(int xk=0; xk<cut_Size[k]; ++xk) // loop6
                        {
                            x3c = table_X[k][xk];

                            std::fill_n(v,16,0.0);
                            for(int p=0; p<sample_Size; ++p)
                            {
                                row_Y = var_Y[p];
                                row_A = var_A[p];
                                v[x1c[p]*8+x2c[p]*4+x3c[p]*2 + *row_A] +=  *row_Y;
                            }

                            sum[0] = v[1]-v[0];   // 000 (0001-0000)
                            sum[1] = v[3]-v[2];   // 001 (0011-0010)
                            sum[2] = v[5]-v[4];   // 010 (0101-0100)
                            sum[3] = v[7]-v[6];   // 011 (0111-0110)
                            sum[4] = v[9]-v[8];   // 100 (1001-1000)
                            sum[5] = v[11]-v[10]; // 101 (1011-1010)
                            sum[6] = v[13]-v[12]; // 110 (1101-1100)
                            sum[7] = v[15]-v[14]; // 111 (1111-1110)

                            const auto ptr = max_element(sum,sum+8);
                            double temp = *ptr + T0;

                            if(temp > bestLocal)
                            {
                                bestLocal = temp;
                                bestIndexLocal = distance(sum, ptr);
                                indexi = i;
                                indexj = j;
                                indexk = k;
                                cuti = xi;
                                cutj = xj;
                                cutk = xk;
                            }
                        } // end loop 6
                    } // end loop 5
                } // end loop 4
                cout<<bestLocal*2/sample_Size<<" Index: "
                    <<"["<<indexi<<" "<<cuti<<" "
                    <<"] ["<<indexj<<" "<<cutj<<" "
                    <<"] ["<<indexk<<" "<<cutk<<" "
                    <<"]"<<bestIndexLocal<<endl;
            } // end loop 3
        } // end loop 2
    } // end loop 1
} // end threeDepthPrint()




vector<Result *> ITR :: threeDepth()
{
    vector<Result *> solutions;
    solutions.reserve(20000000);
    double v[16];

    bool*  x1c;
    bool*  x2c;
    bool*  x3c;
    int* row_A;
    double* row_Y;

    for(int i=0; i<var_Size; ++i)   // loop1
    {
        for(int j=i+1; j<var_Size; ++j)    // loop2
        {
            for(int k=j+1; k<var_Size; ++k)    // loop3
            {
                for(int xi=0; xi<cut_Size[i]; ++xi)            // loop4
                {
                    x1c = table_X[i][xi];
                    for(int xj=0; xj<cut_Size[j]; ++xj)        // loop5
                    {
                        x2c = table_X[j][xj];
                        for(int xk=0; xk<cut_Size[k]; ++xk)    // loop6
                        {
                            x3c = table_X[k][xk];

                            std::fill_n(v,16,0.0);
                            for(int p=0; p<sample_Size; ++p)
                            {
                                row_Y = var_Y[p];
                                row_A = var_A[p];
                                v[x1c[p]*8+x2c[p]*4+x3c[p]*2 + *row_A] +=  *row_Y;
                            }
                            solutions.push_back(new Result(T0+v[1]-v[0],i,xi,0,j,xj,0,k,xk,0));   // 000
                            solutions.push_back(new Result(T0+v[3]-v[2],i,xi,0,j,xj,0,k,xk,1));   // 001
                            solutions.push_back(new Result(T0+v[5]-v[4],i,xi,0,j,xj,1,k,xk,0));   // 010
                            solutions.push_back(new Result(T0+v[7]-v[6],i,xi,0,j,xj,1,k,xk,1));   // 011
                            solutions.push_back(new Result(T0+v[9]-v[8],i,xi,1,j,xj,0,k,xk,0));   // 100
                            solutions.push_back(new Result(T0+v[11]-v[10],i,xi,1,j,xj,0,k,xk,1)); // 101
                            solutions.push_back(new Result(T0+v[13]-v[12],i,xi,1,j,xj,1,k,xk,0)); // 110
                            solutions.push_back(new Result(T0+v[15]-v[14],i,xi,1,j,xj,1,k,xk,1)); // 111
                        } // end loop 6
                    } // end loop 5
                } // end loop 4
            } // end loop 3
        } // end loop 2
    } // end loop 1
    return solutions;
} // end threeDepth()



vector<vector<int>> ITR :: combine(int n, int k)
{
    vector<vector<int>> vectOut;
    int i = 0;
    vector<int> p(k, -1);
    while (i >= 0)
    {
        p[i]++;
        if (p[i] > n-1) --i;
        else if (i == k - 1) vectOut.push_back(p);
        else
        {
            ++i;
            p[i] = p[i - 1];
        }
    }
    return vectOut;
}


//int ITR :: nChoosek( int n, int k )
//{
//    if (k > n) return 0;
//    if (k * 2 > n) k = n-k;
//    if (k == 0) return 1;
//
//    int result = n;
//    for( int i = 2; i <= k; ++i ) {
//        result *= (n-i+1);
//        result /= i;
//    }
//    return result;
//}

