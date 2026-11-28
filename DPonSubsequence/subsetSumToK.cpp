#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// recurrence function
// bool fun(int ind, int target, vector<int> &arr){
//     // base case
//     if(target == 0) return true;
//     if(ind == 0) return (arr[0] == target);
//     bool notTake = fun(ind-1, target, arr);
//     bool take = false;
//     if(arr[ind] <= target){
//         take = fun(ind-1, target - arr[ind],arr);
//     }
//     return take | notTake;
// }


// memeoization function
// bool fun(int ind, int target, vector<int> &arr,vector<vector<int>> &dp){
//     // base case
//     if(target == 0) return true;
//     if(ind == 0) return (arr[0] == target);
//     if(dp[ind][target] != -1) return dp[ind][target];
//     bool notTake = fun(ind-1, target, arr,dp);
//     bool take = false;
//     if(arr[ind] <= target){
//         take = fun(ind-1, target - arr[ind],arr,dp);
//     }
//     return dp[ind][target] = take | notTake;
// }

// calling function
// bool subsetSumToK(int n, int k, vector<int> &arr){
//     vector<vector<int>> dp(n,vector<int>(k+1,-1));
//     return fun(n-1,k,arr,dp);
// }

// tabulation function
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    // base case
    for(int i=0; i<n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int ind=1; ind<n; ind++){
        for(int target=1; target<=k; target++){
            bool notTake = dp[ind-1][k];
            bool take = false;
            if(arr[ind] <= target){
                take = dp[ind-1][k - arr[ind]];
            }
            dp[ind][target] = take | notTake;
        }
    }
    return dp[n-1][k];
}
int main(){
    int n;
    cout<<"Enter no. of elements in array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter target value : ";
    cin>>target;
     bool result = subsetSumToK(n, target,arr);
     cout<<result;
    return 0;
}