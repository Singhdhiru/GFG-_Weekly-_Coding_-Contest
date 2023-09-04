// ?Delete nodes having greater value on right
// Win from a prize pool of INR 15K and get exciting merch! Register your team for Hack-A-Thon today!
// Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. (Not just immidiate Right , but entire List on the Right)
// Example 1:
// Input:
// LinkedList = 12->15->10->11->5->6->2->3
// Output: 15 11 6 3
// Explanation: Since, 12, 10, 5 and 2 are
// the elements which have greater elements
// on the following nodes. So, after deleting
// them, the linked list would like be 15,
// 11, 6, 3.
// Example 2:
// Input:
// LinkedList = 10->20->30->40->50->60
// Output: 60
// Explanation: All the nodes except the last
// node has a greater value node on its right,
// so all the nodes except the last node must
// be removed.

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *compute(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *temp1 = head;

        while (temp1->next != NULL)
        {
            if (temp1->data < temp1->next->data)
            {
                temp1->data = temp1->next->data;
                Node *temp = temp1->next;
                temp1->next = temp1->next->next;
                delete temp;
            }
            else
            {
                temp1 = temp1->next;
            }
        }

        return head;
    }
};

int main()
{
    // Create a sample linked list
    Node *head = new Node(3);
    head->next = new Node(6);
    head->next->next = new Node(2);
    head->next->next->next = new Node(12);

    Solution solution;
    Node *result = solution.compute(head);

    // Print the modified linked list
    while (result != NULL)
    {
        cout << result->data << " ";
        result = result->next;
    }

    return 0;
}
