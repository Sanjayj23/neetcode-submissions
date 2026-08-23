class Solution {
public:
    bool isValid(string s) {
        // Great optimization! Odd length strings can never be valid.
        if (s.size() % 2 != 0) return false;
        
        stack<char> st;
        
        for (char ch : s) {
            // 1. If it's an opening bracket, push it
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } 
            // 2. If it's a closing bracket...
            else {
                // MUST check if empty BEFORE looking at the top
                if (st.empty()) return false;
                
                char top = st.top();
                
                // Check for mismatches
                if ((ch == ')' && top != '(') || 
                    (ch == ']' && top != '[') || 
                    (ch == '}' && top != '{')) {
                    return false;
                }
                
                // If it matches, remove it from the stack
                st.pop();
            }
        }
        
        // 3. At the very end, the stack should be completely empty.
        // If it's not, it means we have leftover opening brackets (like "((()")
        return st.empty();
    }
};