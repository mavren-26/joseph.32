#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st; // store indexes

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main() {
    vector<int> nums = {2, 1, 2, 4, 3};
    vector<int> ans = nextGreater(nums);

    for (int x : ans) cout << x << " ";
}
