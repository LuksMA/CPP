// https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/

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


void printNthFromLast(ListNode* head, int n){
    auto slow = head;
    auto fast = head;
    int i=0;
    while( i<=n && fast){
        fast = fast->next;
        ++i;
    }
    if(fast == nullptr){
        cout<<"Exceed range!"<<endl;
        return;
    }else{
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        cout<<slow->val;
    }

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
    printNthFromLast(ls_0,0);cout<<endl;
    printNthFromLast(ls_0,1);cout<<endl;
    printNthFromLast(ls_0,7);cout<<endl;


}

//10 15 12 13 20 14
//14
//20
//Exceed range!



