class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>ans;
int zero=0;
int one=0;
int two=0;
for(int i=0;i<nums.size();i++){
    if(nums[i]==0){
        zero++;
    }else if(nums[i]==1){
        one++;
    }else{
        two++;
    }
}

for(int i=0;i<zero;i++){
    ans.push_back(0);
}


for(int i=0;i<one;i++){
    ans.push_back(1);
}


for(int i=0;i<two;i++){
    ans.push_back(2);
}

for(int i=0;i<nums.size();i++){
    nums[i]=ans[i];
}
     
    }
};