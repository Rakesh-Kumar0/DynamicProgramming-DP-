#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

// recurrence function
// int fun(int day, int last, vector<vector<int>> &points){
//     // base case
//     if(day == 0){
//         int maxi = 0;
//         for(int task=0; task<3; task++){
//             if(task != last){
//                 maxi = max(maxi, points[0][task]);
//             }
//         }
//         return maxi;
//     }
//     int maxi = 0;
//     for(int task=0; task<3; task++){
//         if(task != last){
//             int point = points[day][task] + fun(day-1, task, points);
//             maxi = max(maxi,point);

//         }
//     }
//     return maxi;
// }

// memoization function
int fun(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    // base case
    if(day == 0){
        int maxi = 0;
        for(int task=0; task<3; task++){
            if(task != last){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
        if(dp[day][last] != -1) return dp[day][last];
    }
    int maxi = 0;
    for(int task=0; task<3; task++){
        if(task != last){
            int point = points[day][task] + fun(day-1, task, points,dp);
            maxi = max(maxi,point);

        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraning(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return fun(n-1, 3, points,dp);
}
int main(){
    int n,m;
    cout<<"Enter number of days and number of task : ";
    cin>>n>>m;
    vector<vector<int>> points(n, vector<int>(m));
    cout<<"Enter elements of points : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
             cin>>points[i][j]; 
        }
    }
    int result = ninjaTraning(n,points);
    cout<<result;
    return 0;
}