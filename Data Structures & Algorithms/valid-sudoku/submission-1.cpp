class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> row;
        unordered_map<int,unordered_set<char>> col;
        map<pair<int,int>,unordered_set<char>> sqrs;

        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c] == '.') continue;

                int val = board[r][c];
                pair<int, int> sqrKey = {r/3,c/3};
                
                if(row[r].count(val)||col[c].count(val)||sqrs[sqrKey].count(val)) return false;

                row[r].insert(val);
                col[c].insert(val);
                sqrs[sqrKey].insert(val);
            }
        }
        return true;

    }
};
