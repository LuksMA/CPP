// https://www.geeksforgeeks.org/write-a-function-that-counts-the-number-of-times-a-given-int-occurs-in-a-linked-list/

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

// global variable for counting frequency of given element k
int frequency = 0;

int count(struct ListNode* head, int search_for){
    if(head == nullptr) return frequency;
    if(head->val == search_for) frequency++;
    count(head->next, search_for);
}



int main(){
    ListNode *ls_0 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(1);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(10); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(20); ls_3->next = ls_4;

    cout<<"Created Linked List: "<<endl;
    printList(ls_0);cout<<endl;

    cout<<count(ls_0,1);cout<<endl;
}

//Created Linked List:
//1 2 1 10 20
//2
