#include<iostream>
#include<queue>
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

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
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

    cout<<"BFS : ";
    levelOrder(a);

    return 0;
}