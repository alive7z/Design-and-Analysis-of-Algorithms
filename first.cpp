//Given an array of nonnegative integers, design a linear algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)

#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& arr, int key, int &comparisons) {
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int main() {
    int n, key, comparisons = 0;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter key: ";
    cin >> key;
    int index = linearSearch(arr, key, comparisons);
    if (index) cout << "Found: " << index << "." << "\n";
    else cout << "Not found. \n";
    cout << "Total comparisons: " << comparisons << "\n";
    return 0;
}