#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
// recurssion function
int fun(int i, int j, vector<vector<int>> &triangle){
    int n = triangle.size();
    // base case
    if(i == n-1) return triangle[n-1][j];
    int down = triangle[i][j] + fun(i+1,j,triangle);
    int diagonal = triangle[i][j] + fun(i+1,j+1,triangle);
    return min(down, diagonal);
}

// calling function
int minimumPathSum(vector<vector<int>> &triangle, int n){
    return fun(0,0,triangle);
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