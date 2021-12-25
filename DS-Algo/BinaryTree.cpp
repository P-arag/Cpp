#include<iostream>

using namespace std;

template <typename T>
struct Node {
    T val;
    Node *left=NULL, *right=NULL; // Left and right children of a node
};

template <typename T>
class BinaryTree {
    public:
        Node<T> *root = new Node<T>;
        
        BinaryTree(T root_val) {
            root->val = root_val;
            
            Node<T> *n1 = new Node<T>;
            n1->val = 1;
            root->left = n1;
            Node<T> *n2 = new Node<T>;
            n1->val = 6;
            root->right = n2;
            Node<T> *nn1 = new Node<T>;
            nn1->val = 5;
            n1->left = nn1; 
            Node<T> *nn2 = new Node<T>;
            nn2->val = 2;
            n1->right = nn2;
        }

        void preorder(Node<T> *n) {
            if(n!=NULL) {
                cout << n->val << " l: " << n->left->val << "r :" << n->right->val << endl; 
                preorder(n->left);
                preorder(n->right);
            }
        }
};

int main() {
    BinaryTree<int> tree(4);
    tree.preorder(tree.root); 
}
