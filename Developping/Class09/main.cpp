#include <iostream>

#include "DataGeneration.h"
#include "Patient.h"
#include "PatientData.h"
#include "VariableInfo.h"


using namespace std;


vector<VariableInfo *> creatVariableInfo(vector<vector<int>> dataSet,vector<int> varType);
template<class T> void print1DVector(vector<T> const &vectIn);
vector<int> binary(int num);



void threeDepthPrint(DataGeneration &data, vector<VariableInfo *> varInfo, vector<Patient *> patients)
{
    double T0 = data.getSumT0();
    int sampleSize = data.getCovariateSize();
//int sampleSize = 5;
    for(int i=0; i<sampleSize; ++i)   // loop1
    {
        for(int j=i+1; j<sampleSize; ++j)    // loop2
        {
            for(int k=j+1; k<sampleSize; ++k)    // loop3
            {

                double bestLocal = 0.0;
                int bestIndexLocal = 0;
                int indexi = 0, indexj = 0, indexk = 0;
                int cuti = 0, cutj = 0, cutk = 0;
                for(auto & xi : varInfo[i]->getCuts())            // loop4
                {
                    for(auto & xj : varInfo[j]->getCuts())    // loop5
                    {
                        for(auto & xk : varInfo[k]->getCuts())    // loop6
                        {
                            double v0000 = 0.0, v0001 = 0.0, v0010 = 0.0, v0011 = 0.0;
                            double v0100 = 0.0, v0101 = 0.0, v0110 = 0.0, v0111 = 0.0;
                            double v1000 = 0.0, v1001 = 0.0, v1010 = 0.0, v1011 = 0.0;
                            double v1100 = 0.0, v1101 = 0.0, v1110 = 0.0, v1111 = 0.0;

                            for(auto p : patients)
                            {
                                if(p->criteria(i,xi,varInfo[i]))
                                {
                                    if(p->criteria(j,xj,varInfo[j]))
                                    {
                                        if(p->criteria(k,xk,varInfo[k]))
                                        {
                                            if(p->getAction()[0] == 1)
                                            {
                                                v0000 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v0001 += p->getY()[0];
                                            }
                                        }
                                        else
                                        {
                                            if(p->getAction()[0] == 1)
                                            {
                                                v0010 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v0011 += p->getY()[0];
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(p->criteria(k,xk,varInfo[k]))
                                        {
                                            if(p->getAction()[0] == 1)
                                            {
                                                v0100 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v0101 += p->getY()[0];
                                            }
                                        }
                                        else
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v0110 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v0111 += p->getY()[0];
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if(p->criteria(j,xj,varInfo[j]))
                                    {
                                        if(p->criteria(k,xk,varInfo[k]))
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v1000 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v1001 += p->getY()[0];
                                            }
                                        }
                                        else
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v1010 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v1011 += p->getY()[0];
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(p->criteria(k,xk,varInfo[k]))
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v1100 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v1101 += p->getY()[0];
                                            }
                                        }
                                        else
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v1110 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v1111 += p->getY()[0];
                                            }
                                        }
                                    }
                                }
                            }

                            double sum1 = v0000 - v0001;
                            double sum2 = v0010 - v0011;
                            double sum3 = v0100 - v0101;
                            double sum4 = v0110 - v0111;
                            double sum5 = v1000 - v1001;
                            double sum6 = v1010 - v1011;
                            double sum7 = v1100 - v1101;
                            double sum8 = v1110 - v1111;

                            double sum[] = {sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8};

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
                        }
                    }
                }
                vector<int> bIndex = binary(bestIndexLocal);
                vector<int> filter1 = {indexi, cuti, bIndex[0]};
                vector<int> filter2 = {indexj, cutj, bIndex[1]};
                vector<int> filter3 = {indexk, cutk, bIndex[2]};
                cout<<bestLocal*2/data.getSampleSize()<<" Index: ";
                print1DVector(filter1);
                print1DVector(filter2);
                print1DVector(filter3);
                cout<<endl;
            }
        }
    }
}








int main()
{
    /// Test data generation class
    vector<int> varType= {0,0,0,1,1,1,2,2,2}; /// 0 for cont, 1 for ordinal, 2 for nominal
    vector<double> rangesCont = {0.0,100.0,10.0,200.0,50.0,300.0};
    vector<int> rangesOrd = {0,4,0,4,0,4};
    vector<int> rangesNom = {0,4,0,4,0,4};
    vector<double> rangesY = {0.0,100.0};
    vector<int> rangesAction = {0,1};

    DataGeneration data(varType,rangesY,rangesAction,rangesCont,rangesOrd,rangesNom);
    data.creatSamples(300);
    data.preprocessing();
//    data.printInfo(6);

    /// Create patient objects
    PatientData pData(data);
    vector<Patient *> patients = pData.getPatients();
//    pData.printPatients(patients);

    /// Create variable information objects
    vector<VariableInfo *> varInfo = creatVariableInfo(data.getDataSet(),data.getVarType());
//    varInfo.at(6)->printVarInfo();
//    print1DVector(varInfo[6]->getCuts());cout<<endl;
//    print1DVector(varInfo[6]->getNominalCut(24));

    /// Three Depth
    threeDepthPrint(data,varInfo,patients);






}




/*****************************************************************************************************************************************************/
vector<VariableInfo *> creatVariableInfo(vector<vector<int>> dataSet,vector<int> varType)
{
    vector<VariableInfo *> variables;
    for(unsigned int i=0; i<varType.size(); ++i)
    {
        variables.push_back(new VariableInfo(i,varType.at(i),dataSet.at(i)));
    }
    return variables;
}

template<class T>
void print1DVector(vector<T> const &vectIn)
{
    cout<<"[ ";
    for(const auto &row : vectIn)
    {
        cout<<row<<' ';
    }
    cout<<']';
}


vector<int> binary(int num)
{
    if(num == 0)
    {
        return {-1,-1,-1};
    }
    else if(num == 1)
    {
        return {-1,-1,1};
    }
    else if(num == 2)
    {
        return {-1,1,-1};
    }
    else if(num == 3)
    {
        return {-1,1,1};
    }
    else if(num == 4)
    {
        return {1,-1,-1};
    }
    else if(num == 5)
    {
        return {1,-1,1};
    }
    else if(num == 6)
    {
        return {1,1,-1};
    }
    else if(num == 7)
    {
        return {1,1,1};
    }
    else
    {
        cout<<"Incorrect input in binary function.\n";
        return {0};
    }
}
