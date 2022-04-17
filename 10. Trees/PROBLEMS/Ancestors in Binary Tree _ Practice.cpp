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

   void printTree(Node *root) {
      if (root == NULL) {
         return;
      }
      printTree(root->left);
      cout << root->data << " ";
      printTree(root->right);
   }

   bool printAncestors(Node *root, int val) {
      if (root == NULL) {
         return (false);
      }

      if (root->data == val) {
         return (true);
      }

      if (printAncestors(root->left, val) || printAncestors(root->right, val)) {
         cout << root->data << " ";
         return (true);
      }

      return (false);
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

      queue<Node *> q;

      while (val != -1) {
         if (q.empty()) {
            root = new Node(val);
            q.push(root);
         } else {
            Node *currNode = q.front();
            Node *newNode  = new Node(val);

            if (currNode->left == NULL) {
               currNode->left = newNode;
            } else {
               currNode->right = newNode;
               q.pop();
            }
            q.push(newNode);
         }

         cin >> val;
      }
   }

   void print() {
      printTree(root);
   }

   void solve() {
      int valToFindAncestorFor;

      cin >> valToFindAncestorFor;
      printAncestors(root, valToFindAncestorFor);
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
