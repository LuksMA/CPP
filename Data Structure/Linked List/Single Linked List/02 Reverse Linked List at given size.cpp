//https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

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


void reverse(ListNode** head){
    if(*head == nullptr) return;
    ListNode* prev = nullptr;
    ListNode* cur = *head;
    ListNode* next;
    while(cur != nullptr){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}



ListNode *reverse (ListNode *head, int k){
    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* next= nullptr;
    int count = 0;
    while(cur != nullptr && count < k){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        ++count;
    }
    if(next != nullptr)
        head->next = reverse(next,k);
    return prev;
}


int main()
{
    ListNode *L = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  L->next = ls_1;
    ListNode *ls_2 = new ListNode(3);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(4);  ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(5);  ls_3->next = ls_4;
    ListNode *ls_5 = new ListNode(6);  ls_4->next = ls_5;
    ListNode *ls_6 = new ListNode(7);  ls_5->next = ls_6;
    ListNode *ls_7 = new ListNode(8);  ls_6->next = ls_7;

    cout<<"Created Linked List: "<<endl;
    printList(L); cout<<endl;

    cout<<"After reverse: "<<endl;
    printList(reverse(L,3)); cout<<endl;
}


//Created Linked List:
//1 2 3 4 5 6 7 8
//After reverse:
//3 2 1 6 5 4 8 7
