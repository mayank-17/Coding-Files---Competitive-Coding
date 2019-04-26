#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <climits>
#include <map>
#include <vector>

using namespace std;

template<class T>
class binaryTreeNode {
    public:
    T data;
    T horizontalDistance;
    binaryTreeNode<T> *left;
    binaryTreeNode<T> *right;
    binaryTreeNode(T d):data(d), left(NULL), right(NULL){}
};

binaryTreeNode<int> *buildTree() {
    int d;
    cin >> d;
    if(d == -1) {
        return NULL;
    }
    binaryTreeNode<int> *n = new binaryTreeNode<int>(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void preOrderTraversal(binaryTreeNode<int> *root) {
	if(root == NULL){
		return;
	}
	cout << root->data << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(binaryTreeNode<int> *root) {
	if(root == NULL){
		return;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
    cout << root->data << " ";
}

void inOrderTraversal(binaryTreeNode<int> *root) {
	if(root == NULL){
		return;
	}
	inOrderTraversal(root->left);
    cout << root->data << " ";
	inOrderTraversal(root->right);
}

void printKthLevel(binaryTreeNode<int> *root, int k) {
    if(root == NULL || k < 1) {
        return;
    }
    if(k == 1) {
        cout << root->data << " ";
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
}

// O(n)
int heightOfBinaryTree(binaryTreeNode<int> *root) {
    if(root == NULL) {
        return 0;
    }
    int h1 = heightOfBinaryTree(root->left);
    int h2 = heightOfBinaryTree(root->right);
    return max(h1, h2) + 1;
}

void levelOrderTraversal(binaryTreeNode<int> *root) {
    int h = heightOfBinaryTree(root);
    for(int i = 1; i <= h; i++) {
        printKthLevel(root, i);
        cout << "\n";
    }
}

binaryTreeNode<int> *takeInputLevelWise() {
    int d;
    cin >> d;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(d);
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()) {
        binaryTreeNode<int> *n = q.front();
        q.pop();
        int child1, child2;
        cin >> child1 >> child2;
        if(child1 != -1) {
            n->left = new binaryTreeNode<int>(child1);
            q.push(n->left);
        }
        if(child2 != -1) {
            n->right = new binaryTreeNode<int>(child2);
            q.push(n->right);
        }
    }
    return root;
}

void levelOrderTraversalUsingQueue(binaryTreeNode<int> *root) {
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()) {
        binaryTreeNode<int> *n = q.front();
        q.pop();
        if(n) {
            cout << n->data << " ";
            if(n->left) {
                q.push(n->left);
            }
            if(n->right) {
                q.push(n->right);
            }
        }

    }
}

int findMaximum(binaryTreeNode<int> *root) {
    int MAX = INT_MIN;
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()) {
        binaryTreeNode<int> *n = q.front();
        q.pop();
        if(MAX < n->data) {
            MAX = n->data;
        }
        if(n->left) {
            q.push(n->left);
        }
        if(n->right) {
            q.push(n->right);
        }
    }
    return MAX;
}

int findMinimum(binaryTreeNode<int> *root) {
    int MIN = INT_MAX;
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()) {
        binaryTreeNode<int> *n = q.front();
        q.pop();
        if(MIN > n->data) {
            MIN = n->data;
        }
        if(n->left) {
            q.push(n->left);
        }
        if(n->right) {
            q.push(n->right);
        }
    }
    return MIN;
}

int findElement(binaryTreeNode<int> *root, int data) {
    if(root) {
        if(data == root->data) {
            return 1;
        } else {
            int temp = findElement(root->left, data);
            if(temp) {
                return temp;
            } else {
                return findElement(root->right, data);
            }
        }
    } else {
        return 0;
    }
}

int findElementUsingQueue(binaryTreeNode<int> *root, int data) {
    queue<binaryTreeNode<int> *> q;
    if(!root) {
        return 0;
    }
    q.push(root);
    int found = 0;
    while(!q.empty()) {
        binaryTreeNode<int> *n = q.front();
        q.pop();
        if(data == n->data) {
            found = 1;
            break;
        }
        if(n->left) {
            q.push(n->left);
        }
        if(n->right) {
            q.push(n->right);
        }
    }
    return found;
}

int numberOfLeafbinaryTreeNodes(binaryTreeNode<int> *root) {
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    if(!root) {
        return 0;
    }
    int count = 0;
    while(!q.empty()) {
        binaryTreeNode<int> *n = q.front();
        q.pop();
        if(n->left == NULL && n->right == NULL) {
            count++;
        } else {
            if(n->left) {
                q.push(n->left);
            }
            if(n->right) {
                q.push(n->right);
            }
        }
    }
    return count;
}

int numberOfFullbinaryTreeNodes(binaryTreeNode<int> *root) {
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    if(!root) {
        return 0;
    }
    int count = 0;
    while(!q.empty()) {
        binaryTreeNode<int> *n = q.front();
        q.pop();
        if(n->left && n->right) {
            count++;
        } else {
            if(n->left) {
                q.push(n->left);
            }
            if(n->right) {
                q.push(n->right);
            }
        }
    }
    return count;
}

int numberOfHalfbinaryTreeNodes(binaryTreeNode<int> *root) {
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    if(!root) {
        return 0;
    }
    int count = 0;
    while(!q.empty()) {
        binaryTreeNode<int> *n = q.front();
        q.pop();
        if((!n->left && n->right) || (n->left && !n->right)) {
            count++;
        } else {
            if(n->left) {
                q.push(n->left);
            }
            if(n->right) {
                q.push(n->right);
            }
        }
    }
    return count;
}

bool areStructurallyIdentical(binaryTreeNode<int> *root1, binaryTreeNode<int> *root2) {
    if(!root1 && !root2) {
        return 1;
    }
    if(!root1 || !root2) {
        return 0;
    }
    return (root1->data == root2->data && areStructurallyIdentical(root1->left, root2->left) && areStructurallyIdentical(root1->right, root2->right));
}

int totalNumberOfNodes(binaryTreeNode<int> *root) {
    if(!root) { // root == NULL
        return 0;
    }
    return 1 + totalNumberOfNodes(root->left) + totalNumberOfNodes(root->right);
}

binaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE) {
    if(inS > inE) {
        return NULL;
    }
    int rootData = pre[preS];
    int rootIndex = -1;
    for(int i = inS; i <= inE; i++) {
        if(in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }
    int linS = inS;
    int linE = rootIndex - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    int rinS = rootIndex + 1;
    int rinE = inE;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, linS, linE, lpreS, lpreE);
    root->right = buildTreeHelper(in, pre, rinS, rinE, rpreS, rpreE);
    return root;
}

