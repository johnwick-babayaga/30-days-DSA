#include <bits/stdc++.h>
using namespace std;

// void leftRotateK(vector<int> &nums, int n, int k){
//     reverse(nums.begin(),nums.begin()+k);
//     reverse(nums.begin()+k, nums.end());
//     reverse(nums.begin(), nums.end());
// }

// int main(){
//     vector<int>nums;
//     int n;
//     cin >> n;
//     // int k;
//     // cin >> k;
//     // if(k>n){
//     //     k = k%n;
//     // }
//     for(int i=0; i < n; i++){
//         int x;
//         cin >> x ;
//         nums.push_back(x);
//     }
// LEFT ROTATE BY 1 PLACE, O(n), E.S.-> O(1)
// int first = nums[0];
// for(int i = 1; i< n; i++){
//     nums[i-1] = nums[i];
// }
// nums[n - 1] = first;

// LEFT ROTATE BY K PLACE T.C.-> O(n+k), E.S.->O(d)
// vector<int>temp;
// for(int i =0; i<k; i++){
//     temp.push_back(nums[i]);
// }
// for (int i = k; i < n; i++){
//     nums[i - k] = nums[i];
// }
// for (int i = n-k; i < n; i++){
//     nums[i] = temp[i-(n-k)];
// }

// LEFT ROTATE BY K PLACE T.C.-> O(2n), E.S.->O(1)
// leftRotateK(nums, n, k);

// MOVE ZEROS TO END, T.C.-> O(2n), S.C.->O(x);
// vector<int>temp;
// for(int i=0; i<n; i++){
//     if(nums[i] != 0){
//         temp.push_back(nums[i]);
//     }
// }
// for (int i = 0; i < n; i++){
//     nums[i] = temp[i];
//     if(i>=temp.size()){
//         nums[i] = 0;
//     }
// }

// optimal MOVE ZEROS TO END, T.C.-> O(n), S.C.->O(1);
// int j=-1;
// for(int i=0; i< n; i++){
//     if(nums[i] == 0){
//         j = i;
//         break;
//     }
// }
// for(int i = j+1; i < n; i++){
//     if(nums[i] != 0){
//         swap(nums[j],nums[i]);
//         j++;
//     }
// }

// for (int i = 0; i < n; i++)
// {
//     cout << nums[i] << " ";
// }
// }

// UNION OF 2 SORTED ARRAYS-> OPTIMAL
// vector<int>sortedUnionArray(vector<int>a, vector<int>b){
//     vector<int>unionArr;
//     int n1 = a.size();
//     int n2 = b.size();
//     int i = 0;
//     int j = 0;

//     while(i<n1 && j<n2){
//         if(a[i] <= b[j]){
//             if(unionArr.size() == 0 || unionArr.back() != a[i])
//             {
//                 unionArr.push_back(a[i]);
//             }
//             i++;
//         }
//         else{
//             if (unionArr.size() == 0 || unionArr.back() != b[j])
//             {
//                 unionArr.push_back(b[j]);
//             }
//             j++;
//         }
//     }
//     while(i<n1){
//         if (unionArr.size() == 0 || unionArr.back() != a[i])
//         {
//             unionArr.push_back(a[i]);
//         }
//         i++;
//     }
//     while(j<n2){
//         if (unionArr.size() == 0 || unionArr.back() != b[j])
//         {
//             unionArr.push_back(b[j]);
//         }
//         j++;
//     }
//     return unionArr;
// }

// vector<int>intersectionArray(vector<int>&a, vector<int>&b, int m){
//     vector<int>ans;
//     vector<int>vis(m, 0);
//     for(int i = 0; i<a.size(); i++){
//         for(int j=0; j < m; j++){
//             if(a[i] == b[j] && vis[j] == 0){
//                 ans.push_back(a[i]);
//                 vis[j] = 1;
//                 break;
//             }
//             if(b[j] > a[i]) break;
//         }
//     }
//     return ans;
// }

vector<int> intersectionArrayO(vector<int> &a, vector<int> &b, int n, int m)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && i < m)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums1;
    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        nums1.push_back(x);
    }
    vector<int> nums2;
    int n2;
    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        nums2.push_back(x);
    }
    vector<int> result = intersectionArrayO(nums1, nums2, n1, n2);

    for (int x : result)
    {
        cout << x << " ";
    }
}
