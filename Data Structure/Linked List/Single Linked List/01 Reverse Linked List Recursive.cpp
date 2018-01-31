//https://www.geeksforgeeks.org/reverse-a-linked-list/

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


static void recursiveReverse(struct ListNode** head_ref){
    ListNode* first;
    ListNode* rest;
    if(*head_ref == nullptr){
        return;
    }
    first = *head_ref;
    rest = first->next;
    if(rest == nullptr){
        return;
    }
    recursiveReverse(&rest);
    first->next->next  = first;

    /* tricky step -- see the diagram */
    first->next  = NULL;

    /* fix the head pointer */
    *head_ref = rest;
}


int main(){
    ListNode *ls_0 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(1);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(10); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(20); ls_3->next = ls_4;

    cout<<"Created Linked List: "<<endl;
    printList(ls_0);cout<<endl;

    cout<<"Reversed Linked List: "<<endl;
    recursiveReverse(&ls_0);
    printList(ls_0);cout<<endl;
}

