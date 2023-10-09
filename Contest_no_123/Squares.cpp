#include <iostream>

int squares(int N, int X) {
    long side = (1 << N);
    long total = (side * side);
    // If X is greater than the total number of squares, it's not possible.
    if (X > total) {
        return -1;
    }
    
    X--;
    int ans = (X / 3);
    if (X % 3 != 0) {
        ans++;
    }
    return ans;
}

int main() {
    int N = 4; // Replace with your desired value of N
    int X = 5; // Replace with your desired value of X
    
    int result = squares(N, X);
    
    if (result == -1) {
        std::cout << "It's not possible to create square " << X << " in a grid of size 2^" << N << " x 2^" << N << ".\n";
    } else {
        std::cout << "Square " << X << " is in row " << result << " of the grid.\n";
    }
    
    return 0;
}
