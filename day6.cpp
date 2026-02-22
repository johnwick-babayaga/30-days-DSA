#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int>&nums){
    int n = nums.size();
    for(int i = 0; i< n; i++){
        cout<<nums[i]<<" ";
    }
}
// OPTIMAL - NEXT PERMUTATION
vector<int> nxtPermutaion(vector<int>&nums){
    int n = nums.size();
    int ind = -1;
    for(int i =n-2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1) {
        reverse(nums.begin(), nums.end());
        return nums;
    }
    for(int  i = n-1; i >= ind; i--){
        if(nums[i] > nums[ind]){
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin()+ind+1,nums.end());
    return nums;
}
// BRUTE FORCE - LEADER ARRAY
vector<int> leaderArray(vector<int>&nums){
    int n = nums.size();
    vector<int>leader;
    for(int i = 0; i< n; i++){
        int flag = 0;
        for(int j = i; j< n; j++){            
            if(nums[j] > nums[i]){
                flag = 1;
                break;
            }            
        }
        if (flag == 0)  leader.push_back(nums[i]);
    }
    return leader;
}
// OPTIMAL - LEADER ARRAY
vector<int> leaderArray2(vector<int>&nums){
    int maxi = INT_MIN;
    vector<int>leader;
    int n = nums.size();
    for(int i =n-1; i>=0; i--){
        if(nums[i] > maxi){
            leader.push_back(nums[i]);            
        }
        // keep track of right maximum
        maxi = max(maxi, nums[i]);        
    }
    return leader;
}

int main(){

    int n;
    cin >> n;
    vector<int>nums;
    for(int i = 0; i< n; i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    printArray(nums);
    cout<<endl;
    // nxtPermutaion(nums);
    // vector<int> leader = leaderArray(nums);
    // printArray(leader);
    // cout << endl;
    // vector<int>leader2 = leaderArray2(nums);
    // printArray(leader2);

    

}