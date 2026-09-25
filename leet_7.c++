#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans= 0,rem,x;
    cin>>x;
    while(x!=0){
        rem=x%10;
        x/=10;
        if(ans>INT_MAX/10||ans<INT_MIN/10)
          return 0;
        ans=ans*10+rem;

    }
    return ans;
}