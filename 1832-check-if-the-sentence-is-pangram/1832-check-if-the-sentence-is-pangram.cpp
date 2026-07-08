class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> mp;
        for (char ch : sentence) {
            mp[ch]++;
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (mp[ch] == 0) {
                return false;
            }
        }
        return true;
    }
};