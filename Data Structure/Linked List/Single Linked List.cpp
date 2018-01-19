#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(struct ListNode *n)
{
  while (n != NULL)
  {
     cout<<n->val<<' ';
     n = n->next;
  }
}

int main(){
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);

    head->next = second;
    second->next = third;

    printList(head);

}
