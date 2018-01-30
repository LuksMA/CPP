// https://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(struct ListNode *n)
{
    while (n != nullptr)
    {
        cout<<n->val<<' ';
        n = n->next;
    }
}


int GetNth(ListNode* head, int index)
{
    int count = 1;
    if( count == index)
        return head->val;

    return GetNth(head->next,count-1);
}


int main()
{
    ListNode *ls_0 = new ListNode(10);
    ListNode *ls_1 = new ListNode(15);
    ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(12);
    ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(13);
    ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(20);
    ls_3->next = ls_4;
    ListNode *ls_5 = new ListNode(14);
    ls_4->next = ls_5;

    printList(ls_0);
    cout<<endl;

    cout<<GetNth(ls_0,2)<<endl;
//    cout<<GetNth(ls_0,10)<<endl;
}
