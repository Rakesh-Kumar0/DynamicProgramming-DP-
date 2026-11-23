#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// recurssion function
int fun(int i, int j, vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    // base case
    if(j<0 || j>=m) return -1e9; // because we have find maximum so -1e9
    if(i == 0) return matrix[0][j];
    int up = matrix[i][j] + fun(i-1,j,matrix);
    int leftDiagonal = matrix[i][j] + fun(i-1,j-1,matrix);
    int rightDiagonal = matrix[i][j] + fun(i-1,j+1,matrix);
    return max(up, max(leftDiagonal, rightDiagonal));
}
// calling function
int maximumPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e9;
    // for all cell of the last row
    for(int j=0; j<m; j++){
        maxi = max(maxi, fun(n-1,j,matrix));
    }
    return maxi;
}

int main(){
    int n,m;
    cout<<"Enter n0. of row and no. of cols : ";
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    int result = maximumPathSum(matrix);
    cout<<result;
    return 0;
}