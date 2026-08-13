class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int n = strs.size();
        int len = strs[0].size();

        // Find common prefix between strs[0] and every other string
        for (int i = 1; i < n; i++) {
            int j = 0;

            while (j < len &&
                   j < strs[i].size() &&
                   strs[0][j] == strs[i][j]) {
                j++;
            }

            len = j;

            // No common prefix
            if (len == 0) return "";
        }

        return strs[0].substr(0, len);
    }
};