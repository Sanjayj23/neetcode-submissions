class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n= prices.size();
        int i=0;
        for(int j= i+1; j<n; j++){
            int cprofit= prices[j]-prices[i];
            if(cprofit>=0){
                profit= max(cprofit, profit);
            }
            else{
                i= j;
            }
        }
        return profit;
    }
};
