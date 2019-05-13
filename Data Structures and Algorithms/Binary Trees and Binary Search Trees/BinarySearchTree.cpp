#include <iostream>
#include <climits>
#include <queue>

using namespace std;

template <class T>
class BinarySearchTreeNode {
    public:
    T data;
    BinarySearchTreeNode<T> *left;
    BinarySearchTreeNode<T> *right;
    BinarySearchTreeNode(T d):data(d), left(NULL), right(NULL){}
};

BinarySearchTreeNode<int> *buildTree() {
    int d;
    cin >> d;
    if(d == -1) {
        return NULL;
    }
    BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

BinarySearchTreeNode<int> *takeInputLevelWise() {
    int d;
    cin >> d;
    BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(d);
    queue<BinarySearchTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()) {
        BinarySearchTreeNode<int> *n = q.front();
        q.pop();
        int child1, child2;
        cin >> child1 >> child2;
        if(child1 != -1) {
            n->left = new BinarySearchTreeNode<int>(child1);
            q.push(n->left);
        }
        if(child2 != -1) {
            n->right = new BinarySearchTreeNode<int>(child2);
            q.push(n->right);
        }
    }
    return root;
}

void printTree(BinarySearchTreeNode<int> *root) {
    queue<BinarySearchTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()) {
        BinarySearchTreeNode<int> *node = q.front();
        q.pop();
        cout << node->data << ": ";
        if(node->left) {
            cout << "Left -> " << node->left->data << " ";
            q.push(node->left);
        }
        if(node->right) {
            cout << "Right -> " << node->right->data;
            q.push(node->right);
        }
        cout << endl;
    }
}


// Recursive Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
BinarySearchTreeNode<int> *insertNode(BinarySearchTreeNode<int> *root, int data) {
    if(!root) {
        root = new BinarySearchTreeNode<int>(data);
    } else {
        if(data < root->data) {
            root->left = insertNode(root->left, data);
        } else if(data > root->data) {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

// Iterative Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
BinarySearchTreeNode<int> *insertNodeIterative(BinarySearchTreeNode<int> *root, int data) {
    BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(data);
    BinarySearchTreeNode<int> *x = root, *y = NULL;
    while(x != NULL) {
        y = x;
        if(data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    } 
    if(y == NULL) {
        y = node;
    } else if(data < y->data) {
        y->left = node; 
    } else {
        y->right = node;
    }
    return root;
}

// Recursive Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
int findMaximumValueRecursive(BinarySearchTreeNode<int> *root) {
    if(!root) {
        return -1;
    } else if(root->right == NULL) {
        return root->data;
    } else {
        return findMaximumValueRecursive(root->right);
    }
}

// Iterative Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
int findMaximumValueIterative(BinarySearchTreeNode<int> *root) {
    while(root->right) {
        root = root->right;
    }
    return root->data;
}

// Recursive Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isBST(BinarySearchTreeNode<int> *root, int MIN, int MAX) {
    if(!root) {
        return true;
    }
    if(root->data < MIN || root->data > MAX) {
        return false;
    }
    return isBST(root->left, MIN, root->data) && isBST(root->right, root->data + 1, MAX);
}

int main() {
    BinarySearchTreeNode<int> *root = buildTree();
    // cout << findMaximumValueRecursive(root) << "\n";
    // cout << findMaximumValueIterative(root) << "\n";

    /* Is BST
    if(isBST(root, INT_MIN, INT_MAX)) {
        cout << "Is a Binary Search Tree!\n";
    } else {
        cout << "Not a Binary Search Tree!\n";
    }
    */
    // printTree(root);
    // cout << endl;
    // root = insertNodeIterative(root, 5);
    // printTree(root);
    return 0;
}