#include <iostream>
#include <vector>
using namespace std;

long long comparisons = 0;
long long inversions = 0;

void merge(vector<int> &arr, int l, int m, int r) {
    vector<int> leftArr, rightArr;

    for (int i = l; i <= m; i++)
        leftArr.push_back(arr[i]);
    for (int i = m + 1; i <= r; i++)
        rightArr.push_back(arr[i]);

    int i = 0, j = 0, k = l;

    while (i < leftArr.size() && j < rightArr.size()) {
        comparisons++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            inversions += (leftArr.size() - i);
        }
    }

    while (i < leftArr.size())
        arr[k++] = leftArr[i++];

    while (j < rightArr.size())
        arr[k++] = rightArr[j++];
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        comparisons = 0;
        inversions = 0;

        mergeSort(arr, 0, n - 1);

        cout << endl; 
        for (int i = 0; i < n; i++) {
            cout  << arr[i];
            if (i != n - 1) cout << " ";
        }
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "inversions = " << inversions << endl;
        cout << endl;
    }
    return 0;
}
