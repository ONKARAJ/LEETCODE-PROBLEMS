class Solution {
public:
bool canship(vector<int>& weights,int days,int capacity){
    int daysneeded=1;
    int capacityload=0;

    for(int weight:weights){
        if(capacityload+weight>capacity){
            daysneeded++;
            capacityload=0;
        }
        capacityload+=weight;
    }

    return daysneeded<=days;
}
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);

        while(left<right){
            int mid=left+(right-left)/2;

            if(canship(nums,k,mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};