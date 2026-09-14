class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        if(k == 1) {
            unordered_map<int,int> mp;

            for(int x : nums)
                mp[x]++;

            int ans = -1;

            for(auto x : mp) {
                if(x.second == 1)
                    ans = max(ans, x.first);
            }

            return ans;
        }

        int c1 = 0, c2 = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[0])
                c1++;
        }
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[n-1])
                c2++;
        }
        int ans = -1;
        if(c1 == 0)
            ans = max(ans, nums[0]);
        if(c2 == 0)
            ans = max(ans, nums[n-1]);
        return ans;
    }
};