
#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
    vector<int> prefix;

public:
    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        } 
        else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefix.size();

        if (k >= n)
            return 0;

        return prefix[n - 1] / prefix[n - 1 - k];
    }
};

int main() {
    ProductOfNumbers obj;

    obj.add(3);
    obj.add(0);
    obj.add(2);
    obj.add(5);
    obj.add(4);

    cout << obj.getProduct(2) << endl;
    cout << obj.getProduct(3) << endl;
    cout << obj.getProduct(4) << endl;

    return 0;
}
