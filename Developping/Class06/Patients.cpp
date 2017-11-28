vector<Patient *> createPatients(vector<vector<int>> dataSet,vector<vector<int>> actions, vector<vector<double>> Y,vector<int> varType, vector<int> patientID){
    vector<Patient *> patients;
    for(unsigned int j=0;j<dataSet.at(0).size();++j){
        vector<int> valueX;
        vector<double> valueY;
        vector<int> action;
        for(unsigned int i=0;i<dataSet.size();++i){
            valueX.push_back(dataSet[i][j]);
        }
        for(unsigned int p=0;p<Y.size();++p){
            valueY.push_back(Y[p][j]);
        }
        for(unsigned int q=0;q<actions.size();++q){
            action.push_back(actions[q][j]);
        }
        patients.push_back(new Patient(patientID.at(j), action , valueX ,valueY , varType));
    }
    return patients;
}

/// Get Individual Patient Info
int getPatientX( Patient * p, int i){
    return p->getX(i);
}
vector<int> getPatientAction( Patient * p ){
    return p->getAction();
}

vector<double> getPatientY( Patient * p ){
    return p->getY();
}






/// Print Individual Patient
void printPatientID( Patient * p ) {
    cout<<p->getID();
}
void printPatientX( Patient * p ) {
    print1DVector(p->getX());
}

void printPatientAction( Patient * p ){
    print1DVector(p->getAction());
}

void printPatientY( Patient * p ){
    print1DVector(p->getY());
}

/// Print Patients
void printPatientsX(vector<Patient *> patients){
    for(auto p : patients){
        cout<<"Patient ID: ";
        printPatientID(p);
        cout<<" \tValue of X: ";
        printPatientX(p);
        cout<<endl;
    }
    cout<<endl;
}

void printPatientsXA(vector<Patient *> patients){
    for(auto p : patients){
        cout<<"Patient ID: ";
        printPatientID(p);
        cout<<" \tValue of X: ";
        printPatientX(p);
        cout<<"\tAction: ";
        printPatientAction(p);
        cout<<endl;
    }
    cout<<endl;
}


void printPatients(vector<Patient *> patients){
    for(auto p : patients){
        cout<<"Patient ID: ";
        printPatientID(p);
        cout<<" \tValue of X: ";
        printPatientX(p);
        cout<<"\tAction: ";
        printPatientAction(p);
        cout<<"\tY: ";
        printPatientY(p);
        cout<<endl;
    }
    cout<<endl;
}


//vector<Patient> combinePatients(vector<Patient> p1, vector<Patient> p2){
//    p1.insert( p1.end(), p2.begin(), p2.end() );
//    return p1;
//}


//double expect(vector<Patient> patients, int s){
//    double out = 0;
//    for(auto patient : patients){
//        out = out + patient.getY(0);
//    }
//    return out*2/s;
//}
