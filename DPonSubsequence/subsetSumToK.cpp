#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// recurrence function
bool fun(int ind, int target, vector<int> &arr){
    // base case
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);
    bool notTake = fun(ind-1, target, arr);
    bool take = false;
    if(arr[ind] <= target){
        take = fun(ind-1, target - arr[ind],arr);
    }
    return take | notTake;
}
// calling function
bool subsetSumToK(int n, int k, vector<int> &arr){
    return fun(n-1,k,arr);
}
int main(){
    int n;
    cout<<"Enter no. of elements in array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter target value : ";
    cin>>target;
     bool result = subsetSumToK(n, target,arr);
     cout<<result;
    return 0;
}