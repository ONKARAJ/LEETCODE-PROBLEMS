class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int maxfreq=0;
        int ans=0;
        unordered_map<char,int>st;
        for(int right=0;right<s.length();right++){
            st[s[right]]++;

            maxfreq=max(maxfreq,st[s[right]]);
            int window=right-left+1;

            while(window-maxfreq>k){
                st[s[left]]--;
                left++;

                window=right-left+1;
            }
            ans=max(ans,window);
        }
        return ans;
    }
};