#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solve(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, int> m;
    for(int i = 0; i<nums.size(); i++) {
        int first = nums[i];
        int second = target - first;
        if(m.find(second) != m.end()) {
            ans.push_back(m[second]);
            ans.push_back(i);
            break;
        }
        m[first] = i;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, target;
        cout << "Enter target: ";
        cin >> target;
        cout << "Enter size: ";
        cin >> n;
        cout << "Enter elements: ";
        vector<int> nums(n);
        for (int &x : nums) cin >> x;

        vector<int> ans = solve(nums, target);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
