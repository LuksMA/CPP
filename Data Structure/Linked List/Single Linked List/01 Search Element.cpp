#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool search(ListNode* head, int x){
    while(head){
        if(head->val == x){
            return true;
        }else{
            head = head->next;
        }
    }
    return false;
}



int main(){
    ListNode *ls_0 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(3);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(10); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(20); ls_3->next = ls_4;

    cout<<search(ls_0,10)<<endl;
    cout<<search(ls_0,50)<<endl;
}


//1
//0
