class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int ans=0,c=0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(auto x:s){
            if(s.find(x-1)==s.end()){
                c=1;
                int a=x;
                while(s.find(a+1)!=s.end()){
                    c++;a++;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};