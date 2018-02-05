#include "Collection.h"


Collection::Collection(){

}
void Collection::set_sort(SortBehavior* s){
     m_sort = s;
}
void Collection::set_search(SearchBehavior* s){
    m_search = s;
}
void Collection::sort() const{
     m_sort->sort();
}
void Collection::search() const{
    m_search->search();
}
