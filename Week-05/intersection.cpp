#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solve(vector<int>& num1, vector<int>& num2) {
    vector<int> ans;
    int i = 0, j = 0;
    sort(num1.begin(), num1.end());
    sort(num2.begin(), num2.end());
    while(i < num1.size() && j < num2.size()) {
        if(num1[i] == num2[j]) {
            ans.push_back(num1[i]);
            i++; j++;
        } else if(num1[i] < num2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cout << "Enter size of num1 and num2: ";
        cin >> m >> n;
        cout << "Enter elements of num1: ";
        vector<int> num1(m);
        for (int &x : num1) cin >> x;
        cout << "Enter elements of num2: ";
        vector<int> num2(n);
        for (int &x : num2) cin >> x;
        vector<int> ans = solve(num1, num2);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
