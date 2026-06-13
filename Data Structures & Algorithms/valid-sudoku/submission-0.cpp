class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int>mp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mp.count(board[i][j])) return false;
                if(board[i][j]!='.') mp[board[i][j]]++;
            }
            mp.clear();
        }

        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                if(mp.count(board[i][j])) return false;
                if(board[i][j]!='.') mp[board[i][j]]++;
            }
            mp.clear();
        }

        for(int i=0;i<=6;i+=3){
            for(int j=0;j<=6;j+=3){
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(mp.count(board[k][l])) return false;
                        if(board[k][l]!='.') mp[board[k][l]]++;
                    }
                }
                mp.clear();
            }
        }
        return true;
        
    }
};
