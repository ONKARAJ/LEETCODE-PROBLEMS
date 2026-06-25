class Solution {
public:
bool canship(vector<int>&weights , int days,int capacity){
    int daysNedded=1;
    int capacityLoad=0;
    for(int weight : weights){
        if(capacityLoad+weight>capacity){
            daysNedded++;
            capacityLoad=0;
        }
        capacityLoad +=weight;
    }
    return daysNedded<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right=accumulate(weights.begin(),weights.end(),0);
        while(left < right){
            int mid=left+(right-left)/2;
            if(canship(weights,days,mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};