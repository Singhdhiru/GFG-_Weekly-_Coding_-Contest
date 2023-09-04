//? Odd Triplets
// Given an array A[ ] of N integers and an integer X. The task is to count all the triplets (i, j, k) where 1 ≤ i ≤ j ≤ k ≤ N which satisfies the below conditions.
// 1. X ≤ j - i and X ≤ k - j.
// 2. A[i], A[j] and A[k] are odd.
// Example 1:
// Input:
// N = 4
// X = 1
// A[] = {1, 2, 3, 3}
// Output: 1
// Explanation: There is only 1 triplet: 
// (i=1, j=3, k=4) which satisfies all 
// conditions.  
// Example 2:
// Input: 
// N = 3
// X = 2
// A[] = {2, 3, 4}
// Output: 0
// Explanation: No such triplet exists.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function countTriplet( ) which takes the an integer N, array A[ ] and an integer X as input parameters and returns the number of triplets which satisfies the all conditions.

// Constraints:
// 1 ≤ X ≤ N ≤ 105
// 1 ≤ A[i] ≤ 105

