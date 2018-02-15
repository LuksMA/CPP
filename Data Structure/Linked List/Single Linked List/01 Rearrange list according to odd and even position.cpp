//https://www.geeksforgeeks.org/rearrange-a-linked-list-such-that-all-even-and-odd-positioned-nodes-are-together/
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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
    while(cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = tmp;
}


ListNode *rearrangeEvenOdd(ListNode *head)
{
    ListNode* dummyOdd = new ListNode(0);
    ListNode* dummyEven = new ListNode(0);
    auto curOdd = dummyOdd;
    auto curEven = dummyEven;
    auto cur = head;
    int count = 1;
    while(cur != nullptr)
    {
        if(count%2 != 0)
        {
            curOdd->next = cur;
            curOdd = curOdd->next;
        }
        else
        {
            curEven->next = cur;
            curEven = curEven->next;
        }
        count++;
        cur = cur->next;
    }
    curOdd->next = dummyEven->next;
    curEven->next = nullptr;
    return dummyOdd->next;
}




int main()
{
    ListNode *L1 = new ListNode(1);
    push(&L1,2);
    push(&L1,3);
    push(&L1,4);
    push(&L1,5);


    cout<<"Created Linked List L1: "<<endl;
    printList(L1);
    cout<<endl;


    printList(rearrangeEvenOdd(L1));
    cout<<endl;
}

//Created Linked List L1:
//1 2 3 4 5
//1 3 5 2 4
