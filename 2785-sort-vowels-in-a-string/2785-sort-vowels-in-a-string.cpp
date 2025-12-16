class Solution {
public:
    string sortVowels(string s) {
        string str1="";
        string str2="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') str1+=s[i];
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') str2+=s[i];
        }
        str1+=str2;
        sort(str1.begin(),str1.end());
        int c=str2.size();
        int j=0,k=0;
        for(int i=0;i<s.size();i++){
            if((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]  =='I'||s[i]=='O'||s[i]=='U')){
                s[i]=str1[j];
                j++;
            }
        }
        return s;
    }
};