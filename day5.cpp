#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}
// MAX PROFIT ON STOCKS
int maxProfitInStocks(vector<int> nums)
{
    int mini = nums[0], cost = 0, profit = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        cost = nums[i] - mini;
        profit = max(cost, profit);
        mini = min(mini, nums[i]);
    }
    return profit;
}
// VARIETY-1 : REARRANGE BY SIGN (POS = NEG);
void rearrangeBySignV1(vector<int> &nums)
{
    int pos = 0, neg = 1;
    vector<int> v(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            v[pos] = nums[i];
            pos += 2;
        }
        else
        {
            v[neg] = nums[i];
            neg += 2;
        }
    }
    printArray(v);
}
// VARIETY-2 : REARRANGE BY SIGN (POS != NEG);
void rearrangeBySignV2(vector<int> &nums)
{
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }
    vector<int> ans(nums.size(), 0);
    int n, p;
    if (pos.size() > neg.size())
    {
        n = neg.size();
        p = pos.size();
    }
    else
    {
        n = pos.size();
        p = neg.size();
    }
    for (int i = 0; i < n; i++)
    {
        ans[2 * i] = pos[i];
        ans[2 * i + 1] = neg[i];
    }
    int idx = 2 * n;
    for (int i = n; i < p; i++)
    {
        ans[idx] = pos[i];
        idx++;
    }
    printArray(ans);
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
    printArray(nums);
    cout << endl;

    // cout << maxProfitInStocks(nums);
    // rearrangeBySignV1(nums);
    // rearrangeBySignV2(nums);
}