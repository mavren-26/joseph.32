#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    vector<int> st;
    vector<int> minSt;

    void push(int x) {
        st.push_back(x);
        if (minSt.empty()) minSt.push_back(x);
        else minSt.push_back(min(x, minSt.back()));
    }

    void pop() {
        if (!st.empty()) {
            st.pop_back();
            minSt.pop_back();
        }
    }

    int top() { return st.back(); }

    int getMin() { return minSt.back(); }
};

int main() {
    MinStack obj;
    obj.push(5);
    obj.push(2);
    obj.push(8);

    cout << obj.getMin() << endl; // 2
    obj.pop();
    cout << obj.top() << endl;    // 2
    cout << obj.getMin() << endl; // 2
}
