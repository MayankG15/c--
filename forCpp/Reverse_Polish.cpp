#include<iostream>
#include<stack>
#include<vector>
using namespace std;
stack<int> st;
void operation(string &op){
    if(st.empty()){
        return;
    }
    int n2 =st.top();
    st.pop();
    if(st.empty()) return;
    int n1=st.top();
    st.pop();
    int x;
    switch(op[0]){
        case '+': x=n1+n2; break;
        case '-': x=n1-n2; break;
        case '*': x=n1*n2; break;
        case '/': x=n1/n2; break;
    }
    st.push(x);

}
int main(){
    vector<string> token{"2","1","+","3","*"};
    int n=token.size();
    for(int s=0;s<n;s++){
        if(token[s]=="+" || token[s]=="-" || token[s]=="*" || token[s]=="/"){
            operation(token[s]);
        }
        else{
            int x=stoi(token[s]);
            st.push(x);
        }
    }
    int ans;
    if(st.empty()) return 0;
    return ans=st.top();
    cout<<ans<<endl;
}