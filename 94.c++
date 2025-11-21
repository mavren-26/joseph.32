#include <bits/stdc++.h>
using namespace std;

long long countSetBits(long long n) {
    long long count = 0, i = 1;

    while (i <= n) {
        long long totalPairs = n / (i * 2);
        count += totalPairs * i;

        count += max(0LL, (n % (2*i)) - i + 1);

        i <<= 1;
    }
    return count;
}

int main() {
    cout << countSetBits(5) << endl; // 7
}
