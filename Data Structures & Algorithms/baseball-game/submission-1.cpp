class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n= ops.size();
        int sum= 0;
        stack<int> st;
        for(auto op: ops){

            if(op== "+"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.push(top1);
                int newScore = top1 + top2;
                st.push(newScore);
                sum += newScore;
            }
            else if(op=="C"){
                sum -= st.top();
                st.pop();
            }
            else if(op=="D"){
                int newScore = st.top() * 2;
                st.push(newScore);
                sum += newScore;
            }
            else{
                int newScore = stoi(op);
                st.push(newScore);
                sum += newScore;
            }
        }
        return sum;
    }
};