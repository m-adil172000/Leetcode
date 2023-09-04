class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            unordered_map<char,int>mp;
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]==0){
                        mp[board[i][j]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
            mp.clear();
        }
        for(int i=0; i<9; i++){
            unordered_map<char,int>mp;
            for(int j=0; j<9; j++){
                if(board[j][i]!='.'){
                    if(mp[board[j][i]]==0){
                        mp[board[j][i]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
            mp.clear();
        }

        unordered_map<char,int>mp;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]==0){
                        mp[board[i][j]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        mp.clear();
        for(int i=0; i<3; i++){
            for(int j=3; j<6; j++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]==0){
                        mp[board[i][j]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        mp.clear();
        for(int i=0; i<3; i++){
            for(int j=6; j<9; j++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]==0){
                        mp[board[i][j]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        mp.clear();
        for(int i=3; i<6; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]==0){
                        mp[board[i][j]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        mp.clear();
        for(int i=3; i<6; i++){
            for(int j=3; j<6; j++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]==0){
                        mp[board[i][j]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        mp.clear();
        for(int i=3; i<6; i++){
            for(int j=6; j<9; j++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]==0){
                        mp[board[i][j]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        mp.clear();
        for(int i=6; i<9; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]==0){
                        mp[board[i][j]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        mp.clear();
        for(int i=6; i<9; i++){
            for(int j=3; j<6; j++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]==0){
                        mp[board[i][j]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        mp.clear();
        for(int i=6; i<9; i++){
            for(int j=6; j<9; j++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]==0){
                        mp[board[i][j]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        return true;

    }
};