#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &nums, int n)
{
    for (auto it : nums)
    {
        cout << it << " ";
    }
}
// BETTER - Sorting 0s,1s,2s
// vector<int> sort0s1s2s(vector<int>&nums){
//     int n = nums.size();
//     int ctr0 = 0, ctr1 = 0, ctr2 = 0;
//     for(int i = 0; i< n; i++){
//         if(nums[i] == 0)
//             ctr0++;
//         else if(nums[i] == 1)
//             ctr1++;
//         else
//             ctr2++;
//     }
//     for(int i=0; i<ctr0; i++){
//         nums[i] = 0;
//     }
//     for (int i = ctr0; i < ctr0+ctr1; i++){
//         nums[i] = 1;
//     }
//     for (int i = ctr0+ctr1; i < ctr0+ctr1+ctr2; i++){
//         nums[i] = 2;
//     }
//     return nums;
// }
// OPTIMAL - Sorting 0s,1s,2s

// void sortedArray(vector<int>&nums, int n){
//     int low = 0, mid = 0, high = n-1;
//     while(mid<=high){
//         if(nums[mid] == 0){
//             swap(nums[mid],nums[low]);
//             mid++;
//             low++;
//         }
//         else if(nums[mid] == 1){
//             mid++;
//         }
//         else{
//             swap(nums[mid],nums[high]);
//             high--;
//         }
//     }
// }

// BETTER - MAJORITY ELEMENTS;
// int majorityELements(vector <int> nums){
//     map<int,int>mpp;
//     for(int i = 0; i < nums.size(); i++){
//         mpp[nums[i]]++;
//     }
//     for(auto it : mpp){
//         if(it.second > nums.size()/2){
//             return it.first;
//         }
//     }
//     return -1;
// }
// OPTIMAL - MAJORITY ELEMENTS;

// int majorityElement(vector<int>&nums){
// int ctr = 0, el;
// for(int i = 0; i<nums.size(); i++){
//     if(ctr == 0){
//         el = nums[i];
//         ctr++;
//     }
//     else if(nums[i] == el){
//         ctr++;
//     }
//     else{
//         ctr--;
//     }
// }
// int ctr2 = 0;
// for(int i =0; i<nums.size(); i++){
//     if(el == nums[i]){
//         ctr2++;
//     }
// }
// if(ctr2 > nums.size()/2){
//     return el;
// }
// return -1;

// }

// OPTIMAL - Maximum SunArray Sum;
// int maxSubArraySum(vector<int> nums){
//     int sum = 0;
//     int maxi = INT_MIN;
//     int start = 0, arrstart = 0, arrend = 0;
//     for(int i = 0; i< nums.size() ; i++){
//         if(sum == 0) start = i;
//         sum += nums[i];
//         if(sum > maxi){
//             maxi = sum;
//             arrstart = start;
//             arrend = i;
//         }
//         if(sum < 0){
//             sum = 0;
//         }
//     }
//     cout << "Maximum Subarray: ";
//     for (int i = arrstart; i <= arrend; i++)
//     {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
//     return maxi;
// }

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &it : nums)
    {
        cin >> it;
    }

    printArray(nums, n);
    cout << endl;
    // BETTER - Sorting 0s,1s,2s
    // sort0s1s2s(nums);
    // for(auto it : nums){
    //     cout<< it<<" ";
    // }
    // OPTIMAL - Sorting 0s,1s,2s
    // sortedArray(nums, n);
    // printArray(nums, n);
    // BETTER - MAJORITY ELEMENTS;
    // cout<< majorityELements(nums);
    // OPTIMAL - MAJORITY ELEMENTS;
    // cout<< majorityElement(nums);
    // OPTIMAL - Maximum SunArray Sum;
    // cout << maxSubArraySum(nums);
}