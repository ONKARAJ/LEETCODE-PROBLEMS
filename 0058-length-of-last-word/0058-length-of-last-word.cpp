class Solution {
public:
    int lengthOfLastWord(string s) {
      int n=s.length();
      reverse(s.begin(),s.end());
      string ans;
      for(int i=0;i<n;i++){
        
        while(i<n && s[i]==' '){
        i++;
        }

        while(i<n && s[i] != ' '){
            ans+=s[i];
            i++;
        }

        if(!ans.empty()){
            break;
        }
      }  
      return ans.length();
    }
};