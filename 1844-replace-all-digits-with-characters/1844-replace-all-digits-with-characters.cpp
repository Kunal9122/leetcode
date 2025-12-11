class Solution {
public:
    string replaceDigits(string s) {
        string str="";
        str+=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i] >= '0' && s[i] <= '9'){
                char d = s[i-1];    
                char e = s[i];  
                int k = e - '0'; 
                char n = d + k; 
                str += n;
            }
            else{
                str+=s[i];
            }
        }
        return str;
    }
};