// https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/

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


void deleteList(ListNode** head_ref){
    auto cur = *head_ref;
    auto next = cur;

    while(cur){
        next = cur->next;
        delete cur;
        cur = next;
    }
    *head_ref = nullptr;
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

    printList(ls_0);cout<<endl;
    deleteList(&ls_0);
    printList(ls_0);cout<<endl;
}


//10 15 12 13 20 14



