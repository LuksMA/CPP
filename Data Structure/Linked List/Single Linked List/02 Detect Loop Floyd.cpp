//https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
/// Method 1. Floyd’s Cycle-Finding Algorithm
/// This is the fastest method. Traverse linked list using two pointers.  Move one pointer by one and other pointer by two.
/// If these pointers meet at some node then there is a loop.  If pointers do not meet then linked list doesn’t have loop.

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

bool detectLoop(ListNode *head){
    auto fast = head;
    auto slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}



int main(){
    ListNode *ls_0 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(1);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(10); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(20); ls_3->next = ls_4;

    cout<<"Created Linked List: "<<endl;
    printList(ls_0);cout<<endl;

    cout<<detectLoop(ls_0);
}
