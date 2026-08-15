class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans= 0;
        int maxf= 0;
        int left= 0;
        unordered_map<int, int> mpp;

        for(int right= 0; right<s.size(); right++){
            mpp[s[right]]++;
            maxf= max(maxf, mpp[s[right]]);
            int d= right-left+1;
            while((d-maxf)>k){
                mpp[s[left]]--;
                left++;
                d= right-left+1;
            }
            ans= max(ans, d);    
        }
        return ans;
    }
};
