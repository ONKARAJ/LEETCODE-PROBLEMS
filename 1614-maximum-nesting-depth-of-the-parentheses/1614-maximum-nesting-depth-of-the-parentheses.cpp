class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int maxdepth=0;
        for(char ch : s){
            if(ch =='('){
                depth++;

                maxdepth=max(depth,maxdepth);
            }else{
                if(ch ==')'){
                    depth--;
                }
            }
        }
        return maxdepth;
    }
};