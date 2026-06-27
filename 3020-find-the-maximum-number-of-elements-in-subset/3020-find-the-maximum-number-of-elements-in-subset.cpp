class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle the special case of 1
        if (freq.count(1)) {
            ans = max(ans, (freq[1] % 2 == 0) ? freq[1] - 1 : freq[1]);
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (!freq.count(cur))
                    break;

                if (freq[cur] == 1) {
                    len++;
                    break;
                }

                // freq[cur] >= 2
                len += 2;

                // Prevent overflow
                if (cur > 1000000000LL / cur) {
                    len--;      // last pair becomes the center
                    break;
                }

                long long next = cur * cur;

                if (!freq.count(next)) {
                    len--;      // no next square, so last pair can't exist
                    break;
                }

                cur = next;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};