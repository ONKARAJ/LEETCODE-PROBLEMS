class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0,ans=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                ans++;
                c=max(c,ans);
            }else{
                ans=0;
            }
        }
        return c;
    }
};