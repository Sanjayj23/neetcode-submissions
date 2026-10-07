class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();

        if(n < 2)
            return n;

        int ans = 1;
        int len = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) {
                if(i >= 2 && arr[i-1] < arr[i-2])
                    len++;
                else
                    len = 2;
            }
            else if(arr[i] < arr[i-1]) {
                if(i >= 2 && arr[i-1] > arr[i-2])
                    len++;
                else
                    len = 2;
            }
            else {
                len = 1;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};