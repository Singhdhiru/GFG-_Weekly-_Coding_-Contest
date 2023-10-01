// Boolean Matrix
// Given a boolean matrix of size RxC where each cell contains either 0 or 1, modify it such that if a matrix cell matrix[i][j] is 1 then all the cells in its ith row and jth column will become 1.
// Example 1:
// Input:
// R = 2, C = 2
// matrix[][] = {{1, 0},
//               {0, 0}}
// Output:
// 1 1
// 1 0
// Explanation:
// Only cell that has 1 is at (0,0) so all
// cells in row 0 are modified to 1 and all
// cells in column 0 are modified to 1.
// Example 2:
// Input:
// R = 4, C = 3
// matrix[][] = {{ 1, 0, 0},
//               { 1, 0, 0},
//               { 1, 0, 0},
//               { 0, 0, 0}}
// Output:
// 1 1 1
// 1 1 1
// 1 1 1
// 1 0 0
// Explanation:
// The position of cells that have 1 in
// the original matrix are (0,0), (1,0)
// and (2,0). Therefore, all cells in row
// 0,1,2 are and column 0 are modified to 1.
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int row[n], col[m];
        for (int i = 0; i < n; i++)
        {
            row[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            col[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                { // agar mat mai 1 ho toh 2 array banaye hi waha jakr 0 ko 1 se replace kar denge
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] || col[j])
                { // finally mai matrix mai merge kr denge
                    matrix[i][j] = 1;
                }
            }
        }
    }
};

int main()
{
    Solution solution;

    // Example matrix
    vector<vector<int>> matrix = {
        {1, 0, 0},
        {0, 0, 1},
        {0, 0, 0}};

    cout << "Original Matrix:" << endl;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // Modify the matrix
    solution.booleanMatrix(matrix);

    cout << "Modified Matrix:" << endl;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
