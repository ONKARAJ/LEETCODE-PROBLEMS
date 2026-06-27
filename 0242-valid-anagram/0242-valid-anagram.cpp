class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.length();
        int n2=t.length();

        if(n1 != n2){
            return false;
        }

        int freq[26]={0};

        for(char ch : s){
            freq[ch-'a']++;
        }

        
        for(char ch : t){
            freq[ch-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i] !=0){
                return false;
            }
        }

return true;
    }
};