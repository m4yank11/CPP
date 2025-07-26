#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void display(Node* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
// int x = 1;
// void NthLevel(Node* root, int l){
//     if(root == NULL) return;
//     if(x == l){
//         cout<<root->val<<" ";
//         x--;
//         return;
//     }
//     if(root->left){
//         x++;
//         NthLevel(root->left, l);
//     }
    
//     if(root->right){
//         x++;
//         NthLevel(root->right, l);
//     }
//     x--;
// }

// more readable code

void NthLevel(Node* root, int currentLevel, int targetLevel) {
    if (root == NULL) return; // Base case: If the node is null, return.

    if (currentLevel == targetLevel) { 
        // If we are at the target level, print the node's value.
        cout << root->val << " ";
        return;
    }

    // Recursively traverse the left and right subtrees with an incremented level.
    NthLevel(root->left, currentLevel + 1, targetLevel);
    NthLevel(root->right, currentLevel + 1, targetLevel);
}

int main(){
    Node* a = new Node(1); //root
    Node* b = new Node(7);
    Node* c = new Node(9);
    Node* d = new Node(2);
    Node* e = new Node(6);
    Node* g = new Node(9);
    Node* h = new Node(5);
    Node* i = new Node(11);
    Node* j = new Node(5);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = g;
    e->left = h;
    e->right = i;
    g->left = j;


    display(a);
    cout<<endl;
    NthLevel(a, 1, 3);

    return 0;
}