#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int i = 0, j = arr.size() - 1;
        while (i < j) {
            if (arr[i] == 0) {
                i++;
            } else if (arr[j] == 0 && arr[i] != 0) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            } else {
                j--;
            }
        }
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (only 0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    obj.segregate0and1(arr);

    cout << "Array after segregation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
