//https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};


void append(struct Node** head_ref, int new_data)
{
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = nullptr;
    auto cur = *head_ref;
    /*If the List is empty*/
    if(cur == nullptr)
    {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }
    while(cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = new_node;
    new_node->prev = cur;
    return;
}

void reverse(Node **head_ref){
    if((*head_ref)->next == nullptr || *head_ref == nullptr) return;
    Node* tmp;
    Node* cur = *head_ref;
    while(cur != nullptr){
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev;
    }
    if(tmp != nullptr )
        *head_ref = tmp->prev;
}



void printList(Node* node)
{
    while(node != nullptr)
    {
        cout<<node->data<<' ';
        node = node->next;
    }
    cout<<endl;
}



int main()
{
    Node* head = nullptr;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    printList(head);

    reverse(&head);
    printList(head);
}
