//https://www.geeksforgeeks.org/merge-a-linked-list-into-another-linked-list-at-alternate-positions/
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
    while(cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = tmp;
}

void mergeList(ListNode** p, ListNode** q){
    if(*p == nullptr || *q == nullptr) return;
    auto cur1 = *p;
    auto tmp1 = cur1;
    auto cur2 = *q;
    auto tmp2 = cur2;
    while(cur1 != nullptr && cur2 != nullptr){
        tmp1 = cur1->next;
        tmp2 = cur2->next;
        cur1->next = cur2;
        cur2->next = tmp1;
        cur1 = tmp1;
        cur2 = tmp2;
    }
    *q = cur2;
}


int main()
{
    ListNode *L1 = new ListNode(4);
    push(&L1,5);
    push(&L1,6);
    push(&L1,7);
    push(&L1,8);

    ListNode *L2 = new ListNode(1);
    push(&L2,2);
    push(&L2,3);


    cout<<"Created Linked List L1: "<<endl;
    printList(L1); cout<<endl;
    cout<<"Created Linked List L2: "<<endl;
    printList(L2); cout<<endl;

    mergeList(&L2,&L1);
    printList(L2); cout<<endl;
    printList(L1); cout<<endl;
}


