#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}
void printMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        cout << "[";
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }
}
bool linearSearch(vector<int> nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            return true;
        }
    }
    return false;
}
// BruteForce- TC- N*N
int LongestConsecutive1(vector<int> nums)
{
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        int cnt = 1;
        while (linearSearch(nums, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }
        maxi = max(maxi, cnt);
    }
    return maxi;
}

int LongestConsecutive2(vector<int> nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ctrCurr = 0, lastSmaller = INT_MIN, longest = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] - 1 == lastSmaller)
        {
            ctrCurr = ctrCurr + 1;
            lastSmaller = nums[i];
        }
        else if (nums[i] != lastSmaller)
        {
            ctrCurr = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, ctrCurr);
    }
    return longest;
}

int LongestConsecutive3(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

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
    printVector(nums);
    cout << endl;
    // cout << LongestConsecutive(nums);
    // cout << LongestConsecutive2(nums);
    cout << LongestConsecutive3(nums);
}