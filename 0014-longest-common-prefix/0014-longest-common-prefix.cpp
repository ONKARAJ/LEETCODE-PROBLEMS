class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            while(j<ans.size()){
                if(ans[j]==strs[i][j]){
                    j++;
                }else{
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};