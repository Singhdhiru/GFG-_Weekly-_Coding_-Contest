#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int solve(string s) {
        set<char> st; // Store only unique characters
        for (auto it : s) {
            st.insert(it);
        }
        return st.size()-1; 
    }
};

// 2nd method ->> store unique character using frequency array

int main() {
    Solution solution;
    string inputString = "hello";
    int result = solution.solve(inputString);
    cout << "Number of unique characters: " << result << endl;
    return 0;
}
