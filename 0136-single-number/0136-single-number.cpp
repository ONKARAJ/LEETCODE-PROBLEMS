class Solution {
public:
    int singleNumber(vector<int>& nums) {
     unordered_map<int,int>mp;
int ans=0;
int n=nums.size();
     for(int i=0;i<n;i++){
        mp[nums[i]]++;
     } 

     for(auto& it :mp){
        if(it.second==1){
            ans=it.first;
        };

       
     }  
 return ans;
    }
};