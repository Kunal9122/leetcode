class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int c=0;
        for(int i=low;i<=high;i++){
            int n=i;
            string str=to_string(n);
            int l=str.size();
             if (l % 2 != 0) continue;
            int ls=0,su=0;
            int rs=0;
            while(n){
                int j=n%10;
                n=n/10;
                if(su<l/2){
                    rs+=j;
                    su++;
                } 
                else ls+=j;
            }
            if(ls==rs) c++;
        }
        return c;
    }
};