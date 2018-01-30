// https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/

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


void printMiddle(ListNode *head){
    auto slow = head;
    auto fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    cout<<slow->val;
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
    printMiddle(ls_0);cout<<endl;

    printList(ls_1);cout<<endl;
    printMiddle(ls_1);cout<<endl;

}

//10 15 12 13 20 14
//13
//15 12 13 20 14
//13

