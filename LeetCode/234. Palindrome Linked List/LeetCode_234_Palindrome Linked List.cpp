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
    bool isPalindrome(ListNode* head) {
        // Reverse the first half list.
        ListNode *reverse = nullptr, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            const auto head_next = head->next;
            head->next = reverse;
            reverse = head;
            head = head_next;
        }

        // If the number of the nodes is odd,
        // set the head of the tail list to the next of the median node.
        ListNode *tail = fast ? head->next : head;

        // Compare the reversed first half list with the second half list.
        // And restore the reversed first half list.
        bool is_palindrome = true;
        while (reverse) {
            is_palindrome = is_palindrome && reverse->val == tail->val;
            const auto reverse_next = reverse->next;
            reverse->next = head;
            head = reverse;
            reverse = reverse_next;
            tail = tail->next;
        }

        return is_palindrome;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l1_1 = new ListNode(1);   l1->next = l1_1;
    ListNode *l1_2 = new ListNode(2);   l1_1->next = l1_2;
    ListNode *l1_3 = new ListNode(1);   l1_2->next = l1_3;
//    ListNode *l1_4 = new ListNode(4);   l1_3->next = l1_4;
//    ListNode *l1_5 = new ListNode(5);   l1_4->next = l1_5;
//    ListNode *l1_6 = new ListNode(6);   l1_5->next = l1_6;

//    printList(l1);

    Solution s;
    cout<<s.isPalindrome(l1);
}
