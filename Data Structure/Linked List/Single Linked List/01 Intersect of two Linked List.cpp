//https://www.geeksforgeeks.org/union-and-intersection-of-two-linked-lists/
#include <unordered_set>
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


ListNode* findIntersection(ListNode* head1, ListNode* head2){
    unordered_set<int> lookup;
    ListNode* dummy = new ListNode(0);
    auto cur = dummy;
    while(head1 != nullptr){
        if(lookup.count(head1->val) == 0){
            lookup.insert(head1->val);
        }
        head1 = head1->next;
    }
    while(head2 != nullptr){
        if(lookup.count(head2->val)){
            cur->next = new ListNode(head2->val);
            cur = cur->next;
        }
        head2 = head2->next;
    }
    cur->next = nullptr;
    return dummy->next;
}


int main()
{
    ListNode *L1 = new ListNode(10);
    push(&L1,15);
    push(&L1,4);
    push(&L1,20);
//    push(&L1,6);

    ListNode *L2 = new ListNode(8);
    push(&L2,4);
    push(&L2,2);
    push(&L2,10);

    cout<<"Created Linked List L1: "<<endl;
    printList(L1); cout<<endl;
    cout<<"Created Linked List L2: "<<endl;
    printList(L2); cout<<endl;

    printList(findIntersection(L1,L2)); cout<<endl;
}


//Created Linked List L1:
//10 15 4 20
//Created Linked List L2:
//8 4 2 10
//4 10
