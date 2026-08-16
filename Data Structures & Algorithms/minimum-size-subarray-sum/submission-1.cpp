class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0;
        int currentSum = 0;
        int minLength = INT_MAX;
        
        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];      
            while (currentSum >= target) {
                minLength = min(minLength, right - left + 1);             
                currentSum -= nums[left];
                left++;
            }
        }
        if(minLength==INT_MAX){
            return 0;
        }
        return minLength;
    }
};