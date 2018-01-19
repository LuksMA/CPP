#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(struct ListNode *n){
  while (n != NULL){
     cout<<n->val<<' ';
     n = n->next;
  }
  cout<<endl;
}


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        ListNode *begin = nullptr, *tailA = nullptr, *tailB = nullptr;
        while (curA && curB) {
            if (curA == curB) {
                begin = curA;
                break;
            }

            if (curA->next) {
                curA = curA->next;
            } else if (!tailA) {
                tailA = curA;
                curA = headB;
            } else {
                break;
            }

            if (curB->next) {
                curB = curB->next;
            } else if (!tailB) {
                tailB = curB;
                curB = headA;
            } else {
                break;
            }
        }

        return begin;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l1_1 = new ListNode(2);
    ListNode *l1_2 = new ListNode(3);
    ListNode *l1_3 = new ListNode(4);
    ListNode *l1_4 = new ListNode(5);


    l1->next = l1_1;
    l1_1->next = l1_2;
    l1_2->next = l1_3;
    l1_3->next = l1_4;


    ListNode *l2 = new ListNode(6);
    ListNode *l2_1 = new ListNode(7);
    ListNode *l2_2 = new ListNode(8);
    ListNode *l2_3 = new ListNode(3);
    ListNode *l2_4 = new ListNode(4);
    ListNode *l2_5 = new ListNode(5);



    l2->next = l2_1;
    l2_1->next = l2_2;
    l2_2->next = l2_3;
    l2_3->next = l2_4;
    l2_4->next = l2_5;

//    printList(l1);
//    printList(l2);
    Solution s;
    printList(s.getIntersectionNode(l1,l2));
}

