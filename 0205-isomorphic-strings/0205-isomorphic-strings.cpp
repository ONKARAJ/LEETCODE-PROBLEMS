class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;

if(s.length() !=t.length()){
    return false;
}
        for(int i=0;i<s.length();i++){
            char c1=s[i];
            char c2=t[i];

            if(mp1.count(c1)){
                if(mp1[c1] != c2){
                    return false;
                }
            }else{
                if(mp2.count(c2))
                return false;

                mp1[c1]=c2;
                mp2[c2]=c1;
            }
        }
        return true;
    }
};