#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* head = NULL, *pre = NULL;

        if ((l1 == NULL) && (l2 != NULL))
            return l2;
        else if ((l1 != NULL) && (l2 == NULL))
            return l1;
        else if ((l1 == NULL) && (l2 == NULL))
            return NULL;

        if (l1 -> val > l2 -> val)
        {
            head = l2;
            pre = l2;
            l2 = l2 -> next;
        }
        else{
            head = l1;
            pre = l1;
            l1 = l1 -> next;
        }

        while (l1 != NULL && l2 != NULL)
        {
            if (l1 -> val > l2 -> val)
            {
                pre ->next = l2;
                pre = l2;
                l2 = l2 -> next;

            }
            else{
                pre -> next = l1;
                pre = l1;
                l1 = l1 -> next;
            }
        }

        if (l1 == NULL)
        {
            pre -> next = l2;
            pre = l2;
        }
        else if (l2 == NULL)
        {
            pre -> next = l1;
            pre = l1;
        }
        return head;

    }
};
