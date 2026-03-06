class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg;
        int add=0;
        for(int i=0;i<k;i++){
            add+=nums[i];
        }
        double a=k;
        maxAvg=add/a;
        double avg=maxAvg;
        int i=0,j=k,n=nums.size();
        while(j<n){
            add-=nums[i];
            add+=nums[j];
            i++;
            j++;
            avg=add/a;
            if(avg>maxAvg){
                maxAvg=avg;
            }
        }
        return maxAvg;
    }
};