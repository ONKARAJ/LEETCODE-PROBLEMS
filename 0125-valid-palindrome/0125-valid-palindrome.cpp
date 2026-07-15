class Solution {
public:
    bool isPalindrome(string s) {
        string ans;

        for (char c : s) {
            if (isalnum(c)) {
                ans += tolower(c);
            }
        }

        int left = 0;
        int right = ans.length() - 1;

        while (left < right) {
            if (ans[left] != ans[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};