#include<iostream>
#include<vector>

using namespace std;

bool isSafe(int n, int row, int col, vector<vector<int>>& board){    
    for(int i=0; i<board[0].size(); i++){
        // check row
        if(board[row][i] == n) return false;
        // check col
        if(board[i][col] == n) return false;
        // check sub matrix
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == n) return false;
    }   
    
    // number is not used before, so its safe
    return true;
}

bool solve(vector<vector<int>>& board){
    int n = board[0].size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 0){
                for(int val=1; val<=9; val++){
                    if(isSafe(val, i, j, board)){
                        board[i][j] = val;
                        bool isFurtherSolutionPossible = solve(board);
                        if(isFurtherSolutionPossible) return true;
                        else board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}


void solveSudoku(vector<vector<int>>& sudoku){
    solve(sudoku);
}

int main(){
    // vector<vector<int>> ans = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
    //                            {5, 2, 0, 0, 0, 0, 0, 0, 0},
    //                            {0, 8, 7, 0, 0, 0, 0, 3, 1},
    //                            {0, 0, 3, 0, 1, 0, 0, 8, 0},
    //                            {9, 0, 0, 8, 6, 3, 0, 0, 5},
    //                            {0, 5, 0, 0, 9, 0, 6, 0, 0},
    //                            {1, 3, 0, 0, 0, 0, 2, 5, 0},
    //                            {0, 0, 0, 0, 0, 0, 0, 7, 4},
    //                            {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    vector<vector<int>> ans = {{ 5 , 3 , 0 , 0 , 7 , 0 , 0 , 0 , 0 },
                               { 6 , 0 , 0 , 1 , 9 , 5 , 0 , 0 , 0 },
                               { 0 , 9 , 8 , 0 , 0 , 0 , 0 , 6 , 0 },
                               { 8 , 0 , 0 , 0 , 6 , 0 , 0 , 0 , 3 },
                               { 4 , 0 , 0 , 8 , 0 , 3 , 0 , 0 , 1 },
                               { 7 , 0 , 0 , 0 , 2 , 0 , 0 , 0 , 6 },
                               { 0 , 6 , 0 , 0 , 0 , 0 , 2 , 8 , 0 },
                               { 0 , 0 , 0 , 4 , 1 , 9 , 0 , 0 , 5 },
                               { 0 , 0 , 0 , 0 , 8 , 0 , 0 , 7 , 9 }};
    solveSudoku(ans);

    for(int i=0; i<ans[0].size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;

}