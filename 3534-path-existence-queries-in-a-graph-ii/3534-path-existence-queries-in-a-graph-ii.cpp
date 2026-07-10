class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> ord;
        ord.reserve(n);
        for (int i = 0; i < n; i++)
            ord.push_back({nums[i], i});
        sort(ord.begin(), ord.end());

        vector<int> pos(n), val(n);
        for (int i = 0; i < n; i++) {
            val[i] = ord[i].first;
            pos[ord[i].second] = i;
        }

        // connected components
        vector<int> comp(n);
        int cid = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (val[i] - val[i - 1] > maxDiff) cid++;
            comp[i] = cid;
        }

        // reach[]
        vector<int> reach(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n && val[r + 1] - val[i] <= maxDiff) r++;
            reach[i] = r;
        }

        const int LOG = 18; // since n <= 1e5
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = reach;
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][ up[k - 1][i] ];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int a = pos[q[0]], b = pos[q[1]];
            if (a == b) {
                ans.push_back(0);
                continue;
            }
            if (a > b) swap(a, b);

            if (comp[a] != comp[b]) {
                ans.push_back(-1);
                continue;
            }

            int cur = a;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    cur = up[k][cur];
                    steps += 1 << k;
                }
            }
            ans.push_back(steps + 1);
        }

        return ans;
    }
};