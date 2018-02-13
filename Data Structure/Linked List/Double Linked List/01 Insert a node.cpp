//https://www.geeksforgeeks.org/doubly-linked-list/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};


void append(struct Node** head_ref, int new_data){
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = nullptr;
    auto cur = *head_ref;
    /*If the List is empty*/
    if(cur == nullptr){
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }
    while(cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = new_node;
    new_node->prev = cur;
    return;
}

void addNode(Node **head_ref,int pos,int data){
    Node* new_node = new Node;
    new_node->data = data;
    auto cur = *head_ref;
    while(cur->next != nullptr && pos != 0){
        cur = cur->next;
        --pos;
    }
    if(cur->next == nullptr){
        cur->next = new_node;
        new_node->next = nullptr;
        new_node->prev = cur;
        return;
    }

    new_node->next = cur->next;
    cur->next->prev = new_node;
    cur->next = new_node;
    new_node->prev = cur;
    return;
}



void printList(Node* node){
    while(node != nullptr){
        cout<<node->data<<' ';
        node = node->next;
    }
    cout<<endl;
}



int main(){
    Node* head = nullptr;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    printList(head);

    addNode(&head,2,10);
    printList(head);
}
