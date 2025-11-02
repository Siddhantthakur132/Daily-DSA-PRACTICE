#include <iostream>
#include <string>
#include <cctype> // For isalnum and tolower

// Use standard namespaces for simplicity in this example
using namespace std;

// --- Your Solution class ---
class Solution {
public:
    bool isPalindrome(string s) {
        
        int start = 0, end = s.size() - 1;
        while(start < end)
        {
            // Skip non-alphanumeric chars from the left
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            // Skip non-alphanumeric chars from the right
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }
            
            // Compare the two alphanumeric chars
            if (tolower(s[start]) != tolower(s[end]))
            {
                return false; // Mismatch found
            }

            // Move pointers inward
            start++;
            end--;
        }
        
        // If the loop finishes, all chars matched
        return true; 
    }
};

// --- The main function to test the class ---
int main() {
    // Create an instance of the Solution class
    Solution sol;

    // --- Test Cases ---
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " "; // Test with just whitespace
    string s4 = "madam";
    string s5 = "hello";

    // Use boolalpha to print "true" or "false" instead of 1 or 0
    cout << boolalpha; 

    // --- Test 1 ---
    cout << "Test 1: \"" << s1 << "\"" << endl;
    cout << "Is palindrome? " << sol.isPalindrome(s1) << endl; // Expected: true

    // --- Test 2 ---
    cout << "\nTest 2: \"" << s2 << "\"" << endl;
    cout << "Is palindrome? " << sol.isPalindrome(s2) << endl; // Expected: false

    // --- Test 3 ---
    cout << "\nTest 3: \"" << s3 << "\"" << endl;
    cout << "Is palindrome? " << sol.isPalindrome(s3) << endl; // Expected: true (empty after filtering)
    
    // --- Test 4 ---
    cout << "\nTest 4: \"" << s4 << "\"" << endl;
    cout << "Is palindrome? " << sol.isPalindrome(s4) << endl; // Expected: true

    // --- Test 5 ---
    cout << "\nTest 5: \"" << s5 << "\"" << endl;
    cout << "Is palindrome? " << sol.isPalindrome(s5) << endl; // Expected: false

    return 0; // Indicate successful execution
}