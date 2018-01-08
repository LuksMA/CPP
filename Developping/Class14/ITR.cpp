#include "ITR.h"

ITR::ITR(DataGeneration &data)
{
    sample_Size = data.getSampleSize();
    var_Size = data.getCovariateSize();
    action_Size = data.getActionSize();
    y_Size = data.getYSize();

    var_X = new int*[sample_Size];
    var_A = new int*[sample_Size];
    var_Y = new double*[sample_Size];

    for(int i=0; i<sample_Size; ++i){
        var_X[i] = new int[var_Size];
        var_A[i] = new int[action_Size];
        var_Y[i] = new double[y_Size];
    }

    loadX(data.getDataSet());
    loadAction(data.getActions());
    loadY(data.getY());

}

ITR::~ITR()
{
    //dtor
}

int ITR::getSampleSize(){
    return sample_Size;
}
int ITR::getVarSize(){
    return var_Size;
}
int ITR::getActionSize(){
    return action_Size;
}
int ITR::getYSize(){
    return y_Size;
}


void ITR :: print_X(){
    for(int i=0; i<sample_Size; ++i){
        for(int j=0; j<var_Size; ++j){
            cout<<var_X[i][j]<<' ';
        }
        cout<<endl;
    }
}

void ITR :: print_Action(){
    for(int i=0; i<sample_Size; ++i){
        for(int j=0; j<action_Size; ++j){
            cout<<var_A[i][j]<<' ';
        }
        cout<<endl;
    }
}

void ITR :: print_Y(){
    for(int i=0; i<sample_Size; ++i){
        for(int j=0; j<y_Size; ++j){
            cout<<var_Y[i][j]<<' ';
        }
        cout<<endl;
    }
}

void ITR :: print_All(){
    for(int i=0; i<sample_Size; ++i){
        cout<<"X: ";
        for(int x=0; x<var_Size; ++x){
            cout<<var_X[i][x]<<' ';
        }
        cout<<" Action: ";
        for(int y=0; y<action_Size; ++y){
            cout<<var_A[i][y]<<' ';
        }
        cout<<" Y: ";
        for(int z=0; z<y_Size; ++z){
            cout<<var_Y[i][z]<<' ';
        }
        cout<<endl;
    }
}



void ITR :: loadX(vector<vector<int>> x){
    for(int i=0; i<sample_Size; ++i){
        for(int j=0; j<var_Size; ++j){
            var_X[i][j] = x[j][i];
        }
    }
}

void ITR :: loadAction(vector<vector<int>> a){
    for(int i=0; i<sample_Size; ++i){
        for(int j=0; j<action_Size; ++j){
            var_A[i][j] = a[j][i];
        }
    }
}

void ITR :: loadY(vector<vector<double>> y){
    for(int i=0; i<sample_Size; ++i){
        for(int j=0; j<y_Size; ++j){
            var_Y[i][j] = y[j][i];
        }
    }
}




void ITR :: clean_X(){
    for(int i=0; i<sample_Size; ++i){
        delete [] var_X[i];
    }
    delete var_X;
}
void ITR :: clean_Action(){
    for(int i=0; i<sample_Size; ++i){
        delete [] var_A[i];
    }
    delete var_A;
}
void ITR :: clean_Y(){
    for(int i=0; i<sample_Size; ++i){
        delete [] var_Y[i];
    }
    delete var_Y;
}


void ITR :: cleanAll(){
    for(int i=0; i<sample_Size; ++i){
        delete [] var_X[i];
        delete [] var_A[i];
        delete [] var_Y[i];
    }
    delete var_X;
    delete var_A;
    delete var_Y;
}
