// Column name from a given column number
// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on.a
// Example 1:
// Input:
// N = 28
// Output: AB
// Explanation: 1 to 26 are A to Z.
// Then, 27 is AA and 28 = AB.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string colName(long long int n)
{
    string str;
    string str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (n > 0)
    {
        str += str1[(n - 1) % 26];
        n = (n - 1) / 26; // Use integer division here
    }

    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    long long int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive integer." << endl;
    }
    else
    {
        string col = colName(n);
        cout << "Excel Column Name: " << col << endl;
    }

    return 0;
}
