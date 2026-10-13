
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector<int> res(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int x = num1[i] - '0';
                int y = num2[j] - '0';

                int product = x * y + res[i + j + 1];

                res[i + j + 1] = product % 10;
                res[i + j] += product / 10;
            }
        }

        string ans = "";
        int idx = 0;

        while (idx < n + m && res[idx] == 0) {
            idx++;
        }

        for (int i = idx; i < n + m; i++) {
            ans += to_string(res[i]);
        }

        return ans.empty() ? "0" : ans;
    }
};
