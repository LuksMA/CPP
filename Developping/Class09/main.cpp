#include <iostream>

#include "DataGeneration.h"
#include "Patient.h"
#include "PatientData.h"
#include "VariableInfo.h"


using namespace std;


vector<VariableInfo *> creatVariableInfo(vector<vector<int>> dataSet,vector<int> varType);
template<class T> void print1DVector(vector<T> const &vectIn);
vector<int> binary(int num);
bool criteria(Patient * p, VariableInfo * v, int cutNo)
{
    if(v->getVarType() == 2)
    {
        return false;
    }
    else
    {
        if(p->getX(v->getVarNo()) < cutNo)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


}


void threeDepthPrint(DataGeneration &data, vector<VariableInfo *> varInfo, vector<Patient *> patients)
{
    double T0 = data.getSumT0();
    for(int i=0; i<5; ++i)   // loop1
    {
        VariableInfo  *variInfoI = varInfo[i];

//        for(int j=i+1; j<varInfo.size(); ++j){   // loop2
        for(int j=i+1; j<5; ++j)    // loop2
        {
            VariableInfo  *variInfoJ = varInfo[j];

//            for(int k=j+1; k<varInfo.size(); ++k){   // loop3
            for(int k=j+1; k<5; ++k)    // loop3
            {
                VariableInfo  *variInfoK = varInfo[k];
                double bestLocal = 0.0;
                int bestIndexLocal = 0;
                int indexi = 0, indexj = 0, indexk = 0;
                int cuti = 0, cutj = 0, cutk = 0;
                for(auto xi : variInfoI->getCuts())            // loop4
                {
                    for(auto xj : variInfoJ->getCuts())    // loop5
                    {
                        for(auto xk : variInfoK->getCuts())    // loop6
                        {
                            double v0000 = 0.0, v0001 = 0.0, v0010 = 0.0, v0011 = 0.0;
                            double v0100 = 0.0, v0101 = 0.0, v0110 = 0.0, v0111 = 0.0;
                            double v1000 = 0.0, v1001 = 0.0, v1010 = 0.0, v1011 = 0.0;
                            double v1100 = 0.0, v1101 = 0.0, v1110 = 0.0, v1111 = 0.0;

                            for(auto p : patients)
                            {
//                                if(p->getX(i) < xi)
                                if(criteria(p,varInfo[i],xi))
                                {
                                    if(criteria(p,varInfo[j],xj))
                                    {
                                        if(criteria(p,varInfo[k],xk))
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
                                        if(criteria(p,varInfo[k],xk))
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
                                    if(criteria(p,varInfo[j],xj))
                                    {
                                        if(criteria(p,varInfo[k],xk))
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
                                        if(criteria(p,varInfo[k],xk))
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


                            double sum1 = v0000 + (T0 - v0001);
                            double sum2 = v0010 + (T0 - v0011);
                            double sum3 = v0100 + (T0 - v0101);
                            double sum4 = v0110 + (T0 - v0111);

                            double sum5 = v1000 + (T0 - v1001);
                            double sum6 = v1010 + (T0 - v1011);
                            double sum7 = v1100 + (T0 - v1101);
                            double sum8 = v1110 + (T0 - v1111);

                            double sum[] = {sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8};

                            const auto ptr = max_element(sum,sum+8);
                            double temp = *ptr;
                            int index = distance(sum, ptr);
                            if(temp > bestLocal)
                            {
                                bestLocal = temp;
                                bestIndexLocal = index;
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

template<class T>
void printNominalCuts(map<int,vector<T>> &mapIn){
    for( const auto& x : mapIn ){
        cout<<'<'<<x.first<<"> :: ";
        vector<int> Second = x.second;
        print1DVector(Second);cout<<'\n';
    }
}




template<class T>
map<int,vector<T>> mapCuts(vector<T> &setIn){
    map <int,vector<T>> mapOfCategorical;

	int max = 1 << setIn.size();
	for(int i = 0; i < max; i++) {
        int First;
		vector<T> Second;

		int j = i;
		int index = 0;
		while (j > 0) {
			if((j & 1) > 0)
				Second.push_back(setIn[index]);
                j >>= 1;
                index++;
		}
		if(Second.size()<=setIn.size()/2){
		    First = i;
            mapOfCategorical.insert(make_pair(First,Second));
		}
	}
	return mapOfCategorical;
}


vector<int> nominalCuts(map<int,vector<T>> &mapIn){

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
//    print1DVector(varInfo[0]->getCuts());

    /// Three Depth
//    threeDepthPrint(data,varInfo,patients);
    vector<int> xv = {0,1,2,3,4};
    map <int,vector<int>> xm = mapCuts(xv);
    printNominalCuts(xm);




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
