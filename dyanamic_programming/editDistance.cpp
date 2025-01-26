#include<iostream>
#include<vector>
using namespace std;
int solve(string a,string b,int i,int j){
    if(i==a.length()){
        return b.length()-j;
    }
    if(j==b.length()){
        return a.length()-i;
    }
    int ans=0;
    if(a[i]==b[j]){
        return solve(a,b,i+1,j+1);
    }
    else{
        int insert=solve(a,b,i,j+1)+1;
        int dele=solve(a,b,i+1,j)+1;
        int replace=solve(a,b,i+1,j+1)+1;
        ans = min(insert,min(dele,replace));
    }
    return ans;   
}
int main(){
    string word1="horse";
    string word2="rose";
    int s= solve(word1,word2,0,0);
    cout<<s<<endl;
}