class Solution {
public:
    int digitSum(int num){
        int s=0;
        while(num){
            int m=num%10;
            s=s+(m*m);
            num=num/10;
        }
        return s;
    }
    bool isHappy(int n) {
        unordered_set<int>s;
        int num=n;
        while(num!=1){
            num=digitSum(num);
            if(s.find(num)!=s.end()) return false;
            else s.insert(num);
        }
        return true;
    }
};