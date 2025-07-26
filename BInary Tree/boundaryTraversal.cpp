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

int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

void levelOrder(Node* root){
    int n = levels(root);
    for(int i = 1 ; i <= n ; i++){
        NthLevel(root, 1 , i);
        cout<<endl;
    }
}

void levelOrderqueue(Node* root){
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

Node* createTree(int v[], int n){
    Node* root = new Node(v[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1, j = 2;
    while(!q.empty() && j < n){
        Node* temp = q.front();
        q.pop();
        if ( v[i] != INT_MIN) {
            temp->left = new Node(v[i]);
            q.push(temp->left);
        } else {
            temp->left = NULL;
        }

        // Process right child
        if ( v[j] != INT_MIN) {
            temp->right = new Node(v[j]);
            q.push(temp->right);
        } else {
            temp->right = NULL;
        }
        i += 2;
        j += 2;
    }
    return root;
}

// left boundary
void leftBoundary(Node* root){
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL) return ;
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left == NULL) leftBoundary(root->right);
}

// bottom boundary
void bottom(Node* root){
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL) cout<<root->val<<" ";
    bottom(root->left);
    bottom(root->right);
}

// right boundary
void rightBoundary(Node* root){
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL) return;
    rightBoundary(root->right);
    if(root->right == NULL) rightBoundary(root->left);
    cout<<root->val<<" ";
}

// complete function
void boundaryTraversal(Node* root){
    leftBoundary(root);
    bottom(root);
    rightBoundary(root->right);
}

int main(){
    // construct the tree using bfs
    int a[] = {1,2,3,4,5, INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    int n = sizeof(a)/sizeof(a[0]);
    
    Node* root = createTree(a,n);
    boundaryTraversal(root);
    return 0;
}