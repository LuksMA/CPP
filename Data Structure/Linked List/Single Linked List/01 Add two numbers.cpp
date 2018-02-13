//https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
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

ListNode* addTwoLists (ListNode* first, ListNode* second){
    ListNode* dummy = new ListNode(0);
    auto cur = dummy;
    int carry = 0;
    int sum;
    while(first != nullptr || second != nullptr){
        sum = carry + (first?first->val:0) + (second?second->val:0);
        carry = (sum >= 10)? 1:0;
        sum = sum%10;
        cur->next = new ListNode(sum);
        cur = cur->next;

        if(first) first = first->next;
        if(second) second = second->next;
    }
    if(carry>0){
        cur->next = new ListNode(1);
        cur->next->next = nullptr;
    }else{
        cur->next = nullptr;
    }
    return dummy->next;
}


int main()
{
    ListNode *L1 = new ListNode(7);
    push(&L1,5);
    push(&L1,9);
    push(&L1,4);
    push(&L1,6);

    ListNode *L2 = new ListNode(8);
    push(&L2,4);
//    push(&L2,2);


    cout<<"Created Linked List L1: "<<endl;
    printList(L1); cout<<endl;
    cout<<"Created Linked List L2: "<<endl;
    printList(L2); cout<<endl;

    printList(addTwoLists(L1,L2)); cout<<endl;
}


//Created Linked List L1:
//7 5 9 4 6
//Created Linked List L2:
//8 4
//5 0 0 5 6
