#include <bits/stdc++.h>
using namespace std;

// OPTIMAL1: FIND MISSING NUMBER using SUM
// int findMissingNumber(vector<int>nums, int n){
// int sum1=n*(n+1)/2, sum2=0;
// for(int i = 0; i < n-1; i++){
//     sum2+=nums[i];
// }
// return sum1 - sum2;
// }

// OPTIMAL2: FIND MISSING NUMBER using XOR
// int findMissingNumber(vector<int> nums, int n){
//     int xor1 = 0, xor2 = 0;
//     for(int i = 0; i< n-1; i++){
//         xor1 = xor1 ^ (i+1);
//         xor2 = xor2 ^ nums[i];
//     }
//     xor1 = xor1 ^ n;
//     return xor1 ^ xor2;
// }

// FIND MAX CONSECUTIVE 1s OPTIMAL
// int maxConsecutiveOnes(vector<int>nums, int n){
//     int ctr = 0, maxi = 0;
//     for(int i=0; i < n; i++){
//         if(nums[i] == 1){
//             ctr = ctr + 1;
//             maxi = max(maxi, ctr);
//         }
//         else{
//             ctr = 0;
//         }
//     }
//     return maxi;
// }

// OPTIMAL: FIND NUMBER WHICH APPEARS ONCE AND OTHERS TWICE
// int appearOnce(vector<int>&nums){
//     int n = nums.size();
//     int xor1 = 0;
//     for(int i = 0; i< n ; i++){
//         xor1 = xor1 ^ nums[i];
//     }
//     return xor1;
// }
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    // FIND MISSING NUMBER
    // cout << findMissingNumber(nums, n);
    // MAX CONSECUTIVE ONES
    // cout << maxConsecutiveOnes(nums, n);
    // FIND NUMBER WHICH APPEARS ONCE AND OTHERS TWICE
    // cout << appearOnce(nums);

    return 0;
}