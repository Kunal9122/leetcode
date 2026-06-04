class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        
        int l=0;
        for(auto x: s){
            int a=x;
            if(s.find(a-1)==s.end()){
                int c=1;
                while(s.find(a+1)!=s.end()){
                    c++;
                    a++;
                }
               l=max(c,l);
            }
            
    }
    return l;
    }
};