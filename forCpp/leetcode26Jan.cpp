// join two string in adjacent ways
#include<iostream>
#include<string>
using namespace std;

string mergeAlternatively(string word1,string word2){
    string result;
    int n1=word1.length(), n2=word2.length();
    int i=0, j=0;

    while(i<n1 && j<n2){
        result+=word1[i];
        result+=word2[j];
        i++;
        j++;
    }
    while(i<n1){
        result+=word1[i];
        i++;
    }
    while(j<n2){
        result+=word2[j];
        j++;
    }
    return result;
}
int main(){
    string word1="Maynk",word2= "Goyal";
    cout<<mergeAlternatively(word1,word2)<<endl;
    return 0;
}