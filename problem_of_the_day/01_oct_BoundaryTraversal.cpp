// Boundary traversal of matrix
// You are given a matrix of dimensions n x m. The task is to perform boundary traversal on the matrix in a clockwise manner.
// Example 1:
// Input:
// n = 4, m = 4
// matrix[][] = {{1, 2, 3, 4},
//          {5, 6, 7, 8},
//          {9, 10, 11, 12},
//          {13, 14, 15,16}}
// Output: 1 2 3 4 8 12 16 15 14 13 9 5
// Explanation:
// The matrix is:
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// The boundary traversal is:
// 1 2 3 4 8 12 16 15 14 13 9 5

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function to return list of integers that form the boundary
    // traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m)
    {
        vector<int> v;
        if (n == 1)
        {
            for (int i = 0; i < m; i++)
            {
                v.push_back(matrix[n - 1][i]);
            }
            return v;
        }
        else if (m == 1)
        {
            for (int i = 0; i < n; i++)
            {
                v.push_back(matrix[i][m - 1]);
            }
            return v;
        }
        else
        {
            int left = 0;
            int right = m - 1;
            int top = 0;
            int bottom = n - 1;

            while (left <= right && top <= bottom)
            {
                // Traverse top row
                for (int col = left; col <= right; col++)
                {
                    v.push_back(matrix[top][col]);
                }
                top++;

                // Traverse rightmost column
                for (int row = top; row <= bottom; row++)
                {
                    v.push_back(matrix[row][right]);
                }
                right--;

                // Traverse bottom row
                if (top <= bottom)
                {
                    for (int col = right; col >= left; col--)
                    {
                        v.push_back(matrix[bottom][col]);
                    }
                    bottom--;
                }

                // Traverse leftmost column
                if (left <= right)
                {
                    for (int row = bottom; row >= top; row--)
                    {
                        v.push_back(matrix[row][left]);
                    }
                    left++;
                }
            }

            return v;
        }
    }
};

int main()
{
    Solution solution;

    // Example usage:
    int n = 4, m = 4;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    vector<int> result = solution.boundaryTraversal(matrix, n, m);

    // Print the result
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
