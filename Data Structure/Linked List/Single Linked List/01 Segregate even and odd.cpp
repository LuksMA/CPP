//https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/
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

void segregateEvenOdd(ListNode **head_ref){
    ListNode* dummy1 = new ListNode(0);
    auto cur1 = dummy1;
    ListNode* dummy2 = new ListNode(0);
    auto cur2 = dummy2;
    auto cur = *head_ref;
    while(cur != nullptr){
        if(cur->val%2 == 0){
            cur1->next = cur;
            cur1 = cur1->next;
        }else{
            cur2->next = cur;
            cur2 = cur2->next;
        }
        cur = cur->next;
    }
    cur1->next = dummy2->next;
    cur2->next = nullptr;

    *head_ref = dummy1->next;
}


int main()
{
    ListNode *L = new ListNode(17);
    push(&L,15);
    push(&L,8);
    push(&L,12);
    push(&L,10);
    push(&L,5);
    push(&L,4);
    push(&L,1);
    push(&L,7);
    push(&L,6);

    cout<<"Created Linked List: "<<endl;
    printList(L); cout<<endl;

    segregateEvenOdd(&L);
    printList(L); cout<<endl;
}


//Created Linked List:
//17 15 8 12 10 5 4 1 7 6
//8 12 10 4 6 17 15 5 1 7
