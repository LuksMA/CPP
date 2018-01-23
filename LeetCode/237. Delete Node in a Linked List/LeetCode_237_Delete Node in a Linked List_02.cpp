#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(struct ListNode *n)
{
    while (n != NULL)
    {
        cout<<n->val<<' ';
        n = n->next;
    }
    cout<<endl;
}


class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *(node->next);
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l1_1 = new ListNode(2);   l1->next = l1_1;
    ListNode *l1_2 = new ListNode(2);   l1_1->next = l1_2;
    ListNode *l1_3 = new ListNode(4);   l1_2->next = l1_3;
//    ListNode *l1_4 = new ListNode(4);   l1_3->next = l1_4;
//    ListNode *l1_5 = new ListNode(5);   l1_4->next = l1_5;
//    ListNode *l1_6 = new ListNode(6);   l1_5->next = l1_6;

//    printList(l1);

    Solution s;

}
