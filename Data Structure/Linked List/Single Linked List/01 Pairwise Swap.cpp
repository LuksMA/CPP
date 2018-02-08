//https://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/

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


void pairWiseSwap(ListNode *head){
    auto cur = head;
    int tmp;
    while(cur != nullptr && cur->next != nullptr){
        tmp = cur->val;
        cur->val = cur->next->val;
        cur->next->val = tmp;
        cur = cur->next->next;
    }
}

int main(){
    ListNode *ls_0 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(3);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(4); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(5); ls_3->next = ls_4;
    ListNode *ls_5 = new ListNode(6); ls_4->next = ls_5;
//    ListNode *ls_6 = new ListNode(60); ls_5->next = ls_6;

    cout<<"Created Linked List: "<<endl;
    printList(ls_0);cout<<endl;

    pairWiseSwap(ls_0);
    printList(ls_0);
}
