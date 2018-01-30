// https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/

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


void swapNodes(struct ListNode **head, int x, int y)
{
    if (x == y) return;
    ListNode* dummy = new ListNode(0);
    dummy->next = *head;
    auto prevX = dummy;
    auto prevY = dummy;
    auto curX = *head;
    auto curY = *head;

    while(curX){
        if(curX->val == x){
            break;
        }else{
            prevX = prevX->next;
            curX = curX->next;
        }
    }
    while(curY){
        if(curY->val == y){
            break;
        }else{
            prevY = prevY->next;
            curY = curY->next;
        }
    }

    prevX->next = curY;
    prevY->next = curX;
    auto tmp = curY->next;
    curY->next = curX->next;
    curX->next  = tmp;

    *head = dummy->next;
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

    printList(ls_0);
    cout<<endl;

    cout<<"Swap 12 and 20:"<<endl;
    swapNodes(&ls_0,12,20);
    printList(ls_0);
    cout<<endl;

    cout<<"Swap 10 and 20:"<<endl;
    swapNodes(&ls_0,10,20);
    printList(ls_0);cout<<endl;

    cout<<"Swap 12 and 13:"<<endl;
    swapNodes(&ls_0,12,13);
    printList(ls_0);cout<<endl;
}
