#include "DataGeneration.h"



DataGeneration :: DataGeneration(vector<short> const &vType, vector<float> const &rY, vector<short> const &rActions, vector<float> const &rCont, vector<short> const &rOrd, vector<short> const &rNom)
{
    sampleSize = 0;

    varType = vType;
    rangesY = rY;
    rangesActions = rActions;
    rangesCont = rCont;
    rangesOrd = rOrd;
    rangesNom = rNom;
    covariateSize = vType.size();
}

DataGeneration  :: ~DataGeneration()    {   }



void DataGeneration :: creatSamples(short sSize)
{
    sampleSize = sSize; // Initial sample size

    id = patientID(sSize);
    vector<vector<short>> seeds = assignSeed(createSeed(getCovariateSize(),100), varType);
    varCont = sampleGenerator(seeds[0],rangesCont);
    varOrd = sampleGenerator(seeds[1],rangesOrd);
    varNom = sampleGenerator(seeds[2],rangesNom);
    varY = sampleGenerator(createSeed(getYSize(),10),rangesY);
    actions = sampleGenerator(createSeed(getActionSize(),50),rangesActions);
}


void DataGeneration :: preprocessing()
{
    varContInt = percentileVec(varCont);
    dataSet = combineData(varContInt, varOrd, varNom);
    sumTreatmentCal();
}

vector<vector<short>> DataGeneration :: combineData(vector<vector<short>> const &varCont, vector<vector<short>> const &varOrd, vector<vector<short>> const &varNom)
{
    vector<vector<short>> dataSet;
    for(short  i=0; i<getContVarSize() ; ++i) dataSet.push_back(varCont.at(i));
    for(short  i=0; i<getOrdVarSize() ; ++i) dataSet.push_back(varOrd.at(i));
    for(short  i=0; i<getNomVarSize() ; ++i) dataSet.push_back(varNom.at(i));
    return dataSet;
}

int DataGeneration :: getSampleSize()
{
    return sampleSize;
}
int DataGeneration :: getCovariateSize()
{
    return covariateSize;
}
int DataGeneration :: getYSize()
{
    return getRangeSize(rangesY);
}
int DataGeneration :: getActionSize()
{
    return getRangeSize(rangesActions);
}
int DataGeneration :: getContVarSize()
{
    return getRangeSize(rangesCont);
}
int DataGeneration :: getOrdVarSize()
{
    return getRangeSize(rangesOrd);
}
int DataGeneration :: getNomVarSize()
{
    return getRangeSize(rangesNom);
}

vector<short> DataGeneration :: getVarType()
{
    return varType;
}
vector<vector<float>> DataGeneration :: getY()
{
    return varY;
}
vector<vector<short>> DataGeneration :: getActions()
{
    return actions;
}
vector<vector<float>> DataGeneration :: getVarCont()
{
    return varCont;
}
vector<vector<short>> DataGeneration :: getVarCont(short i)
{
    return varContInt;
}
vector<vector<short>> DataGeneration :: getVarOrd()
{
    return varOrd;
}
vector<vector<short>> DataGeneration :: getVarNom()
{
    return varNom;
}
vector<vector<short>> DataGeneration :: getDataSet()
{
    return dataSet;
}
vector<short> DataGeneration :: getID()
{
    return id;
}

void DataGeneration :: printContVar()
{
    cout<<'\n'<<getContVarSize()<<" continuous variables, "<<getSampleSize()<<" samples:"<<endl;
    print2DVector(varCont);
}
void DataGeneration :: printContVar5()
{
    cout<<"First 5 continuous variables samples:"<<endl;
    for(short j=0; j<sampleSize;++j){
      for(short i=0;i<5;++i){
            cout<<varCont[i][j]<<'\t';
        }
        cout<<endl;
    }
}


