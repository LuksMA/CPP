#include "ITR.h"

ITR::ITR(DataGeneration &data)
{
    sample_Size = data.getSampleSize();
    var_Size = data.getCovariateSize();
    action_Size = data.getActionSize();
    y_Size = data.getYSize();
    T0 = data.getSumT0();

    var_X = new int*[sample_Size];
    var_A = new int*[sample_Size];
    var_Y = new double*[sample_Size];
    table_X = new bool**[var_Size];

    for(int i=0; i<sample_Size; ++i)
    {
        var_X[i] = new int[var_Size];
        var_A[i] = new int[action_Size];
        var_Y[i] = new double[y_Size];
    }
    for(int i=0; i<var_Size; ++i)
    {
        table_X[i] = new bool*[10];
        for(int j=0; j<10; ++j)
        {
            table_X[i][j] = new bool[sample_Size];
            for(int k=0; k<sample_Size; ++k){
                table_X[i][j][k] = 0;
            }
        }
    }

    loadX(data.getDataSet());
    loadAction(data.getActions());
    loadY(data.getY());
    table_X_gen(data.getDataSet());

}

ITR::~ITR()
{
    //dtor
    cleanAll();
}

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



void ITR :: loadX(vector<vector<int>> x)
{
    for(int i=0; i<sample_Size; ++i)
    {
        for(int j=0; j<var_Size; ++j)
        {
            var_X[i][j] = x[j][i];
        }
    }
}

void ITR :: loadAction(vector<vector<int>> a)
{
    for(int i=0; i<sample_Size; ++i)
    {
        for(int j=0; j<action_Size; ++j)
        {
            var_A[i][j] = a[j][i];
        }
    }
}

void ITR :: loadY(vector<vector<double>> y)
{
    for(int i=0; i<sample_Size; ++i)
    {
        for(int j=0; j<y_Size; ++j)
        {
            var_Y[i][j] = y[j][i];
        }
    }
}


void ITR :: table_X_gen(vector<vector<int>> x){
    for(int i=0; i<var_Size; ++i){
        for(int j=0; j<sample_Size; ++j){
            for(int k=0; k<10; ++k){
                if(x[i][j] < range[k]){
                    table_X[i][k][j] = 1;
                }else{
                    table_X[i][k][j] = 0;
                }
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
        for(int j=0; j<10; ++j)
        {
            delete [] table_X[i][j];
        }
        delete [] table_X[i];
    }
    delete table_X;

}


void ITR :: threeDepthPrint(){
    double v[16];
    double sum[8];

    bool** x1;
    bool** x2;
    bool** x3;
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
    {   x1 = table_X[i];
        for(int j=i+1; j<var_Size; ++j)    // loop2
        {   x2 = table_X[j];
            for(int k=j+1; k<var_Size; ++k)    // loop3
            {   x3 = table_X[k];
                bestLocal = 0.0;
                bestIndexLocal = 0;
                indexi = 0, indexj = 0, indexk = 0;
                cuti = 0, cutj = 0, cutk = 0;

                for(auto xi : {0,1,2,3,4,5,6,7,8,9})            // loop4
                {
                    x1c = x1[xi];
                    for(auto xj : {0,1,2,3,4,5,6,7,8,9})        // loop5
                    {
                        x2c = x2[xj];
                        for(auto xk : {0,1,2,3,4,5,6,7,8,9})    // loop6
                        {
                            x3c = x3[xk];

                            std::fill_n(v,16,0.0);
                            for(int p=0; p<sample_Size; ++p)
                            {
                                row_Y = var_Y[p];
                                row_A = var_A[p];
                                v[x1c[p]*8+x2c[p]*4+x3c[p]*2 + *row_A] =  *row_Y;
                            }

                            sum[0] = v[0]-v[1];
                            sum[1] = v[2]-v[3];
                            sum[2] = v[4]-v[5];
                            sum[3] = v[6]-v[7];
                            sum[4] = v[8]-v[9];
                            sum[5] = v[10]-v[11];
                            sum[6] = v[12]-v[13];
                            sum[7] = v[14]-v[15];

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




//vector<Result *> ITR :: threeDepth(){
//    vector<Result *> solutions;
//    solutions.reserve(20000000);
//    double v[16];
//
//    int** index_X1;
//    int** index_X2;
//    int** index_X3;
//    int*  index_X1_c;
//    int*  index_X2_c;
//    int*  index_X3_c;
//
//    int* row_A;
//    double* row_Y;
//
//    for(int i=0; i<var_Size; ++i)   // loop1
//    {
//        for(int j=i+1; j<var_Size; ++j)    // loop2
//        {
//            for(int k=j+1; k<var_Size; ++k)    // loop3
//            {
//
//                index_X1 = table_X[i];
//                index_X2 = table_X[j];
//                index_X3 = table_X[k];
//
//                for(auto xi : {0,1,2,3,4,5,6,7,8,9})            // loop4
//                {
//                    index_X1_c = index_X1[xi];
//                    for(auto xj : {0,1,2,3,4,5,6,7,8,9})        // loop5
//                    {
//                        index_X2_c = index_X2[xj];
//                        for(auto xk : {0,1,2,3,4,5,6,7,8,9})    // loop6
//                        {
//                            index_X3_c = index_X3[xk];
//
//                            std::fill_n(v,16,0.0);
//                            for(int k=0; k<sample_Size; ++k)
//                            {
//                                row_Y = var_Y[k];
//                                row_A = var_A[k];
//                                v[index_X1_c[k]*8+index_X2_c[k]*4+index_X3_c[k]*2 + *row_A] =  *row_Y;
//                            }
//
//                            solutions.push_back(new Result(T0+v[0]-v[1],i,xi,0,j,xj,0,k,xk,0));
//                            solutions.push_back(new Result(T0+v[2]-v[3],i,xi,0,j,xj,0,k,xk,1));
//                            solutions.push_back(new Result(T0+v[4]-v[5],i,xi,0,j,xj,1,k,xk,0));
//                            solutions.push_back(new Result(T0+v[6]-v[7],i,xi,0,j,xj,1,k,xk,1));
//                            solutions.push_back(new Result(T0+v[8]-v[9],i,xi,1,j,xj,0,k,xk,0));
//                            solutions.push_back(new Result(T0+v[10]-v[11],i,xi,1,j,xj,0,k,xk,1));
//                            solutions.push_back(new Result(T0+v[12]-v[13],i,xi,1,j,xj,1,k,xk,0));
//                            solutions.push_back(new Result(T0+v[14]-v[15],i,xi,1,j,xj,1,k,xk,1));
//                        } // end loop 6
//                    } // end loop 5
//                } // end loop 4
//            } // end loop 3
//        } // end loop 2
//    } // end loop 1
//    return solutions;
//}
