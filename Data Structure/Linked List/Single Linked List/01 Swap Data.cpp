// https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(struct ListNode *n){
  while (n != nullptr)
  {
     cout<<n->val<<' ';
     n = n->next;
  }
}


void swapNodes(struct ListNode **head_ref, int x, int y)
{
   // Nothing to do if x and y are same
   if (x == y) return;

   // Search for x (keep track of prevX and CurrX
   ListNode *prevX = nullptr, *currX = *head_ref;
   while (currX && currX->val != x)
   {
       prevX = currX;
       currX = currX->next;
   }

   // Search for y (keep track of prevY and CurrY
   ListNode *prevY = nullptr, *currY = *head_ref;
   while (currY && currY->val != y)
   {
       prevY = currY;
       currY = currY->next;
   }


   // If either x or y is not present, nothing to do
   if (currX == nullptr || currY == nullptr)
       return;

   // If x is not head of linked list
   if (prevX != nullptr)
       prevX->next = currY;
   else // Else make y as new head
       *head_ref = currY;

   // If y is not head of linked list
   if (prevY != nullptr)
       prevY->next = currX;
   else  // Else make x as new head
       *head_ref = currX;

   // Swap next pointers
   ListNode *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}


int main(){
    ListNode *ls_0 = new ListNode(10);
    ListNode *ls_1 = new ListNode(15);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(12);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(13);  ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(20);  ls_3->next = ls_4;
    ListNode *ls_5 = new ListNode(14);  ls_4->next = ls_5;

    printList(ls_0);cout<<endl;

    cout<<"Swap 12 and 20:"<<endl;
    swapNodes(&ls_0,12,20);
    printList(ls_0);cout<<endl;

    cout<<"Swap 10 and 20:"<<endl;
    swapNodes(&ls_0,10,20);
    printList(ls_0);cout<<endl;

    cout<<"Swap 12 and 13:"<<endl;
    swapNodes(&ls_0,12,13);
    printList(ls_0);cout<<endl;
}
