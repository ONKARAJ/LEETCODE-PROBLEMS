class Solution {
public:
    int minAddToMakeValid(string s) {
     int depth=0;
     int ans=0;
     for(char ch:s){
        if(ch=='('){
            depth++;
        }else {
            if(ch==')'){
                depth--;
            }
        }
        if(depth<0){
            ans++;
            depth=0;
        }
     }   
     return ans+depth;
    }
};