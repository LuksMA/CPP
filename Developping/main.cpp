#include <iostream>
#include <omp.h>

#include "DataGeneration.h"
#include "Patient.h"
#include "PatientData.h"
#include "Result.h"
#include "DataInfo.h"


using namespace std;


//void threeDepthPrint(DataGeneration &data, vector<Patient *> patients)
//{
//    double T0 = data.getSumT0();
//    int sampleSize = data.getCovariateSize();
//    double v16[16];
//    double sum[8];
//    int x;
//
//
//    for(int i=0; i<sampleSize; ++i)   // loop1
//    {
//        for(int j=i+1; j<sampleSize; ++j)    // loop2
//        {
//            for(int k=j+1; k<sampleSize; ++k)    // loop3
//            {
//                double bestLocal = 0.0;
//                int bestIndexLocal = 0;
//                int indexi = 0, indexj = 0, indexk = 0;
//                int cuti = 0, cutj = 0, cutk = 0;
//                for(auto xi : {1,2,3,4,5,6,7,8,9,10})            // loop4
//                {
//                    for(auto xj : {1,2,3,4,5,6,7,8,9,10})    // loop5
//                    {
//                        for(auto xk : {1,2,3,4,5,6,7,8,9,10})    // loop6
//                        {
//                            std::fill_n(v16,16,0.0);
//                            for(auto p : patients)
//                            {
//                                x = p->criteria(i,xi,j,xj,k,xk);
//                                v16[x] += *p->getYPtr();
//                            }
//
//                            sum[0] = v16[0]-v16[1];
//                            sum[1] = v16[2]-v16[3];
//                            sum[2] = v16[4]-v16[5];
//                            sum[3] = v16[6]-v16[7];
//                            sum[4] = v16[8]-v16[9];
//                            sum[5] = v16[10]-v16[11];
//                            sum[6] = v16[12]-v16[13];
//                            sum[7] = v16[14]-v16[15];
//
//                            const auto ptr = max_element(sum,sum+8);
//                            double temp = *ptr + T0;
//
//                            if(temp > bestLocal)
//                            {
//                                bestLocal = temp;
//                                bestIndexLocal = distance(sum, ptr);
//                                indexi = i;
//                                indexj = j;
//                                indexk = k;
//                                cuti = xi;
//                                cutj = xj;
//                                cutk = xk;
//                            }
//                        }
//                    }
//                }
//                cout<<bestLocal*2/data.getSampleSize()<<" Index: "
//                    <<"["<<indexi<<" "<<cuti<<" "
//                    <<"] ["<<indexj<<" "<<cutj<<" "
//                    <<"] ["<<indexk<<" "<<cutk<<" "
//                    <<"]"<<bestIndexLocal<<endl;
//            }
//        }
//    }
//}

void threeDepthPrint(DataGeneration &data, vector<Patient *> patients, DataInfo* *info)
{
    double T0 = data.getSumT0();
    int sampleSize = data.getCovariateSize();
    double v16[16];
    double sum[8];
    int x;

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
                for(auto xi : info[i]->getRange())            // loop4
                {
                    for(auto xj : info[j]->getRange())        // loop5
                    {
                        for(auto xk : info[k]->getRange())    // loop6
                        {
                            std::fill_n(v16,16,0.0);
                            for(auto p : patients)
                            {
                                x = p->criteria(i,xi,j,xj,k,xk);
                                v16[x] += *p->getYPtr();
                            }

                            sum[0] = v16[0]-v16[1];
                            sum[1] = v16[2]-v16[3];
                            sum[2] = v16[4]-v16[5];
                            sum[3] = v16[6]-v16[7];
                            sum[4] = v16[8]-v16[9];
                            sum[5] = v16[10]-v16[11];
                            sum[6] = v16[12]-v16[13];
                            sum[7] = v16[14]-v16[15];

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
                cout<<bestLocal*2/data.getSampleSize()<<" Index: "
                    <<"["<<indexi<<" "<<cuti<<" "
                    <<"] ["<<indexj<<" "<<cutj<<" "
                    <<"] ["<<indexk<<" "<<cutk<<" "
                    <<"]"<<bestIndexLocal<<endl;
            } // end loop 3
        } // end loop 2
    } // end loop 1
}



//vector<Result *> threeDepth(DataGeneration &data, vector<Patient *> patients)
//{
//    int sampleSize = data.getCovariateSize();
//    vector<Result *> solutions;
//    solutions.reserve(20000000);
//
//    double v16[16];
//
//    vector<int> range = {1,2,3,4,5,6,7,8,9,10};
//
//    for(unsigned short i=0; i<sampleSize; ++i)   // loop1
//    {
//        for(unsigned short j=i+1; j<sampleSize; ++j)    // loop2
//        {
//            for(unsigned short k=j+1; k<sampleSize; ++k)    // loop3
//            {
//                for(auto xi :range)            // loop4
//                {
//                    for(auto xj :range)    // loop5
//                    {
//                        for(auto xk :range)    // loop6
//                        {
//
//                            std::fill_n(v16,16,0.0);
//                            for(auto p : patients)
//                            {
//                                int x = p->criteria(i,xi,j,xj,k,xk);
//                                v16[x] += *p->getYPtr();
//                            }
//                            solutions.push_back(new Result(v16[0]-v16[1],i,xi,0,j,xj,0,k,xk,0));
//                            solutions.push_back(new Result(v16[2]-v16[3],i,xi,0,j,xj,0,k,xk,1));
//                            solutions.push_back(new Result(v16[4]-v16[5],i,xi,0,j,xj,1,k,xk,0));
//                            solutions.push_back(new Result(v16[6]-v16[7],i,xi,0,j,xj,1,k,xk,1));
//                            solutions.push_back(new Result(v16[8]-v16[9],i,xi,1,j,xj,0,k,xk,0));
//                            solutions.push_back(new Result(v16[10]-v16[11],i,xi,1,j,xj,0,k,xk,1));
//                            solutions.push_back(new Result(v16[12]-v16[13],i,xi,1,j,xj,1,k,xk,0));
//                            solutions.push_back(new Result(v16[14]-v16[15],i,xi,1,j,xj,1,k,xk,1));
//                        } // end loop 6
//                    } // end loop 5
//                } // end loop 4
//            } // end loop 3
//        } // end loop 2
//    } // end loop 1
//    return solutions;
//}




int main()
{
    /// Test data generation class
    vector<int> varType(35,0); /// 0 for cont, 1 for ordinal, 2 for nominal
    vector<double> rangesCont = {10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0};
    vector<int> rangesOrd = {};
    vector<int> rangesNom = {};
    vector<double> rangesY = {0.0,100.0};
    vector<int> rangesAction = {0,1};

    DataGeneration data(varType,rangesY,rangesAction,rangesCont,rangesOrd,rangesNom);
    data.creatSamples(3000);
    data.preprocessing();
//    data.printInfo(6);

    /// Create patient objects
    PatientData pData(data);
    vector<Patient *> patients = pData.getPatients();
//    pData.printPatients();

    /// Create data info
    DataInfo* info[data.getCovariateSize()];
    for(int i=0;i<data.getCovariateSize();++i){
        info[i] = new DataInfo(i,varType[i],data.getDataSet()[i]);
    }


    /// Three Depth
//    threeDepthPrint(data,patients);
//    threeDepth(data,patients);
    threeDepthPrint(data,patients,info);











}


