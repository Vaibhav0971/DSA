#include<iostream>
#include<vector>

using namespace std;

bool isSafe(int row, int col, int n, vector<vector<int>>& board){
    // check in row
    int tempCol = col;
    int tempRow = row;    
    while(tempCol >= 0){
        if(board[tempRow][tempCol] == 1) return false;
        tempCol--;
    }
    // check upper in diagonal
    tempCol = col;
    tempRow = row;    
    while(tempCol >= 0 && tempRow >=0){
        if(board[tempRow][tempCol] == 1) return false;
        tempCol--;
        tempRow--;
    }
    // check lower in diagonal
    tempCol = col;
    tempRow = row;    
    while(tempCol >= 0 && tempRow < n){
        if(board[tempRow][tempCol] == 1) return false;
        tempCol--;
        tempRow++;
    }
    
    // no queen attacking, so its safe
    return true;
}

void addSolution(int n, vector<vector<int>>& board, vector<vector<int>>& ans){
    vector<int> temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int col, int n, vector<vector<int>>& board, vector<vector<int>>& ans){
    if(col == n){
        addSolution(n, board, ans);
        return;
    }
    
    for(int row=0; row<n; row++){
        if(isSafe(row, col, n, board)){
            board[row][col] = 1;
            solve(col+1, n, board, ans);
            // backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n){
	vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;   
    
    int col = 0;
    solve(col, n, board, ans);
	
    return ans;
}

int main(){
    int n = 4;
    vector<vector<int>> ans = nQueens(n);

    for(int i=0; i<ans[0].size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<", ";
            if((j+1)%n == 0) cout<<endl;
        }
        cout<<endl;
        cout<<endl;
    }
    
}