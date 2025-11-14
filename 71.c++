#include <iostream>
using namespace std;

int main() {
    double distance = 24, speedA = 6, speedB = 10;

    double relativeSpeed = speedA + speedB;
    double time = distance / relativeSpeed;
    double meetFromA = speedA * time;

    cout << "Time to meet: " << time << " hours\n";
    cout << "Distance from A: " << meetFromA << " miles\n";

    return 0;
}
