#include <iostream>

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}*head;

class Solution {
public:
    Node* pairWiseSwap(struct Node* head) {
        Node* a = head, *b, *c;
        Node* prev = NULL;
        while (a && a->next) {
            b = a->next;
            c = b->next;
            if (a == head) {
                head = b;
            } else {
                if (prev != NULL)
                    prev->next = b;
                b->next = a;
                a->next = c;
                prev = a;
                a = c;
            }
        }
        return head;
    }
};

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Create a sample linked list
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original List: ";
    printList(head);

    head = solution.pairWiseSwap(head);

    std::cout << "After Pairwise Swap: ";
    printList(head);

    return 0;
}
