#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPlatforms(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0, current = 0, result = 0;
    int n = arr.size();

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            current++;
            result = max(result, current);
            i++;
        } else {
            current--;
            j++;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum Platforms: " << minPlatforms(arr, dep) << endl;
    return 0;
}
