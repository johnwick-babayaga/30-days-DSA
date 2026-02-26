#include <bits/stdc++.h>
    using namespace std;

void printArray(vector<int>&nums){
        for(auto it : nums){
            cout << it << " ";
        }
    }
int partitionArr(vector<int>&nums, int low, int high){
    int pivot = nums[low];
    int i = low;
    int j = high;
    while(i < j){
        while(nums[i] <= pivot && i <= high-1){
            i++;
        }
        while(nums[j] > pivot && j >= low+1){
            j--;
        }
        if(i < j) swap(nums[i], nums[j]);
    }
    swap(nums[low], nums[j]);
    return j;
}
void quickSort(vector<int>&nums, int low, int high){
    if(low<high){
        int pIndex = partitionArr(nums, low, high);
        quickSort(nums, low, pIndex-1);
        quickSort(nums, pIndex+1, high);
    }
}

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != nums[i])
        {
            cnt1++;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i])
        {
            cnt2++;
            el2 = nums[i];
        }
        else if (el1 == nums[i])
            cnt1++;
        else if (el2 == nums[i])
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (el1 == nums[i])
            cnt1++;
        if (el2 == nums[i])
            cnt2++;
    }
    vector<int> ans;
    int m = (int)n / 3 + 1;
    if (cnt1 >= m)
    {
        ans.push_back(el1);
    }
    if (cnt2 >= m)
    {
        ans.push_back(el2);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int>nums(n);
    for(auto &it : nums){
        cin >> it;
    }
    printArray(nums);
    cout<< endl;

    // quickSort(nums, 0, n-1 );
    // printArray(nums);
    vector<int>res = majorityElement(nums);
    printArray(res);
}