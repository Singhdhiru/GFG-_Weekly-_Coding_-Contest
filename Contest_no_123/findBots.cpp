#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool prime(int p) {
    if (p <= 1) {
        return false;
    }
    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> findBots(vector<string> &usernames, int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int m = usernames[i].size(); // size of first username
        int p = 0;
        int count[26] = {0}; // Initialize the count array to zeros
        for (int j = 0; j < m; j++) {
            if (usernames[i][j] >= 'a' && usernames[i][j] <= 'z') {
                if (count[usernames[i][j] - 'a'] == 0) {
                    p++;
                    count[usernames[i][j] - 'a'] = 1;
                }
            }
        }
        if (prime(p)) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> usernames(n);
    for (int i = 0; i < n; i++) {
        cin >> usernames[i];
    }

    vector<int> result = findBots(usernames, n);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