binaryTreeNode<int> *buildTreeUsingInorderAndPreorder(int *in, int *pre, int size) {
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);   
}

void printTree(binaryTreeNode<int> *root) {
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()) {
        binaryTreeNode<int> *n = q.front();
        q.pop();
        cout << n->data << ": ";
        if(n->left && n->right) {
            cout << "Left -> " << n->left->data << " Right -> " << n->right->data;
            q.push(n->left);
            q.push(n->right);
        }
        cout << endl;
    }
}

int countLevelsUsingQueue(binaryTreeNode<int> *root) {
    int level = 0;
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        binaryTreeNode<int> *n = q.front();
        q.pop();
        if(!n) {
            if(!q.empty()) {
                q.push(NULL);
            }
            level++;
        } else {
            if(n->left) {
                q.push(n->left);
            }
            if(n->right) {
                q.push(n->right);
            }
        }
    }
    return level;
}

void calculateHorizontalDistance(binaryTreeNode<int> *root, int horizontalDistance, map<int, vector<int> > &m) {
    if(!root) {
        return;
    }
    m[horizontalDistance].push_back(root->data);
    if(root->left) {
        calculateHorizontalDistance(root->left, horizontalDistance - 1, m);
    }
    if(root->right) {
        calculateHorizontalDistance(root->right, horizontalDistance + 1, m);
    }
}

