// //? Mean BST

// Geek has a list of integers and a value key. He is trying to find the mean of 

// the element just less than or equal to the given key and
// the element just greater than or equal to the given key
// If either of them does not exist, take the value as -1. Both the values may even be the same.  
// He has recently discovered the concept of Binary Search Tree. He is curious to see if he can use BST to solve this problem. Can you help him?
// The mean of two numbers x and y is defined as ceil((x+y)/2).
// For example,
// if the numbers are 2 and 3 then mean is ceil(5/2) = ceil(2.5) = 3.
// Here ceil(x) denotes the smallest integer that is not smaller than x.
// Example 1:
// Input:
//      3
//     /  \
//    1    5
// key = 2
// Output: 2
// Explaination : 
// Here 1 is just less than 2 and
// 3 is just greater than 2. 
// Required mean is (1+3)/2 = 2.


#include <iostream>

using namespace std; // Using the std namespace

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    void inorder(Node* root, int& l, int& m, int& ok, int key) {
        if (!root) {
            return;
        }

        inorder(root->left, l, m, ok, key);
        int data = root->data;
        if (data <= key) {
            l = data;
        }
        if (ok && data >= key) {
            m = data;
            ok = 0;
        }

        inorder(root->right, l, m, ok, key);
    }

    int mean(Node* root, int key) {
        int ok = 1; // ok ka work hi key se just ak grater chahiye 
        int lessThanKey = -1;
        int greaterThanKey = -1;
        inorder(root, lessThanKey, greaterThanKey, ok, key);
        return (lessThanKey + greaterThanKey + 1) / 2;
    }
};

int main() {
    // Create your binary search tree here
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);

    Solution solution;
    int key = 4; // Change this value to the desired key
    int result = solution.mean(root, key);
    cout << "Mean: " << result << endl;

    return 0;
}
