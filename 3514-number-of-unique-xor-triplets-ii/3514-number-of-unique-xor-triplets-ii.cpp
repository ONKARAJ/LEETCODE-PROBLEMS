class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<char>> dp(4, vector<char>(MAXX, 0));
        dp[0][0] = 1;

        for (int v : nums) {
            auto ndp = dp;

            for (int t = 0; t <= 2; t++) {
                for (int x = 0; x < MAXX; x++) {
                    if (!dp[t][x]) continue;

                    // take current index once
                    ndp[t + 1][x ^ v] = 1;

                    // take current index twice
                    if (t + 2 <= 3)
                        ndp[t + 2][x] = 1;      // v ^ v = 0

                    // take current index three times
                    if (t + 3 <= 3)
                        ndp[t + 3][x ^ v] = 1;  // v ^ v ^ v = v
                }
            }

            dp.swap(ndp);
        }

        int ans = 0;
        for (int x = 0; x < MAXX; x++)
            ans += dp[3][x];

        return ans;
    }
};