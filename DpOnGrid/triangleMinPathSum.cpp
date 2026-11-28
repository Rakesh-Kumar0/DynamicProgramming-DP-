#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
// recurssion function
// int fun(int i, int j, vector<vector<int>> &triangle){
//     int n = triangle.size();
//     // base case
//     if(i == n-1) return triangle[n-1][j];
//     int down = triangle[i][j] + fun(i+1,j,triangle);
//     int diagonal = triangle[i][j] + fun(i+1,j+1,triangle);
//     return min(down, diagonal);
// }

// memoization function
// int fun(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
//     int n = triangle.size();
//     // base case
//     if(i == n-1) return triangle[n-1][j];
//     if(dp[i][j] != -1) return dp[i][j];
//     int down = triangle[i][j] + fun(i+1,j,triangle,dp);
//     int diagonal = triangle[i][j] + fun(i+1,j+1,triangle,dp);
//     return dp[i][j] = min(down, diagonal);
// }

// tabulation function
int fun(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
    int n = triangle.size();
    // base case
    for(int j=0; j<n; j++) dp[n-1][j] = triangle[n-1][j];
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

// calling function
int minimumPathSum(vector<vector<int>> &triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n,-1));
    return fun(0,0,triangle,dp);
}

int main(){
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    vector<vector<int>> triangle(n);
    for(int i = 0; i < n; i++){
        triangle[i].resize(i + 1);
        for(int j = 0; j <= i; j++){
            cin >> triangle[i][j];
        }
    }
    int result = minimumPathSum(triangle,n);
    cout<<result;
    return 0;
}