void DataGeneration :: printContVar(short i)
{
    cout<<'\n'<<getContVarSize()<<" percentile continuous variables, "<<getSampleSize()<<" samples:"<<endl;
    print2DVector(varContInt);
}
void DataGeneration :: printOrdVar()
{
    cout<<'\n'<<getOrdVarSize()<<" ordinal variables, "<<getSampleSize()<<" samples:"<<endl;
    print2DVector(varOrd);
}
void DataGeneration :: printNomVar()
{
    cout<<'\n'<<getNomVarSize()<<" nominal variables, "<<getSampleSize()<<" samples:"<<endl;
    print2DVector(varNom);
}
void DataGeneration :: printY()
{
    cout<<'\n'<<getYSize()<<" Y , "<<getSampleSize()<<" samples:"<<endl;
    print2DVector(varY);
}
void DataGeneration :: printAction()
{
    cout<<'\n'<<getActionSize()<<" actions , "<<getSampleSize()<<" samples:"<<endl;
    print2DVector(actions);
}
void DataGeneration :: printDataSet()
{
    cout<<'\n'<<getCovariateSize()<<" covariates , "<<getSampleSize()<<" samples:"<<endl;
    print2DVector(dataSet);
}

void DataGeneration :: printInfo(short i)
{
    switch(i)
    {
    case 0:
        printContVar();
        break;
    case 1:
        printOrdVar();
        break;
    case 2:
        printNomVar();
        break;
    case 3:
        printAction();
        break;
    case 4:
        printY();
        break;
    case 5:
        printContVar(5);
        break;
    case 6:
        printDataSet();
        break;
    default:
        cout<<"You typed something wrong!";
    }
}

void DataGeneration :: genReport()
{
    cout<<"Generate "<<getSampleSize()<<" samples\n"
        <<"Covariate size: "<<getCovariateSize()
        <<"\tY size: "<<getYSize()
        <<"\tAction size: "<<getActionSize()<<'\n'
        <<"Continuous: "<<getContVarSize()
        <<"\tOrdinal: "<<getOrdVarSize()
        <<"\tNormal: "<<getNomVarSize()<<endl;
}


vector<short> DataGeneration :: patientID(short noSample)
{
    vector<short> vectOut;
    if(noSample>0)
    {
        for(short i=0; i<noSample; ++i)
        {
            vectOut.push_back(i);
        }
    }
    else
    {
        cout<<"No. of sample much be >0"<<endl;
        return vectOut;
    }
    return vectOut;
}

template<class T>
int DataGeneration :: getRangeSize(vector<T> const &vectIn)
{
    int vectSize = vectIn.size();
    if(vectSize%2 == 0)
    {
        for(int i=0 ; i < vectSize; ++i)
        {
            T lowBound = vectIn.at(2*i);
            T upperBound = vectIn.at(2*i+1);
            if(lowBound < upperBound)
            {
                return vectSize/2;
            }
            else
            {
                cout<<"Error: Please check if lower bounds are smaller than upper bounds. \n";
            }
        }
    }
    else
    {
        cout<<"Error: Please check for complete ranges input. \n";
    }
    return 0;
}

vector<short> DataGeneration :: createSeed(short varsize, short start)
{
    vector<short> seed;
    for(short i=0 ; i<varsize; ++i)
    {
        seed.push_back(start+5*i);
    }
    return seed;
}




vector<vector<short>> DataGeneration :: assignSeed(vector<short> const &seed, vector<short> const &varType)
{
    vector<vector<short>> vectOut;
    vector<short> seedCont;
    vector<short> SeedOrd;
    vector<short> seedNom;
    for(int i=0; i< covariateSize; ++i)
    {
        short type = varType[i];
        if(type == 0)
        {
            seedCont.push_back(seed[i]);
        }
        else if(type == 1)
        {
            SeedOrd.push_back(seed[i]);
        }
        else if(type == 2)
        {
            seedNom.push_back(seed[i]);
        }
        else
        {
            cout<<"Error about variable type input."<<endl;
        }
    }
    vectOut.push_back(seedCont);
    vectOut.push_back(SeedOrd);
    vectOut.push_back(seedNom);
    return vectOut;
}

vector<float> DataGeneration :: dataGenerator(short seed, float lowerBound, float upperBound){
    default_random_engine rvEngine{seed};
    mt19937 gen(rvEngine());
    uniform_real_distribution<> dis(lowerBound, upperBound);
    vector<float> vectOut;
    for(short i=0;i<sampleSize;++i){
        vectOut.push_back(dis(gen));
    }
    return vectOut;
}

