class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int minTime=INT_MAX;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=0;j<2;j++){
                s+=tasks[i][j];
            }
            minTime=min(s,minTime);
        }
        return minTime;
    }
};