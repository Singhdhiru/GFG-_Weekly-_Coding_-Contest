#include <iostream>

class Solution
{
public:
    long long int totalWays(int N)
    {
        long long int ans = 1;
        for (int i = 1; i <= N; i++)
        {
            ans *= i;
        }
        return ans;
    }
};
//  lest 3 day and 3 gf ->>> total 6ways to meet them 
int main()
{
    int N;
    std::cout << "Enter a number N: ";
    std::cin >> N;

    Solution solution;
    long long int result = solution.totalWays(N);

    std::cout << "The factorial of " << N << " is: " << result << std::endl;

    return 0;
}
