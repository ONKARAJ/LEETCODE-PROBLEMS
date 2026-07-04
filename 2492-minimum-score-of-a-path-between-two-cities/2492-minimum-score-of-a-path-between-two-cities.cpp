class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> vis(n + 1, 0);

        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto &it : adj[node]) {

                ans = min(ans, it.second);

                if (!vis[it.first]) {
                    vis[it.first] = 1;
                    q.push(it.first);
                }
            }
        }

        return ans;
    }
};