#include <stdio.h>
//8皇后问题
void backtrack(int(*board)[8],int row);
int isValid(int(*board)[8],int row,int col);

int res = 0;//记录解的数量

int main(){
    int board[8][8] = {0}; //初始化棋盘
    backtrack(board,0);
    printf("%d",res);
}

//回溯算法
void backtrack(int(*board)[8],int row){
    if(row == 8){ //row==8说明当前解法可行
        res++; //解的数量++
        return;
    }

    for(int col = 0;col < 8;col++) {
        //遍历当前列，依次尝试当前位置是否可行
        if (!isValid(board, row, col))
            continue;
        board[row][col] = 1; //做选择
        backtrack(board, row + 1);//进入下一行决策
        board[row][col] = 0; //撤销选择
    }
}

//判断是否可以在当前位置放置皇后，注意，这里只需要判断前面的行（剪支）
int isValid(int(*board)[8],int row,int col){
    int i,j;
    //检查列中是否与当前位置皇后冲突
    for(i = 0;i < row;i++) {
        if (board[i][col] == 1)
            return 0;
    }
    //检查右上方是否与当前位置皇后冲突
    for(i = row - 1, j = col + 1;i >= 0 && j < 8;i--,j++) {
        if (board[i][j] == 1)
            return 0;
    }
    //检查左上方是否与当前位置皇后冲突
    for(i = row - 1,j = col - 1; i >= 0 && j >= 0;i--,j--) {
        if (board[i][j] == 1)
            return 0;
    }
    return 1;
}
