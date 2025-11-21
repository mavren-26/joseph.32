#include <bits/stdc++.h>
using namespace std;

pair<int,int> findTwoUnique(vector<int> nums) {
    int xorAll = 0;

    for (int n : nums) xorAll ^= n;

    int rightBit = xorAll & -xorAll;

    int a = 0, b = 0;
    for (int n : nums) {
        if (n & rightBit) a ^= n;
        else b ^= n;
    }

    return {a, b};
}

int main() {
    vector<int> nums = {4,1,2,1,2,5};
    auto p = findTwoUnique(nums);
    cout << p.first << " " << p.second << endl;
}
