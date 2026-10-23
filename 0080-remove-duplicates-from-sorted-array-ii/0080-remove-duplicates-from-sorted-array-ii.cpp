class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int n = nums.size();
        if(n <= 2) return n;
        int ans=1;
        int c=1;
        int prev=nums[0];
        for(int i=1;i<n;i++){
           if(prev==nums[i] && c>=2){
            int j=i;
            while(j<n && nums[j]==prev){
                prev=nums[j];
                j++;
            }
            int k=i;
            while(j<n){
                nums[k]=nums[j];
                k++;
                j++;
            }
            n=k;
            i--;
            c=1;
           }
           else if(prev==nums[i] && c<2){
            ans++;
            c++;
           }
            else if(prev!=nums[i]){
                ans++;
                c=1;
            }
            prev=nums[i];
        }
        return ans;
    }
};