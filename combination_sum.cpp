#include<iostream>
#include<vector>
using namespace std;
void Sum(vector<int>& candidate,int target,vector<int>& r,vector<vector<int> >& res,int i){
    if(target==0){
        res.push_back(r);
        return;
    }
    while(i<candidate.size() && target-candidate[i]>=0){
        r.push_back(candidate[i]);
        Sum(candidate,target-candidate[i],r,res,i);
        i++;
        r.pop_back();
    }
}
vector<vector<int> > combination_sum(vector<int>& candidate,int target){
    sort(candidate.begin(),candidate.end());
    candidate.erase(unique(candidate.begin(),candidate.end()),candidate.end());
    vector<int> r;
    vector<vector<int> > res;
    Sum(candidate,target,r,res,0);
    vector<vector<int> > ans=res;
    return ans;

}
int main(){
    vector<int> candidate;
    candidate.push_back(2);
    candidate.push_back(3);
    candidate.push_back(6);
    candidate.push_back(7);
    int target=7;
    vector<vector<int> > a = combination_sum(candidate,target);
    for(int i=0;i<a.size();i++){
        if(a[i].size()>0){
            cout<<"("<<" ";
            for(int j=0;j<a[i].size();j++){
                cout<<a[i][j]<<" ";
            }
            cout<<")";
        }
    }
    return 0;
}