vector<short> DataGeneration :: dataGenerator(short seed, short lowerBound, short upperBound){
    default_random_engine rvEngine{seed};
    mt19937 gen(rvEngine());
    uniform_int_distribution<> dis(lowerBound, upperBound);
    vector<short> vectOut;
    for(short i=0;i<sampleSize;++i){
        vectOut.push_back(dis(gen));
    }
    return vectOut;
}




vector<vector<float>> DataGeneration :: sampleGenerator(vector<short> const &seed, vector<float> const &ranges)
{
    vector<vector<float>> vectOut;
    for(int  i=0 ; i < getRangeSize(ranges); ++i)
    {
        float lowBound = ranges.at(2*i);
        float upperBound = ranges.at(2*i+1);
        vector<float>   vectTemp = dataGenerator(seed[i],lowBound,upperBound);
        vectOut.push_back(vectTemp);
    }
    return vectOut;
}


vector<vector<short>> DataGeneration :: sampleGenerator(vector<short> const &seed, vector<short> const &ranges){
    vector<vector<short>> vectOut;
    for(int  i=0 ; i < getRangeSize(ranges); ++i)
    {
        short lowBound = ranges.at(2*i);
        short upperBound = ranges.at(2*i+1);
        vector<short>   vectTemp = dataGenerator(seed[i],lowBound,upperBound);
        vectOut.push_back(vectTemp);
    }
    return vectOut;
}



vector<short> DataGeneration :: percentileVec(vector<float> const &vectIn)
{
    vector<short> vectOut;
    map<float, short> mapTemp = percentileMap(vectIn);
    for(const auto &row : vectIn)
    {
        vectOut.push_back(mapTemp[row]);
    }
    return vectOut;
}

vector<vector<short>> DataGeneration :: percentileVec(vector<vector<float>> const &vectIn)
{
    vector<vector<short>> vectOut;
    for(auto x : vectIn)
    {
        vectOut.push_back(percentileVec(x));
    }
    return vectOut;
}

map<float, short> DataGeneration :: percentileMap(vector<float> const &vectorIn)
{
    map<float, short> mapOut;
    vector<float> vectorSort = vectorIn;
    sort(vectorSort.begin(),vectorSort.end());
    short len = vectorSort.size();
    for(short i=0; i<len ; ++i)
        mapOut.insert(make_pair(vectorSort[i],assignPercentile(percentile(len,i+1))));
    return mapOut;
}

float DataGeneration :: percentile(float len,float index)
{
    if(index>=0)
    {
        return 100*(index-0.5)/len;
    }
    else
    {
        cout<<"Out of scope"<<endl;
        return 0.0;
    }

}

short DataGeneration :: assignPercentile(float p)
{
    if (p < 0)
    {
        cout<<"Out of scope"<<endl;
        return -1;
    }
    else if (p < 10)
    {
        return 0;
    }
    else if (p < 20)
    {
        return 1;
    }
    else if (p < 30)
    {
        return 2;
    }
    else if (p < 40)
    {
        return 3;
    }
    else if (p < 50)
    {
        return 4;
    }
    else if (p < 60)
    {
        return 5;
    }
    else if (p < 70)
    {
        return 6;
    }
    else if (p < 80)
    {
        return 7;
    }
    else if (p < 90)
    {
        return 8;
    }
    else
    {
        return 9;
    }
}



void DataGeneration :: sumTreatmentCal()
{
    float sum0 = 0.0;
    for(short i=0; i<sampleSize; ++i)
    {
        if(actions[0][i] != 1)
        {
            sum0 += varY[0][i];
        }
    }
    sumTreatment0 = sum0;
}


float DataGeneration :: getSumT0()
{
    return sumTreatment0;
}




template<class T>
void DataGeneration :: print1DVector(vector<T> const &vectIn)
{
    cout<<"[ ";
    for(const auto &row : vectIn)
    {
        cout<<row<<' ';
    }
    cout<<']';
}

template<class T>
void DataGeneration :: print2DVector(vector<vector<T>> const &vectIn)
{
    try
    {
        for(unsigned int j=0; j<vectIn.at(0).size(); ++j)
        {
            for(unsigned int i=0; i<vectIn.size(); ++i)
            {
                cout<<vectIn[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    catch (const std::out_of_range& oor)
    {
        cerr << "Out of Range error in print2DVector. Please check empty input: " << oor.what() << '\n';
    }
}
