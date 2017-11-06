#include <iostream>
#include <map>
#include <iterator>
#include <string>

using namespace std;

int main(){
    map <string, int> mapOfWords;

    /// Inserting data in std::map
    mapOfWords.insert(make_pair("earth", 1));
    mapOfWords.insert(make_pair("moon", 2));
    mapOfWords["sun"] = 3;


    /// Will replace the value of already added key i.e. earth
    mapOfWords["earth"] = 4;

    /// Iterate through all elements in std::map
    map <string, int>::iterator it = mapOfWords.begin();
    while(it != mapOfWords.end()){
        cout<<it->first<<" :: "<<it->second<<endl;
        it++;
    }


    /// Search by key
//    iterator find (const key_type& k);
//
////e.g.
//
//if(mapOfWords.find("sun") != mapOfWords.end())
//std::cout<<"word 'sun' found"<<std::endl;
//if(mapOfWords.find("mars") == mapOfWords.end())
//std::cout<<"word 'mars' not found"<<std::endl;

    /// Search by value

/// http://thispointer.com/stdmap-tutorial-part-1-usage-detail-with-examples/

/// Deleting data from std::map
}
