class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            if (s[i] != s[j]) {
                // Mismatch found. Try both possibilities:
                // 1. Skip the left character (i + 1 to j)
                // 2. Skip the right character (i to j - 1)
                return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }
        
        return true;
    }
    
private:
    // Helper function to check if a specific range is a standard palindrome
    bool checkPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};