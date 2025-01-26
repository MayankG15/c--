#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
    int n=vect.size();
    for (int x=0;x<n;x++)
        cout << vect[x] << " ";
 
    return 0;
}