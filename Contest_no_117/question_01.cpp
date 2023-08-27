// Silver and Gold
// There are N coins kept in a line. Each coin has two sides - one is colored gold and the other silver. You can flip two adjacent coins any number of times. You need to make the gold-colored side of every coin facing up. You are given the initial status of coins in a binary string s where '1' represents the gold side facing up and '0' represents the silver side facing up. If it is possible to make the gold-colored side of every coin facing up, return "Yes", otherwise return "No".
// Example 1:
// Input:
// N = 8, s = "11001100"
// Output:
// Yes
// Explanation:
// Flipping 3rd and 4th coin together and 7th
// and 8th coin together will do the task.

#include <iostream>
using namespace std;

class Solution
{
public:
    string flipCoins(int N, string s)
    {
        int count = 0;

        for (auto it : s)
        {
            if (it == '0')
            {
                count++;
            }
        }

        if (count % 2 != 0)
        {
            return "No";
        }
        return "Yes";
    }
};

int main()
{
    int N;
    string s;

    cout << "Enter the length of the string: ";
    cin >> N;

    cout << "Enter the string: ";
    cin >> s;

    Solution solution;
    string result = solution.flipCoins(N, s);

    cout << "Result: " << result << endl;

    return 0;
}
