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