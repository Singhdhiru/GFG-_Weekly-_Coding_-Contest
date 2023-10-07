#include <iostream>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    // Helper function to reverse a linked list
    void reverse(Node* &head) {
        Node* prev = NULL, *curr = head, *next;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Function to rearrange the linked list by reversing alternate nodes
    void rearrange(struct Node* odd) {
        if (odd->next == NULL) {
            return;
        }
        Node* head1 = odd, *head2 = NULL;
        Node* t1, *t2;
        t1 = head1;
        while (t1 != NULL && t1->next != NULL) {
            if (head2 == NULL) {
                head2 = t1->next;
                t2 = head2;
            }
            else {
                t2->next = t1->next;
                t2 = t1->next;
            }
            t1->next = t1->next->next;
            t1 = t1->next;
        }
        t2->next = NULL;
        reverse(head2);
        // null tak traveser kr ke umse head2 ko add kar denge
        t1 = head1;
        while (t1->next != NULL) {
            t1 = t1->next;
        }
        t1->next = head2;
    }
};

int main() {
    // Create a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create a Solution object and call rearrange function
    Solution solution;
    solution.rearrange(head);

    // Print the modified linked list
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
