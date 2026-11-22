#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

// recurssion function
int fun(int i, int j){
    // base case
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    int up = fun(i-1,j);
    int left = fun(i, j-1);
    return up + left;
}

int uniquePaths(int n, int m){
    return fun(n-1, m-1);
}

int main(){
    int m,n;
    cout<<"Enter no. of rows and no. of cols : ";
    cin>>n>>m;
    int result = uniquePaths(n,m);
    cout<<result;
    return 0;
}