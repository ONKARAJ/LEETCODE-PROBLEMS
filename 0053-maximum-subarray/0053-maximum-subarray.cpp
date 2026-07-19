class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int lar=INT_MIN;
        for(int num:nums){
            sum+=num;

            lar=max(lar,sum);

            if(sum<0){
                sum=0;
            }
        }
        return lar;
    }
};