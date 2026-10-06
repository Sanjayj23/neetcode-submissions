class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        vector<int> ans;
        int n= digits.size();
        if(digits[n-1]+1>9){
                ans.push_back(0);
                carry++;
        }else{
            ans.push_back(digits[n-1]+1);
        }
        for(int i=n-2; i>=0; i--){
            if(digits[i]+carry>9){
                ans.push_back(0);
                carry=1;
            }
            else{
                ans.push_back(digits[i]+carry);
                if(carry>0){
                    carry--;
                }
            }
        }
        if(carry>0){
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
