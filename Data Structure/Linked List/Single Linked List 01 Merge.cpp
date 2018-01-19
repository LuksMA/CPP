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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        auto curr = &dummy;
        while( l1 && l2){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l1_1 = new ListNode(2);
    ListNode *l1_2 = new ListNode(4);
    l1->next = l1_1;
    l1_1->next = l1_2;

    ListNode *l2 = new ListNode(1);
    ListNode *l2_1 = new ListNode(3);
    ListNode *l2_2 = new ListNode(4);
    l2->next = l2_1;
    l2_1->next = l2_2;

//    printList(l1);
//    printList(l2);
    Solution s;
    printList(s.mergeTwoLists(l1,l2));

}
