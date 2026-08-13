class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;
        
        int count = 0;
        
        // Fix 1: We must move 'n' elements in total, not 'k'
        for (int start = 0; count < n; start++) {
            int curridx = start;
            int prevv = nums[start];
            
            do {
                // Fix 2: Jump forward from the current index, not the start index
                int newidx = (curridx + k) % n;
                
                // Fix 3: Actually write to the array and update the value we are carrying
                swap(nums[newidx], prevv);           // Our new carried value is the one we just displaced
                
                curridx = newidx;
                count++;
            } while (start != curridx);
        }
    }
};