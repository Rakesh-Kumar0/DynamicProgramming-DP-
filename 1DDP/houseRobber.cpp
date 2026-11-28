#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

// function using spaceOptimization(from previous question i.e. maxNonAdjacentSum)
int maximumNonAdjacentSum(int n, vector<int> &arr){
    int prev = arr[0];
    int prev2 = 0;
    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1) pick += prev2; 
        int notpick = 0 + prev;
        int curi = max(pick, notpick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
    
}

long long int houseRobber(vector<int> &valueInHouse){
    vector<int> temp1, temp2;
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    for(int i=0; i<n; i++){
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjacentSum(n,temp1),maximumNonAdjacentSum(n,temp2));
}


int main(){
    int n;
    cout<<"Enter number of elements in array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
   long long int result = houseRobber(arr);
    cout<<result;
    return 0;
}
