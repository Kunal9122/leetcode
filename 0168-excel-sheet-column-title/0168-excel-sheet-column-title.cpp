class Solution {
public:
    string convertToTitle(int columnNumber) {
       string str="";
       while(columnNumber>0){
        columnNumber--;
        str+=(columnNumber%26+'A');
        columnNumber/=26;
       } 
       reverse(str.begin(),str.end());
       return str;
    }
};