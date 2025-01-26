#include<iostream>
#include<vector>
using namespace std;
int solveO(vector<int>& nums,int n){
    int prev2=0;
    int prev1=nums[0];
    
    for(int i=1;i<n;i++){
        int incl=prev2+ nums[i];
        int excl=prev1+0;
        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;

    }
    return prev1;
}
int solveT(vector<int>& nums,int n){
    vector<int> dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int incl=dp[i-2]+nums[i];
        int excl=dp[i-1]+0;
        dp[i]=max(incl,excl);
    }
    return dp[n-1];

}
int solveM(vector<int>& nums,int n,vector<int>& dp){
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int incl = solveM(nums,n-2,dp)+nums[n];
    int excl=solveM(nums,n-1,dp) + 0;
    dp[n]=max(incl,excl);
    return dp[n];
}
int solveR(vector<int>& nums,int n){
    if(n==0){
        return nums[0];
    }
    if(n<0){
        return 0;
    }
    int incl=solveR(nums,n-2)+nums[n];
    int excl=solveR(nums,n-1)+0;
    int ans=max(incl,excl);
    return ans;
}
int main(){
    vector<int> nums;
    nums.push_back(9);
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(2);
    int n=nums.size();
    vector<int> dp(n+1,-1);
    int ans=solveO(nums,n);
    cout<<ans;

}