class Solution {
public:
    int reverse(int x) {
    int k;
    long long j=0;
        while(x!=0){
            k=x%10;
            j=j*10+k;
            x=x/10;
        }
     if(j < INT_MIN || j > INT_MAX)
        return 0;
        return j;
    }
};