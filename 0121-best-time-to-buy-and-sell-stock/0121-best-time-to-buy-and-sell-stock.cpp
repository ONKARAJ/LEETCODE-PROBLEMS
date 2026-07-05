class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int minprice=INT_MAX;
     int profit=INT_MIN;
     for(int price : prices){
        minprice=min(minprice,price);
        profit=max(profit,price-minprice);
     }   
     return profit;
    }
};