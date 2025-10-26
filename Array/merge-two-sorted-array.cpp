#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort and std::swap

using namespace std;

/**
 * This is the Solution class containing your merge logic.
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // If nums2 is empty, there's nothing to merge, so we can return early.
        if (n == 0) {
            return;
        }

        // 'start' points to the beginning of nums2
        int start = 0; 
        
        // 'end' points to the last *real* element in nums1 (at index m-1)
        int end = m - 1; 

        // This loop partitions the elements.
        // It compares the end of nums1's real part with the start of nums2.
        while (start < n && end >= 0) {
            if (nums1[end] > nums2[start]) {
                // If the element in nums1 is larger, swap it with the
                // smaller element from nums2.
                swap(nums1[end], nums2[start]);
                
                // Move both pointers
                end--;
                start++;
            } else {
                // The element in nums1 is already smaller or equal.
                // Since nums1 was sorted, all elements to its left
                // are also smaller, so we can stop partitioning.
                break;
            }
        }

        // At this point:
        // - The first 'm' elements of nums1 contain the m smallest values
        // - All 'n' elements of nums2 contain the n largest values
        // But both arrays are now unsorted internally.

        // 1. Sort the first 'm' elements of nums1
        sort(nums1.begin(), nums1.begin() + m);

        // 2. Sort all 'n' elements of nums2
        sort(nums2.begin(), nums2.end());
        
        // 3. Copy the sorted elements from nums2 into the
        //    empty (zero-filled) slots at the end of nums1.
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};

/**
 * The main function is used to test the Solution.
 */
int main() {
    // 1. Define the test case
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3; // The number of initialized elements in nums1
    vector<int> nums2 = {2, 5, 6};
    int n = 3; // The number of elements in nums2

    // 2. Print the initial state (optional, but good for testing)
    cout << "Before merge:" << endl;
    cout << "nums1: ";
    for(int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    
    cout << "nums2: ";
    for(int i = 0; i < n; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl << endl;

    // 3. Create an instance of the Solution class
    Solution sol;

    // 4. Call the merge function
    //    nums1 is passed by reference, so the function will modify it directly.
    sol.merge(nums1, m, nums2, n);

    // 5. Print the final merged array
    cout << "After merge:" << endl;
    cout << "nums1: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
