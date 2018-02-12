//https://www.geeksforgeeks.org/merge-sort-for-linked-list/
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

ListNode* SortedMerge(ListNode* a, ListNode* b)
{
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    ListNode* result = nullptr;
    if(a->val <= b->val){
        result = a;
        result->next = SortedMerge(a->next,b);
    }else{
        result = b;
        result->next = SortedMerge(a,b->next);
    }
    return result;
}




void FrontBackSplit(ListNode* source, ListNode** frontRef, ListNode** backRef){
    auto slow = source;
    auto slow_prev = source;
    auto fast = source;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow_prev = slow;
        slow = slow->next;
    }
    *backRef = slow;
    slow_prev->next = nullptr;
    *frontRef = source;
}


void MergeSort(ListNode** headRef){
    ListNode* head = *headRef;
    ListNode* a;
    ListNode* b;

    if(head == nullptr || head->next == nullptr){
        return;
    }
    FrontBackSplit(head,&a,&b);
    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a,b);
}



int main()
{
    ListNode *L = new ListNode(2);
    ListNode *ls_1 = new ListNode(4);  L->next = ls_1;
    ListNode *ls_2 = new ListNode(3);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(1);  ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(5);  ls_3->next = ls_4;
    ListNode *ls_5 = new ListNode(2);  ls_4->next = ls_5;
    ListNode *ls_6 = new ListNode(3);  ls_5->next = ls_6;
    ListNode *ls_7 = new ListNode(4);  ls_6->next = ls_7;

    cout<<"Created Linked List: "<<endl;
    printList(L); cout<<endl;

    MergeSort(&L);
    cout<<"After sort: "<<endl;
    printList(L); cout<<endl;
}


//Created Linked List:
//2 4 3 1 5 2 3 4
//After sort:
//1 2 2 3 3 4 4 5
