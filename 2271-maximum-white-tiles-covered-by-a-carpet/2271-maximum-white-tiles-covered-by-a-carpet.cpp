class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n=tiles.size();
        sort(tiles.begin(),tiles.end());
        long long c=0,maxLen=0;
        int j=0;
        for(int i=0;i<n;i++){
           c+=tiles[i][1]-tiles[i][0]+1;
           while(j <= i&&tiles[i][1]-tiles[j][0]+1>carpetLen){
            int part=max(0,carpetLen-(tiles[i][0]-tiles[j][0]));
            maxLen=max(maxLen,c-(tiles[i][1]-tiles[i][0]+1)+part);
            c-=tiles[j][1]-tiles[j][0]+1;
            j++;
           }
           maxLen=max(maxLen,c);

        }
        return (int) maxLen;
    }
};