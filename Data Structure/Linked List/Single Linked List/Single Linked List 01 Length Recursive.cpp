#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getCount(struct ListNode* head){
    if(head == nullptr){
        return 0;
    }else{
        return 1+getCount(head->next);
    }
}


int main(){
    ListNode *ls_0 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  ls_0->next = ls_1;
    ListNode *ls_2 = new ListNode(3);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(10); ls_2->next = ls_3;
    ListNode *ls_4 = new ListNode(20); ls_3->next = ls_4;

    cout<<getCount(ls_0)<<endl;
    cout<<getCount(ls_4)<<endl;
}

//5
//1
