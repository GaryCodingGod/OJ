// Question: 讀取一個矩陣，包含地雷的佈局，然後生成一個新的矩陣，這個新的矩陣要顯示每個方格周圍地雷的數量
#include <stdio.h>

using namespace std;

void countMines(int row, int col, char filed[100][100]) { //計算每個格子周圍的地雷數量
    int top, bottom, left, right;
    int i, j, m, n, count = 0; 
    
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {

            count = 0;

            if (filed[i][j] != '*') { //如果不是地雷
                for (m = -1; m <= 1; m++) {
                    for (n = -1; n <= 1; n++) {
                        int r = i + m; //計算相鄰方格的行索引
                        int c = j + n;//計算相鄰方格的列索引
                        if (r >= 0 && c >= 0 && r < row && c < col && filed[r][c] == '*')
                            count++;
                    }
                }
                filed[i][j] = count + '0';
                         
            }

            else {
                filed[i][j] = '*';     
            }
        }
    }     
}

int main() {

    int i, j, time;
    int row, col;
    int flag = 0;
    char filed[100][100]; 


    time = 1;
    while (1) {

        scanf("%d %d", &row, &col);

        if (row == 0 && col == 0) {
            break;
        }

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                scanf(" %c", &filed[i][j]);
            }
        }
        countMines(row, col, filed);

        if (flag) //控制輸出格式
            printf("\n");

        printf("Field #%d:\n", time);
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                printf("%c", filed[i][j]);
            }
            printf("\n");
            flag = 1;
        }

        time++;
    }



    return 0;
}