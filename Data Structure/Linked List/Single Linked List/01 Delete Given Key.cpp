#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(struct ListNode *n){
  while (n != NULL)
  {
     cout<<n->val<<' ';
     n = n->next;
  }
}


void delete_key(int x, ListNode** head){
    ListNode *dummy = new ListNode(0);
    dummy->next = *head;
    auto prev = dummy;
    auto cur = prev->next;
    while(cur != nullptr && prev->next != nullptr){
        if(cur->val == x){
            prev->next = cur->next;
            free(cur);
        }else{
            prev = cur;
        }
        cur = prev->next;
    }

    *head = dummy->next;
}



int main(){
    ListNode *ls_0 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(3);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(10); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(20); ls_3->next = ls_4;

    cout<<"Created Linked List: "<<endl;
    printList(ls_0);cout<<endl;

    cout<<"After Deletion head of 1: "<<endl;
    delete_key(1,&ls_0);
    printList(ls_0);cout<<endl;

    cout<<"After Deletion middle of 10: "<<endl;
    delete_key(10,&ls_0);
    printList(ls_0);cout<<endl;

    cout<<"After Deletion end of 20: "<<endl;
    delete_key(20,&ls_0);
    printList(ls_0);cout<<endl;
}
