#include<iostream>
#include<vector>
using namespace std;
int solveS(int n,vector<int>& cost){
    int prev2=cost[0];
    int prev1=cost[1];
    for(int i=2;i<n;i++){
        int curr=cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev1,prev2);
}
int solveT(int n,vector<int>& cost){
    vector<int> dp(n,0);
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}
int solveM(int n,vector<int>& cost,vector<int>& dp){
    //base case
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=cost[n]+min(solveM(n-1,cost,dp),solveM(n-2,cost,dp));
    return dp[n]=ans;
}
int solveR(int n,vector<int>& cost){
    //base case
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    int ans=cost[n]+min(solveR(n-1,cost),solveR(n-2,cost));
    return ans;
}
int minimumCostClimbingStairs(vector<int>& cost){
    int n=cost.size();
    vector<int> dp(n+1,-1);
    int a=solveS(n,cost);
    return a;
}
int main(){
    vector<int> cost;
    cost.push_back(10);
    cost.push_back(15);
    cost.push_back(20);
    int ans= minimumCostClimbingStairs(cost);
    cout<<ans;
}