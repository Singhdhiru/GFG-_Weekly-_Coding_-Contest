#include <iostream>
#include <vector>

using namespace std;

long long minOperations(vector<int> A, int N) {
    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        if (sum < 0) {
            ans = max(ans, abs(sum));
        }
    }
    return ans;
}

int main() {
    // Example usage of the minOperations function
    vector<int> A = {1, -2, 3, -4, 5};
    int N = A.size();

    long long result = minOperations(A, N);
    cout << "Minimum operations: " << result << endl;

    return 0;
}
