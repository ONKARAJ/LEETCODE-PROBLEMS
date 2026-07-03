class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int num : nums)
            mp[num]++;

        for(auto &it : mp) {
            if(it.second > nums.size()/3)
                ans.push_back(it.first);
        }

        return ans;
        // int n=nums.size();
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     int count=0;
        //     for(int j=i;j<n;j++){
        //         if(nums[i]==nums[j]){
        //             count++;
        //         }
               
        //     }
        //      if(count > n/3){
        //             ans.push_back(nums[i]);
        //         }
           
        // }
        //  return ans;
    }
};