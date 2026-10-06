class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int depth=0;
        for(char ch:s){
            if(ch=='('){
                depth++;
            }else{
                depth--;
            }

            if(depth<0){
                ans++;
                depth=0;
            }
        }
        return ans+depth;
    }
};