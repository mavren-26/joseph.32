#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestWPI(vector<int>& hours) {
    int score = 0, res = 0;
    unordered_map<int, int> seen;

    for (int i = 0; i < hours.size(); i++) {
        score += (hours[i] > 8) ? 1 : -1;

        if (score > 0)
            res = i + 1;
        else {
            if (seen.find(score - 1) != seen.end())
                res = max(res, i - seen[score - 1]);
        }

        if (seen.find(score) == seen.end())
            seen[score] = i;
    }

    return res;
}

int main() {
    vector<int> hours = {9, 9, 6, 0, 6, 6, 9};
    cout << longestWPI(hours) << endl;  // Output: 3
    return 0;
}
