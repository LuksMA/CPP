#include <iostream>


#include "DataGeneration.h"
#include "Patient.h"
#include "PatientData.h"


using namespace std;


//vector<int> binary(int num);
bitset<3> binaryBit(int &num);
template<class T> void print1DVector(vector<T> const &vectIn);



void threeDepthPrint(DataGeneration &data, vector<Patient *> patients)
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
                for(auto xi : { 1,2,3,4,5,6,7,8,9,10 })            // loop4
                {
                    for(auto xj : { 1,2,3,4,5,6,7,8,9,10 })    // loop5
                    {
                        for(auto xk : { 1,2,3,4,5,6,7,8,9,10 })    // loop6
                        {
                            double v0000 = 0.0, v0001 = 0.0, v0010 = 0.0, v0011 = 0.0;
                            double v0100 = 0.0, v0101 = 0.0, v0110 = 0.0, v0111 = 0.0;
                            double v1000 = 0.0, v1001 = 0.0, v1010 = 0.0, v1011 = 0.0;
                            double v1100 = 0.0, v1101 = 0.0, v1110 = 0.0, v1111 = 0.0;

                            for(auto p : patients)
                            {
                                bitset<4> flag = p->criteria(i,xi,j,xj,k,xk);

                                if(flag[0])
                                {
                                    if(flag[1])
                                    {
                                        if(flag[2])
                                        {
                                            if(flag[3])
                                            {
                                                v0000 += p->getY(0);
                                            }
                                            else
                                            {
                                                v0001 += p->getY(0);
                                            }
                                        }
                                        else
                                        {
                                            if(flag[3])
                                            {
                                                v0010 += p->getY(0);
                                            }
                                            else
                                            {
                                                v0011 += p->getY(0);
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(flag[2])
                                        {
                                            if(flag[3])
                                            {
                                                v0100 += p->getY(0);
                                            }
                                            else
                                            {
                                                v0101 += p->getY(0);
                                            }
                                        }
                                        else
                                        {
                                            if(flag[3])
                                            {
                                                v0110 += p->getY(0);
                                            }
                                            else
                                            {
                                                v0111 += p->getY(0);
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if(flag[1])
                                    {
                                        if(flag[2])
                                        {
                                            if(flag[3])
                                            {
                                                v1000 += p->getY(0);
                                            }
                                            else
                                            {
                                                v1001 += p->getY(0);
                                            }
                                        }
                                        else
                                        {
                                            if(flag[3])
                                            {
                                                v1010 += p->getY(0);
                                            }
                                            else
                                            {
                                                v1011 += p->getY(0);
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(flag[2])
                                        {
                                            if(flag[3])
                                            {
                                                v1100 += p->getY(0);
                                            }
                                            else
                                            {
                                                v1101 += p->getY(0);
                                            }
                                        }
                                        else
                                        {
                                            if(flag[3])
                                            {
                                                v1110 += p->getY(0);
                                            }
                                            else
                                            {
                                                v1111 += p->getY(0);
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
                bitset<3> bIndex = binaryBit(bestIndexLocal);
                cout<<bestLocal*2/data.getSampleSize()<<" Index: "
                    <<"["<<indexi<<" "<<cuti<<" "<<bIndex[2]
                    <<"] ["<<indexj<<" "<<cutj<<" "<<bIndex[1]
                    <<"] ["<<indexk<<" "<<cutk<<" "<<bIndex[0]
                    <<"]"<<endl;
            }
        }
    }
}





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
    data.creatSamples(300);
    data.preprocessing();
//    data.printInfo(6);

    /// Create patient objects
    PatientData pData(data);
    vector<Patient *> patients = pData.getPatients();
//    pData.printPatients(patients);

    /// Three Depth
    threeDepthPrint(data,patients);








}




/*****************************************************************************************************************************************************/
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

//vector<int> binary(int num){
//    switch(num){
//        case 0: return {-1,-1,-1};
//        case 1: return {-1,-1,1};
//        case 2: return {-1,1,-1};
//        case 3: return {-1,1,1};
//        case 4: return {1,-1,-1};
//        case 5: return {1,-1,1};
//        case 6: return {1,1,-1};
//        case 7: return {1,1,1};
//    }
//    return {0,0,0};
//}

bitset<3> binaryBit(int &num){
    switch(num){
        case 0: return bitset<3> {0};
        case 1: return bitset<3> {1};
        case 2: return bitset<3> {2};
        case 3: return bitset<3> {3};
        case 4: return bitset<3> {4};
        case 5: return bitset<3> {5};
        case 6: return bitset<3> {6};
        case 7: return bitset<3> {7};
    }
    return 0;
}

//vector<int> binary(int num)
//{
//    if(num == 0)
//    {
//        return {-1,-1,-1};
//    }
//    else if(num == 1)
//    {
//        return {-1,-1,1};
//    }
//    else if(num == 2)
//    {
//        return {-1,1,-1};
//    }
//    else if(num == 3)
//    {
//        return {-1,1,1};
//    }
//    else if(num == 4)
//    {
//        return {1,-1,-1};
//    }
//    else if(num == 5)
//    {
//        return {1,-1,1};
//    }
//    else if(num == 6)
//    {
//        return {1,1,-1};
//    }
//    else if(num == 7)
//    {
//        return {1,1,1};
//    }
//    else
//    {
//        cout<<"Incorrect input in binary function.\n";
//        return {0};
//    }
//}
