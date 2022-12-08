// Q5.Create a Binary Search Tree and perform related operations?

#include <iostream>

using namespace std;

class Node
{

public:
  int data;
  Node *left = NULL;
  Node *right = NULL;

  Node(int data)
  {
    this->data = data;
  }
};

class BST
{
  Node *insertHelper(int data, Node *node)
  {
    if (node == NULL)
    {
      return new Node(data);
    }
    if (data >= node->data)
    {
      node->right = insertHelper(data, node->right);
    }
    else
    {
      node->left = insertHelper(data, node->left);
    }
    return node;
  }

  Node *deleteHelper(int data, Node *node)
  {
    if (node == NULL)
      return NULL;
    if (node->data < data)
    {
      node->right = deleteHelper(data, node->right);
    }
    else if (node->data > data)
    {
      node->left = deleteHelper(data, node->left);
    }
    else
    {
      Node *rightNode = node->right;
      Node *leftNode = node->left;

      if (rightNode != NULL)
      {
        if (rightNode->left != NULL)
        {
          Node *smallestNodeParent = rightNode->left;
          Node *smallestNode = rightNode->left->left;
          while (smallestNode->left != NULL)
          {
            smallestNodeParent = smallestNode;
            smallestNode = smallestNode->left;
          }
          smallestNodeParent = smallestNode->right;
          smallestNode->left = node->left;
          smallestNode->right = node->right;
          delete node;
          return smallestNode;
        }
        else
        {
          rightNode->left = node->left;
          return rightNode;
        }
      }
      else
      {
        delete node;
        return leftNode;
      }
    }

    return node;
  }

  void traversePreorderHelper(Node *node)
  {
    if (node == NULL)
      return;
    cout << node->data << " ";
    traversePreorderHelper(node->left);
    traversePreorderHelper(node->right);
  }

  void traverseInorderHelper(Node *node)
  {
    if (node == NULL)
      return;
    traversePreorderHelper(node->left);
    cout << node->data << " ";
    traversePreorderHelper(node->right);
  }

  void traversePostorderHelper(Node *node)
  {
    if (node == NULL)
      return;
    traversePreorderHelper(node->left);
    traversePreorderHelper(node->right);
    cout << node->data << " ";
  }

  Node *searchHelper(int data, Node *node)
  {
    if (node->data == data)
    {
      return node;
    }
    if (node->data > data)
    {
      return searchHelper(data, node->left);
    }
    else
    {
      return searchHelper(data, node->right);
    }
  }

public:
  Node *root = NULL;

  void insertNode(int data)
  {
    root = insertHelper(data, root);
  }

  void deleteNode(int data)
  {
    root = deleteHelper(data, root);
  }

  void traversePreorder()
  {
    cout << "Pre order traversal : ";
    if (root != NULL)
    {
      traversePreorderHelper(root);
    }
    cout << endl;
  }

  void traverseInorder()
  {
    cout << "In order traversal : ";
    if (root != NULL)
    {
      traverseInorderHelper(root);
    }
    cout << endl;
  }

  void traversePostorder()
  {
    cout << "Post order traversal : ";
    if (root != NULL)
    {
      traversePostorderHelper(root);
    }
    cout << endl;
  }

  Node *search(int data)
  {
    return searchHelper(data, root);
  }
};

int main()
{
  BST *bst = new BST();

  bst->insertNode(8);
  bst->insertNode(10);
  bst->insertNode(6);
  bst->insertNode(7);
  bst->insertNode(5);
  bst->insertNode(9);
  bst->insertNode(11);

  bst->deleteNode(10);
  bst->deleteNode(5);

  Node *node = bst->search(9);

  bst->traverseInorder();
  bst->traversePreorder();
  bst->traversePostorder();

  return 0;
}