void verticalOrderTraversal(binaryTreeNode<int> *root) {
    map<int, vector<int> > m;
    int horizontalDistance = 0;
    calculateHorizontalDistance(root, horizontalDistance, m);
    for(map<int, vector<int > >::iterator it = m.begin(); it != m.end(); it++) {
        for(int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
} 

void zigZagTraversal(binaryTreeNode<int> *root) {
    bool leftToRight = true;
    if(!root) {
        return;
    }
    stack<binaryTreeNode<int> *> currentLevel, nextLevel;
    currentLevel.push(root);
    while(!currentLevel.empty()) {
        binaryTreeNode<int> *node = currentLevel.top();
        currentLevel.pop();
        if(node) {
            cout << node->data << " ";
            if(leftToRight) {
                if(node->left) {
                    nextLevel.push(node->left);
                }
                if(node->right) {
                    nextLevel.push(node->right);
                }
            } else {
                if(node->right) {
                    nextLevel.push(node->right);
                }
                if(node->left) {
                    nextLevel.push(node->left);
                }
            }
        }
        if(currentLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

void calculateHorizontalDistance(binaryTreeNode<int> *root, int horizontalDistance, map<int, int> &m) {
    if (!root) {
        return;
    }
    if(horizontalDistance <= 0) {
        if (m.find(horizontalDistance) == m.end()) {
            m[horizontalDistance] = root->data;
        }
    }
    if (horizontalDistance == 0 || horizontalDistance < 0) {
        calculateHorizontalDistance(root->left, horizontalDistance - 1, m);
    }
    if (horizontalDistance == 0 || horizontalDistance > 0) {
        calculateHorizontalDistance(root->right, horizontalDistance + 1, m);
    }
    if(horizontalDistance > 0) {
        m[horizontalDistance] = root->data;
    }
}

void topView(binaryTreeNode<int> *root) {
    if(!root) {
        return;
    }
    map<int, int> m;
    int horizontalDistance = 0;
    calculateHorizontalDistance(root, horizontalDistance, m);
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->second << " ";
    }
}

void bottomView(binaryTreeNode<int> *root) {
    if(!root) {
        return;
    }
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    int hd = 0;
    map<int, int> m;
    root->horizontalDistance = hd;
    while(!q.empty()) {
        binaryTreeNode<int> *node = q.front();
        q.pop();
        hd = node->horizontalDistance;
        m[hd] = node->data;
        if(node->left) {
            node->left->horizontalDistance = hd - 1;
            q.push(node->left);
        }
        if(node->right) {
            node->right->horizontalDistance = hd + 1;
            q.push(node->right);
        }
    }
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->second << " ";
    }
}

void leftView(binaryTreeNode<int> *root) {
    if(!root) {
        return;
    }
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    map<int, int> m;
    while(!q.empty()) {
        binaryTreeNode<int> *node = q.front();
        q.pop();
        if(!node) {
            if(!q.empty()) {
                q.push(NULL);
            }
            level++;
        } else {
            if(m.count(level) == 0) {
                m[level] = node->data;
            }
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
    }
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->second << " ";
    }
}

void rightView(binaryTreeNode<int> *root) {
    if(!root) {
        return;
    }
    queue<binaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    map<int, int> m;
    while(!q.empty()) {
        binaryTreeNode<int> *node = q.front();
        q.pop();
        if(!node) {
            if(!q.empty()) {
                q.push(NULL);
            }
            level++;
        } else {
            m[level] = node->data;
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
    }
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->second << " ";
    }
}

void calDistanceForDiagonalView(binaryTreeNode<int> *root, map<int, vector<int>> &m, int dist) {
    if(!root) {
        return;
    }
    m[dist].push_back(root->data);
    calDistanceForDiagonalView(root->left, m, dist + 1);
    calDistanceForDiagonalView(root->right, m, dist);
}

void diagonalView(binaryTreeNode<int> *root) {
    map<int, vector<int>> m;
    calDistanceForDiagonalView(root, m, 0);
    for(map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
        for(int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " "; 
        }
        cout << "\n";
    }
}

// Basic Approach O(n + heightOfBinaryTree)
int diameterOfBinaryTree(binaryTreeNode<int> *root) {
    if(!root) {
        return 0;
    }
    int option1 = heightOfBinaryTree(root->left) + heightOfBinaryTree(root->right);
    int option2 = diameterOfBinaryTree(root->left);
    int option3 = diameterOfBinaryTree(root->right);
    return max(option1, max(option2, option3));
}

// Better Approach O(n)
pair<int, int> heightDiameter(binaryTreeNode<int> *root) {
    if(!root) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int main() {
    /*
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    binaryTreeNode<int> *root = buildTreeUsingInorderAndPreorder(in, pre, 9);
    cout << countLevelsUsingQueue(root) << endl;
    */
    
    // binaryTreeNode<int> *root = buildTree();
    binaryTreeNode<int> *root = takeInputLevelWise();

    // /* Height and Diameter
    pair<int, int> p = heightDiameter(root);
    cout << "\nHeight: " << p.first << "\nDiameter: " << p.second << "\n";
    // */

    /* Views
    diagonalView(root);
    topView(root);
    bottomView(root);
    leftView(root);
    rightView(root);
    zigZagTraversal(root);
    verticalOrderTraversal(root);
    printTree(root);
    */

    // cout << numberOfLeafbinaryTreeNodes(root);
    // cout << findMaximum(root) << "\n" << findMinimum(root);
    // cout << findElementUsingQueue(root, 10);
    // printKthLevel(root, 3);
    // cout << "\nThe height of tree is: " << heightOfTree(root) << "\n";
    
    /* Traversals
    levelOrderTraversal(root);
    levelOrderTraversalUsingQueue(root);
    cout << "Pre-order:\n";
    preOrderTraversal(root);
    cout << "\nIn-order:\n";
    inOrderTraversal(root);
    cout << "\nPost-order:\n";
    postOrderTraversal(root);
    cout << "\n";
    */
    delete root;
    return 0;
}


// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

// 1 2 4 5 -1 -1 -1 -1 3 6 7 -1 8 -1 -1 9 -1