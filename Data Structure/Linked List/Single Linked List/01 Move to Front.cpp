// https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *n){
  while (n != nullptr)
  {
     cout<<n->val<<' ';
     n = n->next;
  }
}


void moveToFront(ListNode **head){
    ListNode* dummy = new ListNode(0);
    dummy->next = *head;
    auto prev = dummy;
    auto cur = prev->next;
    while(cur->next != nullptr){
        prev = cur;
        cur = cur->next;
    }
    cur->next = dummy->next;
    dummy->next = cur;
    prev->next = nullptr;
    *head = dummy->next;
}

int main(){
    ListNode *ls_0 = new ListNode(11);
    ListNode *ls_1 = new ListNode(11);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(11);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(21); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(43); ls_3->next = ls_4;
    ListNode *ls_5 = new ListNode(43); ls_4->next = ls_5;
    ListNode *ls_6 = new ListNode(60); ls_5->next = ls_6;

    cout<<"Created Linked List: "<<endl;
    printList(ls_0);cout<<endl;

    moveToFront(&ls_0);
    printList(ls_0);
}

//Created Linked List:
//11 11 11 21 43 43 60
//60 11 11 11 21 43 43

