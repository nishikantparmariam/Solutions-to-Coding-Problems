#include <bits/stdc++.h>
using namespace std;


int N = 7;
int **board;
int *dp_left;
int *dp_up_dia;
int *dp_down_dia;

bool canPlace(int row, int col){
    
    if(col==0) return true;
    if(dp_left[row]==1) return false;
    if(dp_up_dia[row-col+N]==1) return false;
    if(dp_down_dia[col+row]==1) return false;
    return true;
    /*int temp = col-1;
    while(temp>=0){
        if(board[row][temp]==1) return false;
        temp--;
    }   

    int tempCol = col-1;
    int tempRow = row-1;
    while(tempRow>=0 && tempCol>=0){
        if(board[tempRow][tempCol]==1) return false;
        tempRow--;
        tempCol--;
    }


    tempCol = col-1;
    tempRow = row+1;
    while(tempRow<N && tempCol>=0){
        if(board[tempRow][tempCol]==1) return false;
        tempRow++;
        tempCol--;
    }

    return true; */
}

void printSolution(int **board){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

bool solveNQueen(int **board, int col){      
    if(col==N) {
        printSolution(board);
        return true;
    }
    bool res = false;
    for(int row=0;row<N;row++){
        if(canPlace(row, col)){            
            board[row][col] = 1;    
            dp_down_dia[col+row] = 1;  
            dp_up_dia[row-col+N]=1;
            dp_left[row]=1;
            if(solveNQueen(board, col+1)){
                res = true;
            }
            board[row][col] = 0;
            dp_down_dia[col+row] = 0;  
            dp_up_dia[row-col+N]=0;
            dp_left[row]=0;
        }            
    }    
    return res;
}


int main(){    
    board = new int*[N];    
    dp_left = new int[400];
    dp_up_dia = new int[400];
    dp_down_dia = new int[400];

    memset(dp_left, 0, sizeof(dp_left));
    memset(dp_up_dia, 0, sizeof(dp_up_dia));
    memset(dp_down_dia, 0, sizeof(dp_down_dia));
    
    for(int i=0;i<N;i++){                        
        board[i] = new int[N];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j] = 0;
        }
    }

    
    solveNQueen(board, 0);    
    return 0;
}