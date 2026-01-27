#include <bits/stdc++.h>
using namespace std;

vector<int> printArray(vector<int> nums, int n)
{
    for (auto it : nums)
    {
        cout << it << " ";
    }
    return nums;
}

// BRUTE-FORCE ( LONGEST SUB ARRAY)
// int longestSubArray(vector<int>nums, int l){
//     int len = 0, n = nums.size();
//     for(int i = 0; i< n; i++)
//     {
//         int sum = 0;
//         for(int j = i; j< n; j++){
//             sum+=nums[j];
//             if (sum == l)
//             {
//                 len = max(len, j - i + 1);
//             }
//         }
//     }
//     return len;
// }

// BETTER ( LONGEST SUB ARRAY)
// int longestsubArraySum(vector<int> &nums, int k)
// {
//     map<long long, int> preSumMap;
//     long long sum = 0;
//     int maxLen = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         sum += nums[i];
//         if (sum == k)
//         {
//             maxLen = max(maxLen, i + 1);
//         }
//         long long rem = sum - k;
//         if (preSumMap.find(rem) != preSumMap.end())
//         {
//             int len = i - preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }
//         if (preSumMap.find(sum) == preSumMap.end())
//         {
//             preSumMap[sum] = i;
//         }
//     }
//     return maxLen;
// }
// OPTIMAL ( LONGEST SUB ARRAY)
// int longestSubArray(vector<int> nums, int k){
//     int left = 0, right = 0;
//     long long sum = nums[0];
//     int maxLen = 0;
//     int n = nums.size();
//     while(right < n){
//         while(left <= right && sum > k){
//             sum-=nums[left];
//             left++;
//         }
//         if(sum == k){
//             maxLen = max(maxLen, right - left +1);
//         }
//         right++;
//         if(right < n) sum+=nums[right];
//     }
//     return maxLen;
// }

// //  BETTER- TWO SUM(Variety 2: {indexes})
// vector <int> indexOfTwoSum(vector<int>&nums, int t){
//     int n = nums.size();
//     map<int,int>mpp;
//     for(int i = 0; i<n ; i++){
//         int a = nums[i];
//         int more = t - a;
//         if(mpp.find(more) != mpp.end()){
//             return {mpp[more], i};
//         }
//         mpp[a] = i;
//     }
//     return {0};
// }

// //  OPTIMAL- TWO SUM(Variety 1: {YES/NO})
// string twoSumTarget(vector<int>&nums, int t){
//     int left = 0, right = nums.size()-1;
//     sort(nums.begin(),nums.end());
//     while(left<right){
//         int a = nums[left] + nums[right];
//         if(a == t) {
//             return "YES";
//         }
//         else if(a < t) {
//             left++;
//         }
//         else {
//             right++;
//         }
//     }
//     return "NO";
// }

int main()
{
    int n;
    cin >> n;
    int l;
    cin >> l;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    printArray(nums, n);
    // LONGEST SUB ARRAY
    // cout << endl << longestSubArray(nums, l);
    // TWO SUM
    // vector<int> result = indexOfTwoSum(nums, l);
    // if (!result.empty())
    // {
    //     cout << "Indices: " << result[0] << ", " << result[1] << endl;
    // }
    // else
    // {
    //     cout << "No pair found." << endl;
    // }
    // cout <<endl << twoSumTarget(nums, l);
}