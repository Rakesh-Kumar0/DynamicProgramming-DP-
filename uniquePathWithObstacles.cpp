#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

// recurssion function
int fun(int i, int j, vector<vector<int>> &obstacleGrid){
    // base case
    if(i >=0 && j>=0 && obstacleGrid[i][j] == 1 ) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    int up = fun(i-1,j,obstacleGrid);
    int left = fun(i, j-1,obstacleGrid);
    return up + left;
}

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
// int fun(int n, int m, vector<vector<int>> &dp){
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(i == 0 && j == 0) dp[i][j] = 1;
//             else{
//                 int up = 0;
//                 int left = 0;
//                 if(i>0)  up = dp[i-1][j];
//                 if(j>0)  left = dp[i][j-1];
//                 dp[i][j] = up + left;
//             }
//         }
//     }
//     return dp[n-1][m-1];
// }

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid){
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fun(n-1, m-1,obstacleGrid);
}

int main(){
    int m,n;
    cout<<"Enter no. of rows and no. of cols : ";
    cin>>n>>m;
    vector<vector<int>> obstacleGrid(n, vector<int>(m));
    cout<<"Enter elements in 0 and 1 only : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>obstacleGrid[i][j];
        }
    }
    int result = uniquePathsWithObstacles(obstacleGrid);
    cout<<result;
    return 0;
}