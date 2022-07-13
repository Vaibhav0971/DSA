#include<iostream>
#include<vector>

using namespace std;
    
bool solve(int row, int col, int index, vector<vector<char>>& board, string& word){

    if((row < 0 || row >= board.size()) || (col < 0 || col >= board[0].size()) || (board[row][col] == '-') || (board[row][col] != word[index])){
        return false;
    }       

    if(index == word.length() - 1) return true;

    char temp = board[row][col];
    board[row][col] = '-';

    // move down
    bool down = solve(row + 1, col, index+1, board, word);

    // move left
    bool left = solve(row, col - 1, index+1, board, word);

    // move right
    bool right = solve(row, col + 1, index+1, board, word);

    // move up
    bool up = solve(row - 1, col, index+1, board, word);

    board[row][col] = temp;

    return left || right || up || down;
}
    
    
bool exist(vector<vector<char>>& board, string word) {        
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == word[0] && solve(i, j, 0, board, word)){
                return true;
            }
        }
    }
    
    return false;
}

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "SEE";

    cout<<exist(board, word);
}
