#include <iostream>
using namespace std;

class Node {
    public:
        int info;
        Node *leftchild;
        Node *rightchild;

        // constructor for the node class
        Node(){
            leftchild = nullptr; // initialize left child to null
            rightchild = nullptr; // initialize right child to null
        }
};

class BinaryTree{
    public:
    Node *root;

    BinaryTree(){
        root = nullptr; // initialize root to null
    }

    void insert(){
        int x;
        cout << "Masukkan Nilai: ";
        cin >> x;
        
        // step 1: Allocate memory for the new node
        Node *newNode = new Node();

        // step 2: Assign the value to the data field of new node
        newNode->info = x;

        // Step 3: Make the left and right child of new node point as null
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        // Step  4: Locate the node which will be the parent of the node to be inserted
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);

        // Step 5: if parent is NULL (tree is empty)
        if(parent == nullptr){
            // 5a: Mark the new node as root
            root = newNode;

            // 5b: exit
            return;
        }

        // Step 6: if the value in the data field of new node is less than the parent node
        if (x < parent->info){
            // 6a: Make the left child of parent point to new node
            parent->leftchild = newNode;

            // 6b: exit
            return;
        }

        // Step 7: if the value in the data field of new node is greater than that of the parent
        else if(x > parent->info){
            // 7a: Make the right child of parent point to new node
            parent->rightchild = newNode;

            // 7b: exit
            return;
        }
    }

};

int main(){

}