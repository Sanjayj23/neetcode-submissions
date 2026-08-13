class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0]=1;
        int currsum= 0;
        int count =0;
        for(int num: nums){
            currsum+= num;
            if(mpp[currsum-k]){
                count+= mpp[currsum-k];
            }
            mpp[currsum]++;
        }
        return count;
    }
};