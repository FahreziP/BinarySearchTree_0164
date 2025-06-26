#include <iostream>
using namespace std;


class Node
{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    //Constructor for the node Class
    Node()
    {
        leftchild = nullptr; // Initialize left child to null
        rightchild = nullptr; // Initialize right child to null
    }
};

class BinaryTree
{
public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; //Inisialisasi ROOT ke NULL
    }

    void insert()   //membuat fungsi insert
    {
        int x;
        cout << "Masukkan Nilai: ";
        cin >> x;

        // Step 1: Allocate memory for the new node
        Node *newNode = new Node();

        // Step 2: Assign value to the data field of new node
        newNode->info = x;

        // Step 3: Make the left and right child of the new node point ot NULL
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        // Step 4: Locate the node which will be the parent of the node to be inserted
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);

        // Step 5: If parent is Null (Tree is Empty)
        if (parent == nullptr)
        {
            // 5a: Mark the new node as Root
            ROOT = newNode;

            // 5b: Exit
            return;
        }

        // Step 6: if the value in the data field of new node is less than that of parent
        if (x < parent->info)
        {
            // 6a: Make the left child of parent point to the new node
            parent->leftchild = newNode;

            // 6b: Exit
            return;
        }
        // Step 7: if the value in the data field of the new node is greater than that of the parent
        else if (x > parent->info)
        {
            // 7a: Make the right child of parent point to the new node
            parent->rightchild = newNode;

            //7b: Exit
            return;
        }
        
    }


    void search(int element, Node *&parent, Node *&currentNode) //membuat fungsi search node
    {
        // This Function searches the currentNode of the specified Node as well as the current Node of its parent
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info) 
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }


    void inorder(Node *ptr) //membuat fungsi inorder traversal
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        inorder(ptr->leftchild);
        cout << ptr->info << " ";
        inorder(ptr->rightchild);
    }    

    void preorder(Node *ptr) //fungsi preorder
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        cout << ptr->info << " ";
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }    

    void postorder(Node *ptr) //fungsi postorder
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        cout << ptr->info << " ";
    }    

    bool isEmpty()
    {
        // Checks if the tree is empty
        return ROOT == nullptr;
    }
};

int main() {
BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {
            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {
            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}