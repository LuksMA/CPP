//https://www.geeksforgeeks.org/make-middle-node-head-linked-list/

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
    while (n != NULL)
    {
        cout<<n->val<<' ';
        n = n->next;
    }
}

void setMiddleHead(ListNode** head)
{
    auto middle = *head;
    auto fast = *head;
    auto prev = *head;
    while(fast && fast->next){
        prev = middle;
        middle = middle->next;
        fast = fast->next->next;
    }
    prev->next = prev->next->next;
    middle->next = *head;
    *head = middle;
}



int main()
{
    ListNode *ls_0 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(9);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(10); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(20); ls_3->next = ls_4;

    cout<<"Created Linked List: "<<endl;
    printList(ls_0);cout<<endl;

    setMiddleHead(&ls_0);
    printList(ls_0);cout<<endl;
}


//Created Linked List:
//1 2 9 10 20
//9 1 2 10 20
