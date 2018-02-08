//https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/

#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *n){
  while (n != nullptr)
  {
     cout<<n->val<<' ';
     n = n->next;
  }
}


void removeDuplicates(ListNode* head){
    unordered_set<int> lookup;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* cur = dummy->next;

    while(cur != nullptr){
        if(lookup.count(cur->val)){
            prev->next = cur->next;
        }else{
            lookup.insert(cur->val);
            prev = prev->next;
        }
        cur = prev->next;
    }
    head = dummy->next;
}

int main(){
    ListNode *ls_0 = new ListNode(12);
    ListNode *ls_1 = new ListNode(11);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(12);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(21); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(43); ls_3->next = ls_4;
    ListNode *ls_5 = new ListNode(21); ls_4->next = ls_5;
    ListNode *ls_6 = new ListNode(60); ls_5->next = ls_6;

    cout<<"Created Linked List: "<<endl;
    printList(ls_0);cout<<endl;

    removeDuplicates(ls_0);
    printList(ls_0);
}

