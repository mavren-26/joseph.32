#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrows(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](auto &a, auto &b){
        return a[1] < b[1];    // sort by ending
    });

    int arrows = 1;
    int end = points[0][1];

    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }
    return arrows;
}

int main() {
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};

    cout << "Minimum Arrows: " << findMinArrows(points) << endl;
    return 0;
}
