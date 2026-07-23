class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            leftsum+=cardPoints[i];
        }

        int maxsum=leftsum;
        int rightsum=0;
        for(int i=0;i<k;i++){
            leftsum -=cardPoints[k-1-i];
            rightsum+=cardPoints[n-1-i];

            maxsum=max(maxsum,leftsum+rightsum);
        }
        return maxsum;
    }
};