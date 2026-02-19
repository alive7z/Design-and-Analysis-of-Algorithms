#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n;
    cin >> n;

    vector<char> s(n);
    for (char &x : s) cin >> x;

    vector<int> ans(26, 0);
    for(char val : s) {
        int j = 97 - val;
        ans[j]++;
    }
    int a = ans[0];
    int idx = 0;
    for(int i = 1; i<ans.size(); i++) {
        if(ans[i] > ans[0]) {
            a = ans[i];
            idx = i;
        }
    }
    cout << char(idx + 97) << " " << a << endl;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
