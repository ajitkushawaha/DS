// // Q3. Create a linked list and perform all the related operations?

// #include <iostream>

// using namespace std;

// class Node
// {

// public:
//   int data;
//   Node *next = NULL;

//   Node(int data)
//   {
//     this->data = data;
//   }
// };

// class NodeList
// {
//   Node *head = NULL;
//   int size = 0;

// public:
//   Node *insertAtStart(int num)
//   {
//     Node *newNode = new Node(num);

//     if (head == NULL)
//     {
//       head = newNode;
//       size++;
//       return newNode;
//     }

//     newNode->next = head;
//     head = newNode;

//     size++;
//     return newNode;
//   }

//   Node *insertAtEnd(int num)
//   {
//     if (head == NULL)
//     {
//       return insertAtStart(num);
//     }

//     Node *temp = head;
//     Node *newNode = new Node(num);

//     while (temp->next != NULL)
//     {
//       temp = temp->next;
//     }

//     temp->next = newNode;

//     size++;
//     return newNode;
//   }

//   Node *insertAtPosition(int num, int pos = -1)
//   {

//     if (pos < 0 || pos > size)
//       throw "Invalid position";

//     if (pos == 0)
//       return insertAtStart(num);

//     if (pos == size)
//       return insertAtEnd(num);

//     if (head == NULL)
//       throw "Position is out of bound";

//     int currentPos = 1;
//     Node *temp = head;

//     Node *newNode = new Node(num);

//     while (currentPos < pos)
//     {
//       temp = temp->next;
//       currentPos++;
//     }

//     newNode->next = temp->next;
//     temp->next = newNode;

//     size++;
//     return newNode;
//   }

//   void deleteAtStart()
//   {
//     if (head == NULL)
//       throw "No node exist in the list";

//     Node *temp = head;

//     head = temp->next;
//     size--;
//     delete temp;
//   }

//   void deleteAtEnd()
//   {
//     if (head == NULL)
//       throw "No node exist in the list";

//     if (head->next == NULL)
//     {
//       size--;
//       delete head;
//       head = NULL;
//       return;
//     }

//     Node *temp = head;
//     Node *tempLast = NULL;

//     while (temp->next != NULL)
//     {
//       tempLast = temp;
//       temp = temp->next;
//     }

//     size--;
//     delete temp->next;
//     tempLast->next = NULL;
//   }

//   void deleteAtPosition(int pos)
//   {
//     if (pos < 0 || pos > size - 1)
//     {
//       throw "Position out of bound";
//     }
//     if (pos == 0)
//     {
//       return deleteAtStart();
//     }
//     if (pos == size - 1)
//     {
//       return deleteAtEnd();
//     }

//     int currentPos = 0;
//     Node *temp = head;
//     Node *tempLast = head;

//     while (currentPos < pos)
//     {
//       tempLast = temp;
//       temp = temp->next;
//       currentPos++;
//     }

//     tempLast->next = temp->next;
//     size--;
//     delete temp;
//   }

//   Node *search(int num)
//   {
//     Node *temp = head;

//     while (temp != NULL)
//     {
//       if (temp->data == num)
//       {
//         return temp;
//       }
//       temp = temp->next;
//     }

//     return NULL;
//   }

//   void traverse()
//   {
//     Node *temp = head;

//     while (temp != NULL)
//     {
//       cout << temp->data << " ";
//       temp = temp->next;
//     }
//     cout << endl;
//   }
// };

// int main()
// {
//   NodeList *list = new NodeList();

//   try
//   {
//     list->insertAtEnd(5);
//     list->insertAtEnd(6);
//     list->insertAtEnd(7);
//     list->insertAtStart(4);
//     list->insertAtPosition(10, 2);

//     int n = 10;

//     Node *searchNode = list->search(n);

//     if (searchNode == NULL)
//     {
//       cout << n << " is not found in list" << endl;
//     }
//     else
//     {
//       cout << n << " is found" << endl;
//     }

//     list->traverse();

//     list->deleteAtStart();
//     list->deleteAtEnd();
//     list->deleteAtPosition(1);

//     list->traverse();
//   }
//   catch (const char *s)
//   {
//     cout << s << endl;
//   }

//   return 0;
// }

// Linked list operations in C++

#include <stdlib.h>

#include <iostream>
using namespace std;

// Create a node
struct Node {
  int data;
  struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
  // Allocate memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the data
  new_node->data = new_data;
  new_node->next = (*head_ref);

  // Move head to new node
  (*head_ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node* prev_node, int new_data) {
  if (prev_node == NULL) {
  cout << "the given previous node cannot be NULL";
  return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Insert at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref; /* used in step 5*/

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

// Delete a node
void deleteNode(struct Node** head_ref, int key) {
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

// Search a node
bool searchNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;

  while (current != NULL) {
  if (current->data == key) return true;
  current = current->next;
  }
  return false;
}

// Sort the linked list
void sortLinkedList(struct Node** head_ref) {
  struct Node *current = *head_ref, *index = NULL;
  int temp;

  if (head_ref == NULL) {
  return;
  } else {
  while (current != NULL) {
    // index points to the node next to current
    index = current->next;

    while (index != NULL) {
    if (current->data > index->data) {
      temp = current->data;
      current->data = index->data;
      index->data = temp;
    }
    index = index->next;
    }
    current = current->next;
  }
  }
}

// Print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
  cout << node->data << " ";
  node = node->next;
  }
}

// Driver program
int main() {
  struct Node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  cout << "Linked list: ";
  printList(head);

  cout << "\nAfter deleting an element: ";
  deleteNode(&head, 3);
  printList(head);

  int item_to_find = 3;
  if (searchNode(&head, item_to_find)) {
  cout << endl << item_to_find << " is found";
  } else {
  cout << endl << item_to_find << " is not found";
  }

  sortLinkedList(&head);
  cout << "\nSorted List: ";
  printList(head);
}