#include "ComplementFilter.h"

ComplementFilter :: ComplementFilter(vector<string> id)
{
    patientID = id;
}

vector<Patient> ComplementFilter :: meetCriteria(vector<Patient> patients){
    vector<Patient> vectOut;
    for(auto patient : patients){
        if(std::find(patientID.begin(), patientID.end(), patient.getPatientID()) != patientID.end()){
            vectOut.push_back(patient);
        }
    }
    return vectOut;
}
