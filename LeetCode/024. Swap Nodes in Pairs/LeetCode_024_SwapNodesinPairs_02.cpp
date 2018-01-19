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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        auto curr = dummy;
        while (curr->next && curr->next->next) {
            auto next_one = curr->next;
            auto next_two = next_one->next;
            auto next_three = next_two->next;
            curr->next = next_two;
            next_two->next = next_one;
            next_one->next = next_three;
            curr = next_one;
        }
        return dummy->next;
    }
};




int main()
{
    ListNode *l = new ListNode(1);
    ListNode *l_1 = new ListNode(2);
    ListNode *l_2 = new ListNode(3);
    ListNode *l_3 = new ListNode(4);

    l->next = l_1;
    l_1->next = l_2;
    l_2->next = l_3;

    Solution s;
    printList(s.swapPairs(l));


}

