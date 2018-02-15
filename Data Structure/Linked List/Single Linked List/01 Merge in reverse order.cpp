//https://www.geeksforgeeks.org/merge-two-sorted-linked-lists-such-that-merged-list-is-in-reverse-order/
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

void push(ListNode** head_ref, int new_data)
{
    ListNode* tmp = new ListNode(new_data);
    tmp->next = nullptr;
    auto cur = *head_ref;
    while(cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = tmp;
}

ListNode* mergeResult (ListNode* node1, ListNode* node2)
{
    ListNode* dummy = new ListNode(0);
    ListNode* tmp;
    while(node1 != nullptr && node2 != nullptr)
    {
        if(node1->val < node2->val)
        {
            tmp = node1->next;
            node1->next = dummy->next;
            dummy->next = node1;
            node1 = tmp;
        }
        else
        {
            tmp = node2->next;
            node2->next = dummy->next;
            dummy->next = node2;
            node2 = tmp;
        }
    }
    if(node2 != nullptr)
    {
        while(node2 != nullptr)
        {
            tmp = node2->next;
            node2->next = dummy->next;
            dummy->next = node2;
            node2 = tmp;
        }
    }
    if(node1 != nullptr)
    {
        while(node1 != nullptr)
        {
            tmp = node1->next;
            node1->next = dummy->next;
            dummy->next = node1;
            node1 = tmp;
        }
    }
    return dummy->next;
}


int main()
{
    ListNode *L1 = new ListNode(5);
    push(&L1,10);
    push(&L1,15);
    push(&L1,40);
//    push(&L1,6);

    ListNode *L2 = new ListNode(2);
    push(&L2,3);
    push(&L2,20);


    cout<<"Created Linked List L1: "<<endl;
    printList(L1);
    cout<<endl;
    cout<<"Created Linked List L2: "<<endl;
    printList(L2);
    cout<<endl;

    printList(mergeResult(L1,L2));
    cout<<endl;
}


//Created Linked List L1:
//5 10 15 40
//Created Linked List L2:
//2 3 20
//40 20 15 10 5 3 2
