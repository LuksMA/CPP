//https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *n)
{
    while (n != nullptr)
    {
        cout<<n->val<<' ';
        n = n->next;
    }
}

ListNode* SortedMerge(ListNode* a, ListNode* b)
{
    ListNode* result = nullptr;

    /* Base cases */
    if (a == nullptr)
        return(b);
    else if (b==nullptr)
        return(a);

    /* Pick either a or b, and recur */
    if (a->val <= b->val)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}



int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l1_1 = new ListNode(2);
    ListNode *l1_2 = new ListNode(4);
    l1->next = l1_1;
    l1_1->next = l1_2;

    ListNode *l2 = new ListNode(1);
    ListNode *l2_1 = new ListNode(3);
    ListNode *l2_2 = new ListNode(4);
    l2->next = l2_1;
    l2_1->next = l2_2;


    printList(SortedMerge(l1,l2));
}
