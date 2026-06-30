class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int n=s.length();
        int count=0;
        unordered_map<char,int>mp;
        for(int right=0;right<n;right++){
             mp[s[right]]++;

             while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                count +=n-right;

                mp[s[left]]--;
                left++;
             }
        }
        return count;
    }
};