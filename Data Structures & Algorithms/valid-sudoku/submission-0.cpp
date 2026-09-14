class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //hashset for row, col and square 
        for(int i=0;i<9;i++){
            unordered_map<char,bool> rowVisited;
            unordered_map<char,bool> colVisited;
            unordered_map<char,bool> sqVisited;
            for(int j=0;j<9;j++){
                int row = board[i][j];
                if(row != '.'){
                    if( rowVisited[row]) return false;
                    rowVisited[row] = true;
                }

                int column = board[j][i];
                if(column != '.'){
                    if( colVisited[column]) return false;
                    colVisited[column] = true;
                }

                int boxRow = 3 * (i/3) + (j/3);
                int boxCol = 3 * (i%3) + (j%3);
                int sq = board[boxRow][boxCol];
                if(sq != '.'){
                    if( sqVisited[sq]) return false;
                    sqVisited[sq] = true;
                }

            }
        }
        return true;
    }
};
