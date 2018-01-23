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

void insert_middle(int x, ListNode* prev_node){
    ListNode *temp = new ListNode(x);
    temp->next = prev_node->next;
    prev_node->next = temp;
}

int main(){
    ListNode *ls_0 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2); ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(3); ls_1->next = ls_2;
    printList(ls_0);cout<<endl;

    insert_middle(10,ls_1);
    printList(ls_0);cout<<endl;

    insert_middle(20,ls_1);
    printList(ls_0);cout<<endl;
}


//1 2 3
//1 2 10 3
//1 2 20 10 3
