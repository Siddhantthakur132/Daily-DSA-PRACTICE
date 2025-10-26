#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans;
    int start = 0, end = numbers.size() - 1;

    while (start < end) {
        int sum = numbers[start] + numbers[end];
        if (sum == target) {
            ans.push_back(start + 1); // +1 because problem usually expects 1-based index
            ans.push_back(end + 1);
            break;
        } else if (sum < target) {
            start++;
        } else {
            end--;
        }
    }
    return ans;
}

int main() {
    int n, target;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> result = twoSum(numbers, target);

    if (!result.empty()) {
        cout << "Indices (1-based): " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No two numbers found with the given target sum." << endl;
    }

    return 0;
}

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         vector<int>ans;
//       int start,end,mid;
//       int ans1;
//       for(int i=0;i<numbers.size()-1;i++)
//       {
//         int x=target-numbers[i];
//             ans1=-1;
//         start=i+1,end=numbers.size()-1;
//         while(start<=end)
//         {
//             mid=start+(end-start)/2;
//             if(numbers[mid]==x)
//             {
//                 ans1=mid;
//                 break;
//             }
//             else if(numbers[mid]>x)
//             {
//                 end=mid-1;
//             }
//             else
//             start=mid+1;

//         }
//         if(ans1!=-1)
//         {
//             ans.push_back(i+1);
//             ans.push_back(ans1+1);
//             break;
//         }
//       }
//        return ans;
//     }
// };