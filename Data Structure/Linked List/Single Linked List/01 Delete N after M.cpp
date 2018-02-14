//https://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/
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

void linkdelete(ListNode *head, int M, int N){
//    ListNode* dummy = new ListNode(0);
//    dummy->next = head;
    auto prev = head;
    auto cur = head;
    int index = 0;
    while(cur != nullptr){
        if(index < M){
            ++index;
            prev = cur;
            cur = prev->next;
        }else if(index >= M && index < M+N){
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
            ++index;
        }else{
            index = 0;
        }
    }
}


int main()
{
    ListNode *L1 = new ListNode(1);
    push(&L1,2);
    push(&L1,3);
    push(&L1,4);
    push(&L1,5);
    push(&L1,6);
    push(&L1,7);
    push(&L1,8);
    push(&L1,9);
    push(&L1,10);

    cout<<"Created Linked List L1: "<<endl;
    printList(L1); cout<<endl;

    linkdelete(L1,3,2);
    printList(L1);
}

//Created Linked List L1:
//1 2 3 4 5 6 7 8 9 10
//1 2 3 6 7 8
