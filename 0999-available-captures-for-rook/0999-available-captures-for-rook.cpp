class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row=-1,col=-1;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    row=i;
                    col=j;
                    break;
                }
            }
            if(row!=-1) break;
        }
        int ans=0;
   
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {

            int r = row + dr[k];
            int c = col + dc[k];

            while (r >= 0 && r < 8 && c >= 0 && c < 8) {

                if (board[r][c] == 'B')
                    break;

                if (board[r][c] == 'p') {
                    ans++;
                    break;
                }

                r += dr[k];
                c += dc[k];
            }
        }

        return ans;
     }
};