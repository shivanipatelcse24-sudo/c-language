#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1,2,3,0,0,0};
    vector<int> b = {2,5,6};
    int m = 3, n = 3;

    int i=m-1, j=n-1, k=m+n-1;

    while(j>=0) {
        if(i>=0 && a[i]>b[j])
            a[k--]=a[i--];
        else
            a[k--]=b[j--];
    }

    for(int x:a) cout << x << " ";
}