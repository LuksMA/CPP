//https://github.com/vectormars/CPP/blob/master/Data%20Structure/Linked%20List/Single%20Linked%20List/01%20Delete%20Given%20Position.cpp
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(struct ListNode *n){
  while (n != NULL)
  {
     cout<<n->val<<' ';
     n = n->next;
  }
}


void delete_key(ListNode** head, int p){
    ListNode* dummy = new ListNode(0);
    dummy->next = *head;
    auto prev = dummy;
    auto cur = prev->next;
    while(cur != nullptr){
        if(p == 0){
            prev->next = cur->next;
            delete cur;
            break;
        }else{
            prev = cur;
        }
        cur = prev->next;
        --p;
    }
    *head = dummy->next;
}



int main(){
    ListNode *ls_0 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(3);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(10); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(20); ls_3->next = ls_4;

    cout<<"Created Linked List: "<<endl;
    printList(ls_0);cout<<endl;

    cout<<"After Deletion position of 1: "<<endl;
    delete_key(&ls_0,1);
    printList(ls_0);cout<<endl;

    cout<<"After Deletion position of 0: "<<endl;
    delete_key(&ls_0,0);
    printList(ls_0);cout<<endl;

    cout<<"After Deletion position of 3: "<<endl;
    delete_key(&ls_0,2);
    printList(ls_0);cout<<endl;

    cout<<"After Deletion position of 3: "<<endl;
    delete_key(&ls_0,3);
    printList(ls_0);cout<<endl;
}



//Created Linked List:
//1 2 3 10 20
//After Deletion position of 1:
//1 3 10 20
//After Deletion position of 0:
//3 10 20
//After Deletion position of 3:
//3 10
//After Deletion position of 3:
//3 10
