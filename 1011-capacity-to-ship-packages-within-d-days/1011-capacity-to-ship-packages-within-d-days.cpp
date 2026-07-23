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
        capacityload +=weight;
    }

    return daysneeded<=days;
  }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<high){
            int mid=low+(high-low)/2;

            if(canship(weights,days,mid)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};