//https://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/

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


void delLesserNodes(ListNode **head_ref){
    ListNode *current = *head_ref;
    ListNode *maxnode = *head_ref;
    ListNode *temp;

     while (current != NULL && current->next != NULL)
     {
         if(current->next->val < maxnode->val)
         {
             temp = current->next;
             current->next = temp->next;
             delete temp;
         }
         else
         {
             current = current->next;
             maxnode = current;
         }
     }
}


ListNode *compute(ListNode *head){
    reverse(&head);
    delLesserNodes(&head);
    reverse(&head);
    return head;
}




int main()
{
    ListNode *L = new ListNode(12);
    ListNode *ls_1 = new ListNode(15);  L->next = ls_1;
    ListNode *ls_2 = new ListNode(10);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(11);  ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(5);  ls_3->next = ls_4;
    ListNode *ls_5 = new ListNode(6);  ls_4->next = ls_5;
    ListNode *ls_6 = new ListNode(2);  ls_5->next = ls_6;
    ListNode *ls_7 = new ListNode(3);  ls_6->next = ls_7;

    cout<<"Created Linked List: "<<endl;
    printList(L); cout<<endl;

    printList(compute(L));
}


//Created Linked List:
//12 15 10 11 5 6 2 3
//15 11 6 3
