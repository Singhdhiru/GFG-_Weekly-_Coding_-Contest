// ?Even Sum
// You are given an array A consisting of n positive integers.
// In one operation, you can choose any index i such that 1 <= i <=n and Ai is even, then you can assign Ai = Ai / 2.
// Your task is to make total sum of array even using minimum number of operations (possibly 0) or return -1 if it is not possible.
// Example 1:
// Input:
// N = 5
// A[] = {1, 2, 1, 2, 1}
// Output: 1
// Explanation: Initially sum is 7
// which is odd. Assign A2 = A2/2
// then array becomes 1, 1, 1, 2, 1
// having sum 6 which is even. So total one
// operation is required which is minimum
// possible.
// Example 2:
// Input:
// N = 3
// B[] = {1, 1, 2}
// Output: 0
// Explanation: Sum is even ie 4.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findMin() which takes the array A[], its size N as input parameters and returns the an integer denoting minimum number of operations.
// Constraints:
// 1 <= N <= 105
// 1 <= A[i] <= 109

#include <iostream>
#include <algorithm>

using namespace std; // Add this line

int findMin(int A[], int n)
{
    int total_sum = 0;
    int count;
    int ans = -1;

    // Calculate the total sum and count even and odd integers.
    for (int i = 0; i < n; i++)
    {
        total_sum += A[i];
    }

    // If the total sum is already even, return 0.
    if (total_sum % 2 == 0)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
        {
            count = 0;

            // Make the number odd by dividing by 2 until it's odd.
            while (A[i] % 2 == 0)
            {
                A[i] = A[i] / 2;
                count++;
            }

            if (ans == -1)
            {
                ans = count;
            }
            else
            {
                ans = min(ans, count);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int A[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int minOperations = findMin(A, n);
    cout << "Minimum operations to make sum even: " << minOperations << endl;

    return 0;
}
