#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BST
{
private:
    Node *root;

    Node *insertHelper(Node *node, int val)
    {
        if (node == nullptr)
        {
            return new Node(val);
        }
        else if (val < node->data)
        {
            node->left = insertHelper(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insertHelper(node->right, val);
        }
        return node;
    }

    bool searchHelper(Node *node, int val)
    {
        if (node == nullptr)
        {
            return false;
        }
        else if (val == node->data)
        {
            return true;
        }
        else if (val < node->data)
        {
            return searchHelper(node->left, val);
        }
        else if (val > node->data)
        {
            return searchHelper(node->right,val);
        }
    }

    void inorderhelper(Node* node){
        if(node==nullptr) return;
        inorderhelper(node->left);
        cout<<node->data<<" ";
        inorderhelper(node->right);
    }

    void preorderHelper(Node* node){
        if(node==nullptr) return;
        cout<<node->data<<" ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void postorderHelper(Node* node){
        if(node==nullptr) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout<<node->data<<" ";
    }

    Node* findMin(Node* node){
        while(node->left!=nullptr){
            node=node->left;
        }
        return node;
    }

    Node* deletionHelper(Node* node,int val){
        if(node==nullptr) return nullptr;
        if(val<node->data){
            node->left=deletionHelper(node->left,val);
        }else if(val>node->data){
            node->right=deletionHelper(node->right,val);
        }else{

            if(node->left==nullptr && node->right==nullptr){
                delete node;
                return nullptr;
            }else if(node->left==nullptr){
                Node* temp=node->right;
                delete node;
                return temp;
            }else if(node->right==nullptr){
                Node* temp=node->left;
                delete node;
                return temp;
            }else{
                Node* temp=findMin(node->right);
                node->data=temp->data;
                node->right=deletionHelper(node->right,temp->data);
            }

        }
        return node;

    }

    public:
    BST(){
        root=nullptr;

    }

    void insert(int val){
        root=insertHelper(root,val);
    }

    bool search(int val){
        return searchHelper(root,val);
    }

    void remove(int val){
        root=deletionHelper(root,val);
    }

    void inorder() {
        inorderhelper(root);
        cout << endl;
    }

    void preorder() {
        preorderHelper(root);
        cout << endl;
    }

    void postorder() {
        postorderHelper(root);
        cout << endl;
    }


};

int main() {
    BST tree;

    // Insert elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal (sorted): ";
    tree.inorder();

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    // Search
    cout << "\nSearching for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Searching for 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;

    // Delete
    cout << "\nDeleting 20..." << endl;
    tree.remove(20);
    cout << "Inorder after deletion: ";
    tree.inorder();

    cout << "\nDeleting 30 (node with one child)..." << endl;
    tree.remove(30);
    cout << "Inorder after deletion: ";
    tree.inorder();

    cout << "\nDeleting 50 (node with two children)..." << endl;
    tree.remove(50);
    cout << "Inorder after deletion: ";
    tree.inorder();

    return 0;
}