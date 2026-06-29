class Solution {
public:
    int maxArea(vector<int>& height) {
        int length=0;
        int bredth=0;
        int left=0;
        int area=0;
        int right=height.size()-1;
        while(left < right){
            
       bredth=right-left;
       length=min(height[left],height[right]);
       area=max(area,length*bredth);

       if(height[left] < height[right]){
        left++;
       }else{
        right--;
       }
        }
        return area;
    }
};