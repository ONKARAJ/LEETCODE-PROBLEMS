class Solution {
public:
    int largestRectangle(vector<int>& h) {
        stack<int> st;
        int ans = 0;

        for (int i = 0; i <= h.size(); i++) {
            while (!st.empty() && (i == h.size() || h[st.top()] >= h[i])) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix[0].size();
        vector<int> h(n, 0);
        int ans = 0;

        for (auto &row : matrix) {
            for (int j = 0; j < n; j++)
                h[j] = (row[j] == '1') ? h[j] + 1 : 0;

            ans = max(ans, largestRectangle(h));
        }

        return ans;
    }
};