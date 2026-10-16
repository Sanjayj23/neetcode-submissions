class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int idx=0;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        while(idx<n){
            if(nums[idx]==idx){
                idx++;
                continue;
            }else{
                return nums[idx]-1;
            }
        }
        return n;
    }
};
