#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;
// function. using recurssion
// int maximumNonAdjacentSum(int idx, vector<int> &arr){
//     // base case
//     if(idx == 0) return arr[idx];
//     if(idx < 0) return 0;
//     int pick = arr[idx] + maximumNonAdjacentSum(idx-2,arr);
//     int notpick = 0 + maximumNonAdjacentSum(idx-1,arr);
//     return max(pick, notpick);
// }

// function. using memoization
// int maximumNonAdjacentSum(int idx, vector<int> &arr,vector<int> &dp){
//     // base case
//     if(idx == 0) return arr[idx];
//     if(idx < 0) return 0;
//     if(dp[idx] != -1) return dp[idx];
//     int pick = arr[idx] + maximumNonAdjacentSum(idx-2,arr,dp);
//     int notpick = 0 + maximumNonAdjacentSum(idx-1,arr,dp);
//     return dp[idx] = max(pick, notpick);
// }

// function. using tabulation
int maximumNonAdjacentSum(int idx, vector<int> &arr,vector<int> &dp){
    // base case
    dp[0] = arr[0];
    int negative = 0;
    for(int i=1; i<=idx; i++){
        int pick = arr[i];
        if(i>1) pick += dp[i-2]; 
        int notpick = 0 + dp[i-1];
        dp[i] = max(pick, notpick);

    }
    return dp[idx];
    
}


int main(){
    int n;
    cout<<"Enter number of elements in array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> dp(n+1,-1);
    int result = maximumNonAdjacentSum(n-1,arr,dp);
    cout<<result;
    return 0;
}
