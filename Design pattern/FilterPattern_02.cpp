/// Filter pattern
#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
// https://www.tutorialspoint.com/design_pattern/filter_pattern.htm

using namespace std;



/// Step 1: Create a class on which criteria is to be applied.
class Person{
    string name;
    string gender;
    string maritalStatus;

public:
    Person(string n, string g, string m){
      name = n;
      gender = g;
      maritalStatus = m;
    }
    string getName(){
        return name;
    }
    string getGender(){
        return gender;
    }
    string getMaritalStatus(){
        return maritalStatus;
    }
    bool operator==(const Person& p) const
	{
		return name == p.name && gender == p.gender && maritalStatus == p.maritalStatus;
	}
};

/// Step 2. Create an interface for Criteria.
class ICriteria{
public:
    virtual vector<Person> meetCriteria(vector<Person> persons)=0;
};

/// Step 3. Create concrete classes implementing the Criteria interface.
class CriteriaMale : public ICriteria{
public:
    vector<Person> meetCriteria(vector<Person> persons){
        vector<Person> malePersons;
        for(auto& person : persons){
            if(person.getGender().compare("Male") == 0){
                malePersons.push_back(person);
            }
        }
        return malePersons;
    }
};

class CriteriaFemale : public ICriteria{
public:
    vector<Person> meetCriteria(vector<Person> persons){
        vector<Person> femalePersons ;
        for(auto& person : persons){
            if(person.getGender().compare("Female") == 0){
                femalePersons.push_back(person);
            }
        }
        return femalePersons ;
    }
};

class CriteriaSingle : public ICriteria{
public:
    vector<Person> meetCriteria(vector<Person> persons){
        vector<Person> singlePersons ;
        for(auto& person : persons){
            if(person.getMaritalStatus().compare("Single") == 0){
                singlePersons.push_back(person);
            }
        }
        return singlePersons ;
    }
};

class AndCriteria : public ICriteria{
    ICriteria *criteria;
    ICriteria *otherCriteria;
public:
    AndCriteria(ICriteria &A, ICriteria &B){
        criteria = &A;
        otherCriteria = &B;
    }
    vector<Person> meetCriteria(vector<Person> persons){
        vector<Person> firstCriteriaPersons = criteria -> meetCriteria(persons);
        return otherCriteria -> meetCriteria(firstCriteriaPersons);
    }
};

class OrCriteria : public ICriteria{
    ICriteria *criteria;
    ICriteria *otherCriteria;
public:
    OrCriteria(ICriteria &A, ICriteria &B){
        criteria = &A;
        otherCriteria = &B;
    }
    vector<Person> meetCriteria(vector<Person> persons){
        vector<Person> firstCriteriaItems = criteria -> meetCriteria(persons);
        vector<Person> otherCriteriaItems  = otherCriteria -> meetCriteria(persons);
        for(auto& person : otherCriteriaItems){
                if(find(firstCriteriaItems.begin(), firstCriteriaItems.end(), person) != firstCriteriaItems.end()){
                    firstCriteriaItems.push_back(person);
                }
        }
        return firstCriteriaItems;
    }
};

class AllFilter : public ICriteria{
    vector<ICriteria *> criterias;
public:
//    AllFilter(){
//    }
    void addFilter(ICriteria &A){
        criterias.push_back(&A);
    }
    vector<Person> meetCriteria(vector<Person> persons){
        vector<Person> before = persons;
        vector<Person> after;
        for(int i=0;i<criterias.size();i++){
            vector<Person> after = criterias[i] -> meetCriteria(before);
            before = after;

        }
        return before;
    }
};


void printPersons(vector<Person> persons);




/// Step 4. Use different Criteria and their combination to filter out persons.
int main(){
    vector<Person> persons;
    persons.push_back(Person("Robert","Male", "Single"));
    persons.push_back(Person("John", "Male", "Married"));
    persons.push_back(Person("Laura", "Female", "Married"));
    persons.push_back(Person("Diana", "Female", "Single"));
    persons.push_back(Person("Mike", "Male", "Single"));
    persons.push_back(Person("Bobby", "Male", "Single"));

    ICriteria *iMale;
    CriteriaMale cMale;
    iMale = &cMale;
    vector<Person> male = iMale -> meetCriteria(persons);

    ICriteria *iFemale;
    CriteriaFemale cFemale;
    iFemale = &cFemale;
    vector<Person> female = iFemale -> meetCriteria(persons);

    ICriteria *iSingle;
    CriteriaSingle cSingle;
    iSingle = &cSingle;
    vector<Person> single = iSingle -> meetCriteria(persons);

    ICriteria *iSingleAndMale;
    AndCriteria cSingleAndMale(cSingle,cMale);
    iSingleAndMale = &cSingleAndMale;
    vector<Person> singleAndMale1 = iSingleAndMale -> meetCriteria(persons);

    ICriteria *iSingleOrFemale;
    OrCriteria cSingleOrMale(cSingle,cFemale);
    iSingleOrFemale = &cSingleOrMale;
    vector<Person> singleOrFemale = iSingleOrFemale -> meetCriteria(persons);

    ICriteria *iAllFilter;
    AllFilter cAllFilter;
    cAllFilter.addFilter(cMale);
    cAllFilter.addFilter(cSingle);
    iAllFilter = &cAllFilter;
    vector<Person> singleAndMale2 = iAllFilter -> meetCriteria(persons);

    cout<<"All persons: \n";printPersons(persons);
    cout<<"Males: \n";printPersons(male);
    cout<<"Female: \n";printPersons(female);
    cout<<"Single: \n";printPersons(single);
    cout<<"Single And Male 1: \n";printPersons(singleAndMale1);
    cout<<"Single OR Male: \n";printPersons(singleOrFemale);
    cout<<"Single And Male 2: \n";printPersons(singleAndMale2);
}




void printPersons(vector<Person> persons){
    for(auto& person : persons){
        cout<<"Name: "<<person.getName()
            <<" \tGender: "<<person.getGender()
            <<" \tMarital Status: "<<person.getMaritalStatus()
            <<endl;
    }
    cout<<endl;
}
