#include <iostream>
#include <vector>
#include <unordered_set>

// Using namespace std for brevity in a simple example file.
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Your Solution class containing the logic.
 * This version is safe for platforms like LeetCode because it does not
 * manually 'delete' nodes, avoiding the heap-use-after-free error.
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        // Create a hash set for efficient O(1) average time lookups.
        unordered_set<int> st(begin(nums), end(nums));

        // 1. Handle the case where the head node(s) need to be removed.
        // We keep advancing the head pointer until we find a node
        // that is NOT in the set.
        while (head != NULL && st.find(head->val) != st.end()) {
            head = head->next;
            // Note: We do NOT delete the old head, as the calling
            // environment (like LeetCode) manages its own memory.
        }

        // If the entire list was deleted, head will be null.
        if (head == NULL) {
            return head;
        }

        // 2. Handle nodes in the middle or at the end of the list.
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {
            // Check if the *next* node needs to be removed.
            if (st.find(curr->next->val) != st.end()) {
                // "Bypass" the node to be removed by pointing around it.
                curr->next = curr->next->next;
                // We do NOT delete the bypassed node.
                // We also do NOT advance `curr` yet, in case the
                // new `curr->next` also needs to be removed.
            } else {
                // Only advance `curr` if its next node is safe.
                curr = curr->next;
            }
        }
        
        // Return the potentially new head of the modified list.
        return head;
    }
};

// --- Helper Functions for main() ---

/**
 * Helper function to print a linked list to the console.
 */
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

/**
 * Helper function to free all nodes in a linked list.
 * This is crucial for a standalone C++ program to avoid memory leaks.
 */
void freeList(ListNode* head) {
    cout << "Cleaning up list memory..." << endl;
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    cout << "List memory freed." << endl;
}

// --- Main Function ---
int main() {
    // 1. Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // 2. Create a vector of numbers to remove.
    vector<int> nums = {1, 3, 5};
    cout << "Numbers to remove: {1, 3, 5}" << endl;

    // 3. Instantiate Solution and call the method.
    Solution solution;
    ListNode* modifiedHead = solution.modifiedList(nums, head);

    // 4. Print the modified list.
    cout << "Modified list: ";
    printList(modifiedHead); // Expected: 2 -> 4 -> NULL

    // 5. Clean up the memory for the remaining nodes.
    // In a real LeetCode environment, you would NOT do this.
    // But in our main(), we must free the nodes we can still access.
    // Note: The original nodes (1, 3, 5) are now "leaked" in this
    // standalone program because `modifiedList` didn't free them
    // and `main` no longer has a pointer to them. This is the
    // expected trade-off for making the solution platform-safe.
    freeList(modifiedHead);

    return 0;
}
