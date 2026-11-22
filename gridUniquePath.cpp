#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

// recurssion function
// int fun(int i, int j){
//     // base case
//     if(i == 0 && j == 0) return 1;
//     if(i < 0 || j < 0) return 0;
//     int up = fun(i-1,j);
//     int left = fun(i, j-1);
//     return up + left;
// }

// memoization function
// int fun(int i, int j, vector<vector<int>> &dp){
//     // base case
//     if(i == 0 && j == 0) return 1;
//     if(i < 0 || j < 0) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     int up = fun(i-1,j,dp);
//     int left = fun(i, j-1,dp);
//     return dp[i][j] = up + left;
// }

// tabuation function
int fun(int n, int m, vector<vector<int>> &dp){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0 && j == 0) dp[i][j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i>0)  up = dp[i-1][j];
                if(j>0)  left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n-1][m-1];
}

int uniquePaths(int n, int m){
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fun(n, m,dp);
}

int main(){
    int m,n;
    cout<<"Enter no. of rows and no. of cols : ";
    cin>>n>>m;
    int result = uniquePaths(n,m);
    cout<<result;
    return 0;
}