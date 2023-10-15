#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void inorder(Node* root, vector<Node*>& in) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, in);
    in.push_back(root);
    inorder(root->right, in);
}

int median(Node* node, int k) {
    vector<Node*> inorderStore;
    inorder(node, inorderStore);
    Node* x = inorderStore[k - 1];

    vector<Node*> inorderStoreX; // Create a new vector to store the in-order traversal of node x.
    inorder(x, inorderStoreX);

    int ans = 0;
    int l = inorderStoreX.size();

    if (l % 2 == 0) {
        ans = (inorderStoreX[l / 2]->data + inorderStoreX[(l / 2) - 1]->data) / 2;
    } else {
        ans = inorderStoreX[l / 2]->data;
    }

    return ans;
}

int main() {
    // Sample usage of the median function
    Node* root = new Node{3, new Node{1, nullptr, nullptr}, new Node{5, nullptr, nullptr}};
    int k = 2; // Find the median of the 2nd element in the in-order traversal.
    int result = median(root, k);
    cout << "Median: " << result << endl;

    return 0;
}
