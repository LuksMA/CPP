//https://www.geeksforgeeks.org/sort-a-linked-list-of-0s-1s-or-2s/

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

void sortList(ListNode *head){
    int count[3] = {0, 0, 0};
    auto cur = head;
    while(cur != nullptr){
        count[cur->val] += 1;
        cur = cur->next;
    }
    int i = 0;
    cur = head;
    while(cur != nullptr){
        if(count[i] == 0){
            ++i;
        }else{
            cur->val = i;
            --count[i];
            cur = cur->next;
        }
    }
}


int main()
{
    ListNode *L = new ListNode(2);
    push(&L,1);
    push(&L,2);
    push(&L,1);
    push(&L,1);
    push(&L,2);
    push(&L,0);
    push(&L,1);
    push(&L,0);

    cout<<"Created Linked List: "<<endl;
    printList(L); cout<<endl;

    sortList(L);
    printList(L); cout<<endl;
}

//Created Linked List:
//2 1 2 1 1 2 0 1 0
//0 0 1 1 1 1 2 2 2
