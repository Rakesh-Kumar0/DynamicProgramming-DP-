#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// function to solve using recurssion
// int frogJump(int idx, vector<int> &height){
//     // base case
//     if(idx == 0) return 0;
//     int right = INT_MAX; // when we can't jump 2 index

//     int left  = frogJump(idx-1,height) + abs(height[idx] - height[idx-1]);
//     if(idx > 1) right = frogJump(idx-2,height) + abs(height[idx] - height[idx-2]); 
//     return min(left , right);
// }

// function to solve using dp
int frogJump(int idx, vector<int> &height, vector<int> &dp){
    if(idx == 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    int right = INT_MAX;
    int left = frogJump(idx-1,height,dp) + abs(height[idx] - height[idx-1]);
    if(idx>1) right = frogJump(idx-2, height, dp) + abs(height[idx] - height[idx-2]);
    return dp[idx] = min(left,right);
}
int main(){
    int n;
    cout<<"Enter no. of elements in height : ";
    cin>>n;
    vector<int> height(n);
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    vector<int> dp(n+1,-1);
    int result = frogJump(n-1,height,dp);
    cout<<result;
    return 0;
}