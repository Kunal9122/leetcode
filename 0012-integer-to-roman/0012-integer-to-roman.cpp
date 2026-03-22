class Solution {
public:
    string intToRoman(int num) {
        int c=0;
        string ans="";
        unordered_map<int,char>mp;
        mp[1]='I';
        mp[5]='V';
        mp[10]='X';
        mp[50]='L';
        mp[100]='C';
        mp[500]='D';
        mp[1000]='M';
        while(num){
            int j=num%10;
            int r=j;
            int b=pow(10,c);
            if(r<=3){
                for(int i=0;i<r;i++){
                    ans=mp[b]+ans;
                }
            }
            else if(r==4){
                ans=mp[5*b]+ans;
                ans=mp[b]+ans;
                
            }
            else if(r<=8){
                
                for(int i=0;i<r-5;i++){
                    ans=mp[b]+ans;
                }
                ans=mp[5*b]+ans;
            }
            else if(r==9){
                ans=mp[10*b]+ans;
                ans=mp[b]+ans;
                
            }
            c++;
            num/=10;
        }
        return ans;
    }
};