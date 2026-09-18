class Solution {
public:
    string predictPartyVictory(string s) {
        int r = 0, d = 0;
        int len = s.size();

        for (char c : s) {
            if (c == 'R')
                r++;
            else
                d++;
        }
        int i = 0;
        while (r!=0 && d!=0) {
            if (s[i] == 'X') {
                i = (i + 1) % len;
                continue;
            }
            if (s[i] == 'R') {
                int j = (i + 1) % len;
                while (s[j] != 'D') {
                    j = (j + 1) % len;
                }
                s[j] = 'X';
                d--;
            }
            else if (s[i] == 'D') {
                int j = (i + 1) % len;
                while (s[j] != 'R') {
                    j = (j + 1) % len;
                }
                s[j] = 'X';
                r--;
            }
            i = (i + 1) % len;
        }
        return r>0 ? "Radiant" : "Dire";
    }
};