/*************************************************************************
	> File Name: LeetCode_36.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月13日 星期日 18时59分46秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
   int rom[9] = {0}, col[9] = {0}, gong[9] = {0};
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            int val = board[i][j] - '0';
            if (val + '0' == '.') continue;
            int ind = i / 3 * 3 + j / 3;
            if (rom[i] & (1 << val)) return false;
            if (col[j] & (1 << val)) return false;
            if (gong[ind] & (1 << val)) return false;
            rom[i] |= (1 << val);
            col[j] |= (1 << val);
            gong[ind] |= (1 << val);
        }
    }
    return true;
}

int main() {
 
    return 0;
}
