class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        int s=0;
        int c=0;
        for(int i=0;i<queries.size();i++){
            s=0;
            c=0;
            for(int j=0;j<nums.size();j++){
                s+=nums[j];
                c++;
                if(s>queries[i]){
                    c--;
                    break; 
                }
               
            }
            v.push_back(c);
        }
        return v;
    }
};