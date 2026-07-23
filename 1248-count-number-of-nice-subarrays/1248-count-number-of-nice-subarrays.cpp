class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0;
        int oddcount=0;
        unordered_map<int,int>st;
        st[0]=1;
        for(int num :nums){
            oddcount +=(num%2);

            if(st.find(oddcount-k) !=st.end()){
                count +=st[oddcount-k];
            }
            st[oddcount]++;
        }
        return count;
    }
};