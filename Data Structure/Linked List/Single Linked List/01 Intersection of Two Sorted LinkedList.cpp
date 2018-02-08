//https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/

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

ListNode* sortedIntersect(ListNode* a, ListNode* b){
    if(a == nullptr) return nullptr;
    if(b == nullptr) return nullptr;
    ListNode* dummy = new ListNode(0);
    auto cur = dummy;
    while(a != nullptr && b != nullptr){
        if(a->val == b->val){
            cur->next = new ListNode(a->val);
            cur = cur->next;
            a = a->next;
            b = b->next;
        }else if(a->val < b->val){
            a = a->next;
        }else{
            b = b->next;
        }
    }


    return dummy->next;
}


int main(){
    ListNode *L1 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  L1->next = ls_1;
    ListNode *ls_2 = new ListNode(3);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(4); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(6); ls_3->next = ls_4;
    ListNode *ls_5 = new ListNode(10); ls_4->next = ls_5;

    ListNode *L2 = new ListNode(2);
    ListNode *ls_6 = new ListNode(4);  L2->next = ls_6;
    ListNode *ls_7 = new ListNode(6);  ls_6->next = ls_7;
    ListNode *ls_8 = new ListNode(8); ls_7->next = ls_8;

    cout<<"Created Linked List L1: "<<endl;
    printList(L1);cout<<endl;
    cout<<"Created Linked List L2: "<<endl;
    printList(L2);cout<<endl;

    printList(sortedIntersect(L1,L2));
}


