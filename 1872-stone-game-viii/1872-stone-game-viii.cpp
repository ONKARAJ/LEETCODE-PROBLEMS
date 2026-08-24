class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sum
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // Start with taking all stones
        int ans = stones[n - 1];

        // Work backwards
        for (int i = n - 2; i > 0; i--) {
            ans = max(ans, stones[i] - ans);
        }

        return ans;
    }
};