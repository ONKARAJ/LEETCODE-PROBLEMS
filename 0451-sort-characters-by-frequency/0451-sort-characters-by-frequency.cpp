class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());
         sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        for(auto &p :v){
            ans.append(p.second,p.first);
        }
        return ans;
    }
};