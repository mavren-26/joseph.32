#include <iostream>
using namespace std;

double markedPrice(double cp, double profit, double discount) {
    double sp = cp * (1 + profit / 100);
    double mp = sp / (1 - discount / 100);
    return mp;
}

int main() {
    double cp = 800, profit = 25, discount = 10;

    double mp = markedPrice(cp, profit, discount);
    cout << "Required Marked Price: $" << mp << endl;

    return 0;
}
