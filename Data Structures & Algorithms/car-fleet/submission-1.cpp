class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, double>> cars(n);
        
        for(int i = 0; i < n; i++) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        
        sort(cars.begin(), cars.end());
        
        // Fix 1: Use double instead of int
        stack<double> st; 
        
        for(int i = n - 1; i >= 0; i--) {
            // Fix 2: Use double instead of int
            double currtime = cars[i].second; 
            
            if(st.empty() || currtime > st.top()) {
                st.push(currtime);
            }
        }
        return st.size();
    }
};