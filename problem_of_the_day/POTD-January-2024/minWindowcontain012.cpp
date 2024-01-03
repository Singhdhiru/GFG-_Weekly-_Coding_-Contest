#include <iostream>
#include <climits>

using namespace std;

int smallestSubstring(string S) {
    int o = -1; //1
    int j = -1; // 2 
    int k = -1; //0
    int ans = INT_MAX;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '1') {
            o = i;
        } else if (S[i] == '2') {
            j = i;
        } else {
            k = i;
        }

        if (o != -1 && j != -1 && k != -1) {
            int maxi = max(o, max(j, k));
            int mini = min(o, min(j, k));
            ans = min(ans, maxi - mini + 1);
        }
    }
    if (ans == INT_MAX) {
        return -1;
    }
    return ans;
}

int main() {
    // Example usage:
    string inputString = "120210";
    int result = smallestSubstring(inputString);
    cout << "The length of the smallest substring containing all three characters is: " << result << endl;

    return 0;
}
