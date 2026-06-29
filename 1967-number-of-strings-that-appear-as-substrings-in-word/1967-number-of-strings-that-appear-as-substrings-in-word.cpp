class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int p=patterns.size();
       int count=0;
       for(int i=0;i<p;i++){
        if(word.find(patterns[i]) != string::npos){
            count++;
        }
       
        }
        return count;
    }
};