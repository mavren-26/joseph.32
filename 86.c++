#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

double fractional_knapsack(vector<int>& value, vector<int>& weight, int W){
    int n = value.size();
    // store (value/weight ratio, value, weight)
    vector<tuple<double,int,int>> items;
    for(int i=0;i<n;i++)
        items.push_back(make_tuple((double)value[i]/weight[i], value[i], weight[i]));
    
    // sort descending by ratio
    sort(items.rbegin(), items.rend());
    
    double total = 0;
    for(auto item : items){
        double ratio;
        int v, w;
        tie(ratio, v, w) = item;

        if(W == 0) break;

        int take = min(W, w);
        total += take * (double)v / w;
        W -= take;
    }
    return total;
}

int main(){
    vector<int> value = {60,100,120};
    vector<int> weight = {10,20,30};
    int W = 50;
    cout << "Maximum value: " << fractional_knapsack(value, weight, W) << endl;
    return 0;
}
