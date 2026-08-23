class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto as: asteroids){
            if(as>0){
                st.push(as);
            }
            else{
                bool destroyed = false;
                while(!st.empty() && st.top()>0){
                    int curr= st.top();
                    if(curr<(-as)){
                        st.pop();
                        continue;
                    }
                    else if(curr==(-as)){
                        st.pop();
                        destroyed= true;
                        break;
                    }
                    else{
                        destroyed= true;
                        break;
                    }
                }
                if( !destroyed){
                    st.push(as);
                }
            }
        }
        vector<int> ans;
        if(st.empty()) return {};
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};