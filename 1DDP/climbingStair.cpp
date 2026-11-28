#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int climbingStare(int step){
    // base case
    if(step == 0) return 1;
    if(step < 0) return 0;
    // A 1-step final jump starts one step below
    int oneStepJump = climbingStare(step - 1);
    // A 1-step final jump starts two step below
    int twoStepJump = climbingStare(step - 2);
    return oneStepJump + twoStepJump;
}

int main(){
    int n;
    cout<<"Enter numbet of steps : ";
    cin>>n;
    int result = climbingStare(n);
    cout<<result;
    return 0;
}


// Memoization

// class Solution {
// private:
//     // Counts paths and stores calculated results.
//     int solve(int step, vector<int>& dp) {
//         // Ground level completes one valid sequence.
//         if (step == 0) {
//             return 1;
//         }

//         // A negative step cannot complete a valid sequence.
//         if (step < 0) {
//             return 0;
//         }

//         // A saved count avoids repeated recursive work.
//         if (dp[step] != -1) {
//             return dp[step];
//         }

//         // A 1-step final jump starts one step below.
//         int oneStepJump = solve(step - 1, dp);

//         // A 2-step final jump starts two steps below.
//         int twoStepJump = solve(step - 2, dp);

//         // The full count joins both final-jump groups.
//         dp[step] = oneStepJump + twoStepJump;

//         // The saved count finishes the current state.
//         return dp[step];
//     }

// public:
//     // Returns the count using memoized recursion.
//     int climbStairs(int n) {
//         // Minus one marks every uncalculated state.
//         vector<int> dp(n + 1, -1);

//         // Target state n represents the full staircase.
//         return solve(n, dp);
//     }
// };

// // Driver code
// int main() {
//     int n = 4;
//     Solution obj;
//     cout << obj.climbStairs(n);
//     return 0;
// }


// Tabulation

// class Solution {
// public:
//     // Returns the count using bottom-up tabulation.
//     int climbStairs(int n) {
//         // One table entry stores each step count.
//         vector<int> dp(n + 1, 0);

//         // Ground level represents one empty sequence.
//         dp[0] = 1;

//         // A positive staircase needs the first base count.
//         if (n >= 1) {
//             dp[1] = 1;
//         }

//         // Increasing order keeps both earlier counts ready.
//         for (int step = 2; step <= n; step++) {
//             // Both final-jump groups form the current count.
//             dp[step] = dp[step - 1] + dp[step - 2];
//         }

//         // Target entry stores the complete answer.
//         return dp[n];
//     }
// };

// // Driver code
// int main() {
//     int n = 4;
//     Solution obj;
//     cout << obj.climbStairs(n);
//     return 0;
// }