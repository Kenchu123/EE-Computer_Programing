//PREPEND BEGIN
#include <iostream>
using namespace std;
// A linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data);

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(struct Node* prev_node, int new_data);

/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data);

// This function prints contents of linked list starting from the given node
void printList(struct Node* node)
{
    struct Node* last;
    cout<<"\nTraversal in forward direction\n";
    while (node != NULL) {
        cout<<node->data<<" ";
        last = node;
        node = node->next;
    }

    cout<<"\nTraversal in reverse direction\n";
    while (last != NULL) {
        cout<<last->data<<" ";
        last = last->prev;
    }
}

/* Drier program to test above functions*/
int main()
{
    Node* head = NULL;
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);

    cout<<"Created DLL is: ";
    printList(head);

    return 0;
}

//PREPEND END

//TEMPLATE BEGIN
void push(struct Node** head_ref, int new_data)
{
  //todo
  if (*head_ref == NULL) {
      *head_ref = new Node;
      (*head_ref)->next = NULL;
      (*head_ref)->prev = NULL;
      (*head_ref)->data = new_data;
      return;
  }
  Node* tmp = new Node;
  tmp->prev = NULL;
  tmp->next = (*head_ref);
  tmp->data = new_data;
  (*head_ref)->prev = tmp;
  (*head_ref) = tmp;
}
void insertAfter(struct Node* prev_node, int new_data)
{
  //todo
  Node* tmp = new Node;
  tmp->prev = prev_node;
  tmp->next = prev_node->next;
  tmp->data = new_data;
  prev_node->next = tmp;
  if (tmp->next != NULL) tmp->next->prev = tmp;
}
void append(struct Node** head_ref, int new_data)
{
  //todo
  if (*head_ref == NULL) {
      *head_ref = new Node;
      (*head_ref)->next = NULL;
      (*head_ref)->prev = NULL;
      (*head_ref)->data = new_data;
      return;
  }
  Node* last = (*head_ref);
  while (last->next != NULL) last = last->next;
  Node* tmp = new Node;
  last->next = tmp;
  tmp->prev = last;
  tmp->next = NULL;
  tmp->data = new_data;
}
//TEMPLATE END