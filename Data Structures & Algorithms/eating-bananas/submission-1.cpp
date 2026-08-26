class Solution {
public:
    int fun(vector<int>& piles, int k){
        int n= piles.size();
        int ans=0;
        for(int i= 0; i<n; i++){
            if(piles[i]<=k) ans++;
            else{
                ans += ceil((double)piles[i] / k);
            }
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n= piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(fun(piles,mid)>h){
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return low;
    }
};
