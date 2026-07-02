class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int mx=nums[i];
            int mn=nums[i];
            for(int j=i;j<n;j++){
                mn=min(mn,nums[j]);
                mx=max(mx,nums[j]);

                ans+=(ans,mx-mn);
            }
        }
        return ans;
    }
};