#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order input
Node* buildTree(const vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == -1) return nullptr;

    queue<Node*> q;
    Node* root = new Node(levelOrder[0]);
    q.push(root);
    int i = 1;

    while (!q.empty() && i < levelOrder.size()) {
        Node* curr = q.front();
        q.pop();

        if (levelOrder[i] != -1) {
            curr->left = new Node(levelOrder[i]);
            q.push(curr->left);
        }
        i++;

        if (i < levelOrder.size() && levelOrder[i] != -1) {
            curr->right = new Node(levelOrder[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Function to perform all three traversals in a single pass
vector<vector<int>> preInPostTraversal(Node* root) {
    vector<int> pre, in, post;
    if (root == NULL) return {};

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();  // Copy the top element
        st.pop();

        if (it.second == 1) {  // Preorder
            pre.push_back(it.first->val);
            it.second = 2;
            st.push(it);  // Push updated pair back
            if (it.first->left) st.push({it.first->left, 1});
        }
        else if (it.second == 2) {  // Inorder
            in.push_back(it.first->val);
            it.second = 3;
            st.push(it);  // Push updated pair back
            if (it.first->right) st.push({it.first->right, 1});
        }
        else {  // Postorder
            post.push_back(it.first->val);
        }
    }

    return {pre, in, post};
}

// Function to print a vector
void printVector(const string& title, const vector<int>& vec) {
    cout << title << ": ";
    for (int val : vec) cout << val << " ";
    cout << endl;
}

// Driver code
int main() {
    vector<int> levelOrder = {1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9, -1};  // Given level order

    Node* root = buildTree(levelOrder);
    vector<vector<int>> traversals = preInPostTraversal(root);

    printVector("Preorder", traversals[0]);
    printVector("Inorder", traversals[1]);
    printVector("Postorder", traversals[2]);

    return 0;
}