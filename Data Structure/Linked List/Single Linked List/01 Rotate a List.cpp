//https://www.geeksforgeeks.org/rotate-a-linked-list/
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

void rotate(ListNode **head_ref, int k){
    auto hold = *head_ref;
    auto cur = *head_ref;
    auto prev = *head_ref;
    ListNode* dummy = new ListNode(0);
    while(cur != nullptr && k != 0){
        prev = cur;
        cur = prev->next;
        --k;
    }
    if(cur == nullptr) return;
    prev->next = nullptr;
    dummy->next = cur;
    while(cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = hold;
    *head_ref = dummy->next;
}


int main()
{
    ListNode *L = new ListNode(10);
    push(&L,20);
    push(&L,30);
    push(&L,40);
    push(&L,50);
    push(&L,60);

    cout<<"Created Linked List: "<<endl;
    printList(L); cout<<endl;

    rotate(&L,4);
    printList(L); cout<<endl;
}


//Created Linked List:
//10 20 30 40 50 60
//50 60 10 20 30 40
