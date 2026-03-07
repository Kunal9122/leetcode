class Solution {
public:
    int maxVowels(string s, int k) {
       int maxLen=0,c=0;
       for(int i=0;i<k;i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') maxLen++;
       } 
       c=maxLen;
       int i=0,j=k,n=s.size();
       while(j<n){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            c--;
        }
        if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
            c++;
        }
        i++;
        j++;
        if(c>maxLen) maxLen=c;
       }
       return maxLen;
    }
};