#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// space optimization function
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<int> prev(k+1,0), cur(k+1,0);
    // base case
    prev[0] = cur[0] = true;
    if(arr[0] <= k) prev[arr[0]] = true;
    for(int ind=1; ind<n; ind++){
        for(int target=1; target<=k; target++){
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind] <= target){
                take = prev[target - arr[ind]];
            }
            cur[target] = take | notTake;
        }
        prev = cur;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr, int n){
    int totalSum = 0;
    for(int i=0; i<n; i++){
        totalSum += arr[i];
    }
    if(totalSum % 2) return false;
    int target = totalSum / 2;
    return subsetSumToK(n, target, arr);
}
int main(){
    int n;
    cout<<"Enter no. of elements in array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    bool result = canPartition(arr, n);
     cout<<result;
    return 0;
}