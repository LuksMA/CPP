// https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

#include <iostream>
#include <stack>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *n){
  while (n != NULL)
  {
     cout<<n->val<<' ';
     n = n->next;
  }
}


void printReverse(ListNode* head){
    if(head == nullptr) return;
    printReverse(head->next);
    cout<<head->val<<" ";
}

int main(){
    ListNode *ls_0 = new ListNode(5);
    ListNode *ls_1 = new ListNode(1);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(4);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(4); ls_2->next = ls_3;
//    ListNode *ls_4 = new ListNode(20); ls_3->next = ls_4;

    cout<<"Created Linked List: "<<endl;
    printList(ls_0);cout<<endl;

    printReverse(ls_0);
}
