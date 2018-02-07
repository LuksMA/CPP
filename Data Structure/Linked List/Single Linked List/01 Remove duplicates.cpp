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
  while (n != nullptr)
  {
     cout<<n->val<<' ';
     n = n->next;
  }
}


void removeDuplicates(ListNode* head){
    ListNode* cur = head;
    ListNode* next = head;

    while(cur != nullptr && cur->next != nullptr){
        next = cur->next;
        if(cur->val == next->val){
            cur->next = cur->next->next;
        }else{
            cur = cur->next;
        }
    }
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

    removeDuplicates(ls_0);
    printList(ls_0);
}

