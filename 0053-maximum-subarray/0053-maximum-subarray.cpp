class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int lar=INT_MIN;
        int sum=0;

       for(int num : nums){
        sum+=num;

        lar=max(lar,sum);

        if(sum<0){
            sum=0;
        }
       }
       return lar;
    }
};