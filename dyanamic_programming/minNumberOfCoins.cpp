#include<iostream>
#include<vector>
using namespace std;
int solveM(vector<int>& nums,int x,vector<int>& dp){
    if(x==0) return 0;
    if(x<0) return INT_MAX;
    if(dp[x]!=-1){
        return dp[x];
    }
    int ans=0;
    int mini=INT_MAX;
    for(int i=0;i<nums.size();i++){
        ans=solveM(nums,x-nums[i],dp);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);
        }
        
    }
    dp[x]=mini;
    return mini;
}
int solveR(vector<int>& nums,int x){
    if(x==0) return 0;
    if(x<0) return INT_MAX;
    int mini=INT_MAX;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        int ans=solveR(nums,x-nums[i]);
        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
    }
    return mini;
}
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(5);
    int x=11;
    int n=nums.size();
    vector<int> dp(n+1,-1);
    int ans=solveM(nums,x,dp);
    if(ans==INT_MAX){
        return -1;
    }
    cout<<ans;
}