#include <iostream>
using namespace std;

int countBits(unsigned int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // remove last 1 bit
        count++;
    }
    return count;
}

int main() {
    unsigned int n = 11;
    cout << "Number of 1 bits: " << countBits(n) << endl;
    return 0;
}
