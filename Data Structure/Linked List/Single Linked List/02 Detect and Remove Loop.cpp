//https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
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

void removeLoop(ListNode* node, ListNode* head){
    auto ptr1 = node;
    auto ptr2 = node;
    unsigned int k = 1;

    // Count the number of nodes in loop
    while(ptr1->next != ptr2){
        ptr1 = ptr1->next;
        k++;
    }

    ptr1 = head;
    ptr2 = head;

    for(unsigned int i = 0; i < k; i++)
        ptr2 = ptr2->next;

    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

     // Get pointer to the last node
    ptr2 = ptr2->next;
    while (ptr2->next != ptr1)
       ptr2 = ptr2->next;

    ptr2->next = nullptr;
}

void removeTheLoop(ListNode *node){
    ListNode* slow = node;
    ListNode* fast = node;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            removeLoop(slow, node);
            return;
        }
    }
}



int main()
{
    ListNode *L = new ListNode(50);
    L->next = new ListNode(20);
    L->next->next = new ListNode(15);
    L->next->next->next = new ListNode(4);
    L->next->next->next->next = new ListNode(10);

    L->next->next->next->next->next = L->next->next;

    removeTheLoop(L);
    printList(L); cout<<endl;
}


//50 20 15 4 10
