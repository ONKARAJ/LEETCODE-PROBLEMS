class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int n=s.length();
        int count=0;
        unordered_map<char,int>st;
        for(int right=0;right<n;right++){
           st[s[right]]++;

       while(st['a']>0 && st['b']>0 && st['c']>0){
        count +=n-right;
        st[s[left]]--;
        left++;
       }
 
 }
 return count;
    }
};