#include <iostream>

using namespace std;

template <class T>
class ListNode {
    public:
    T data;
    ListNode<T> *next;
    ListNode(T d) : data(d), next(NULL){} 
};

// Traversing Linked List - Calculating Length
// Iterative Approach
// Time Complexity : O(n)
// Space Complexity : O(1) 
int LengthOfLinkedList(ListNode<int> *head) {
    ListNode<int> *currentNode = head;
    int len = 0;
    while(currentNode) {
        len++;
        currentNode = currentNode->next; 
    }
    return len;
}

// Inserting Node in a Linked List
class InsertNodeInLinkedList {
    public:

    // 1. Add a node at the front: (4 steps process)
    // Time Complexity : O(1)
    // Space Complexity : O(1) 
    void push(ListNode<int> **head, int new_data) {
        // 1. Allocate Node 
        ListNode<int> *newNode;

        // 2. Put in the data
        newNode->data = new_data;

        // 3. Make next of newNode as head
        newNode->next = *head;
        
        // 4. Move the head to point the new node
        *head = newNode;
    }

    // 2. Add a node after a given node: (5 steps process)
    // Time Complexity : O(1)
    // Space Complexity : O(1)
    void insertAfter(ListNode<int> *prevNode, int new_data) {
        // 1. Check if the given prevNode is NULL  
        if (!prevNode) {  
        printf("The given node cannot be NULL");        
        return;
        }   
            
        // 2. Allocate new node
        ListNode<int> *newNode;
    
        // 3. Put in the data
        newNode->data  = new_data; 
    
        // 4. Make next of newNode as next of prevNode
        newNode->next = prevNode->next;  
    
        // 5. Move the next of prevNode as newNode
        prevNode->next = newNode; 
    }

    // 3. Add a node at the end: (6 steps process)
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    void append(ListNode<int> **head, int new_data) {
        // 1. Allocate Node
        ListNode<int> *newNode;
    
        ListNode<int> *last = *head;  // Used in Step 5
    
        // 2. Put in the data
        newNode->data  = new_data; 
    
        // 3. This newNode is going to be the last node, so make next of it as NULL
        newNode->next = NULL; 
    
        // 4. If the Linked List is empty, then make the newNode as head
        if (*head == NULL) { 
        *head = newNode; 
        return; 
        }   
        
        // 5. Else traverse till the last node
        while (last->next != NULL) {
            last = last->next;
        } 
    
        // 6. Change the next of last node
        last->next = newNode; 
        return;  
    }
};



int main() {
    return 0;
}