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


    }

};

int main(){

}