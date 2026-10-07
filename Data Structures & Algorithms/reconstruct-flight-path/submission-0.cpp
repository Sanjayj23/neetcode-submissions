class Solution {
public:
    vector<string> ans;

    unordered_map<string, priority_queue<
        string,
        vector<string>,
        greater<string>
    >> adj;

    void dfs(string station) {
        while(!adj[station].empty()) {
            string next = adj[station].top();
            adj[station].pop();

            dfs(next);
        }

        ans.push_back(station);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};