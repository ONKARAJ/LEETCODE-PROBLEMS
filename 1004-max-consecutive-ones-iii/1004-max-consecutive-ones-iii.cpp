class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int zeros=0;
        int amxlen=0;

        for(int right=0;right<nums.size();right++){
            if(nums[right]==0)
                zeros++;
            

            while(zeros>k){
                if(nums[left]==0)
                    zeros--;
                    left++;
                
            }
                        amxlen=max(amxlen,right-left+1);
            }


            
        
        return amxlen;
    }
};