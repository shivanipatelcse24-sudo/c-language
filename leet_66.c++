#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>d={1,2,9};
    for(int i=d.size()-1;i>=0;i--){
        if(d[i]<9){
            d[i]++;
            break;
        }
        d[i]=0;
        if(i==0) d.insert(d.begin(),1);

    }
    for(int x:d) cout<<x<<" ";
    
}