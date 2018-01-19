#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(struct ListNode *n){
  while (n != NULL){
     cout<<n->val<<' ';
     n = n->next;
  }
  cout<<endl;
}


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        auto curr = dummy;
        while (curr->next && curr->next->next) {
            auto next_one = curr->next;
            auto next_two = next_one->next;

            if(next_one->val == next_two->val){
                curr->next = next_two;
            }else{
                curr = next_one;
            }
        }
        return dummy->next;
    }
};



int main()
{
    ListNode *l = new ListNode(1);
    ListNode *l_1 = new ListNode(1);
    ListNode *l_2 = new ListNode(2);
    ListNode *l_3 = new ListNode(3);
    ListNode *l_4 = new ListNode(3);


    l->next = l_1;
    l_1->next = l_2;
    l_2->next = l_3;
    l_3->next = l_4;

    Solution s;
    printList(s.deleteDuplicates(l));


}
