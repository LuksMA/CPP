//https://www.geeksforgeeks.org/compare-two-strings-represented-as-linked-lists/

#include <iostream>

using namespace std;

struct ListNode
{
    char c;
    ListNode *next;
    ListNode(char x) : c(x), next(nullptr) {}
};

void printList(ListNode *n)
{
    while (n != nullptr)
    {
        cout<<n->c<<' ';
        n = n->next;
    }
}

void push(ListNode** head_ref, char new_data)
{
    ListNode* tmp = new ListNode(new_data);
    tmp->next = nullptr;
    auto cur = *head_ref;
    while(cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = tmp;
}

int compare(ListNode *list1, ListNode *list2){
    while(list1 != nullptr && list2 != nullptr){
        if(list1->c == list2->c){
             list1 = list1->next;
             list2 = list2->next;
         }else{
             break;
         }
     }
     if(list1 == nullptr && list2 == nullptr) return 0;
     if(list2 == nullptr || list1->c > list2->c) return 1;
     if(list1 == nullptr || list2->c > list1->c) return -1;
}



int main()
{
    ListNode *L1 = new ListNode('g');
    push(&L1,'e');
    push(&L1,'e');
    push(&L1,'k');
    push(&L1,'s');
//    push(&L1,'a');

    ListNode *L2 = new ListNode('g');
    push(&L2,'e');
    push(&L2,'e');
    push(&L2,'k');
    push(&L2,'s');
//    push(&L2,'b');

    cout<<"Created Linked List L1: "<<endl;
    printList(L1);
    cout<<endl;
    cout<<"Created Linked List L2: "<<endl;
    printList(L2);
    cout<<endl;

    cout<<compare(L1,L2);
    cout<<endl;
}
