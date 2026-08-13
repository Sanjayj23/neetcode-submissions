class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int longest =0;
        for(int num: nums){
            if(!st.count(num-1)){
                int currentstreak= 1;
                int current= num;
            
            while(st.count(current+1)){
                current++;
                currentstreak++;
            }
            longest= max(longest, currentstreak);
            }
        }
        return longest;
    }
};
