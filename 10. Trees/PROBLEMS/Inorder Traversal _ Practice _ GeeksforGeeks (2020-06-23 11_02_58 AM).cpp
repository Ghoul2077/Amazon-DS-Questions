#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


struct Node {
   int   data;
   Node *left;
   Node *right;

   Node(int val) {
      data  = val;
      left  = NULL;
      right = NULL;
   }
};

class Tree {
private:
   Node *root;

   Node* push(Node *root, int data) {
      if (root == NULL) {
         Node *newNode = new Node(data);
         return (newNode);
      }

      if (data < root->data) {
         root->left = push(root->left, data);
      } else {
         root->right = push(root->right, data);
      }

      return (root);
   }

   Node* findPredecessorModified(Node *root) {
      if ((root == NULL) || (root->left == NULL)) {
         return (NULL);
      }
      Node *curr = root->left;

      while (curr->right != NULL && curr->right != root) {
         curr = curr->right;
      }
      return (curr);
   }

   void inorderTraversal(Node *root) {
      if (root == NULL) {
         return;
      }
      inorderTraversal(root->left);
      cout << root->data << " ";
      inorderTraversal(root->right);
   }

   void inorderMorrisTraversal(Node *root) {
      Node *curr = root;

      while (curr != NULL) {
         if (curr->left != NULL) {
            Node *predecessor = findPredecessorModified(curr);

            if (predecessor == NULL) {
               curr = curr->right;
            } else if (predecessor->right == NULL) {
               predecessor->right = curr;
               curr               = curr->left;
            } else {
               predecessor->right = NULL;
               cout << curr->data << " ";
               curr = curr->right;
            }
         } else {
            cout << curr->data << " ";
            curr = curr->right;
         }
      }
   }

public:
   Tree() {
      root = NULL;
   }

   Tree(int data) {
      root = new Node(data);
   }

   void initialize() {
      int val;

      cin >> val;

      while (val != -1) {
         insert(val);
         cin >> val;
      }
   }

   void solve() {
      inorderMorrisTraversal(root);
   }

   void insert(int data) {
      root = push(root, data);
   }
};

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Tree *t = new Tree();
      t->initialize();
      t->solve();
      cout << endl;
   }
   return (0);
}
