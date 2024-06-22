#include <iostream>
using namespace std;
#define SIZE 100

class GetMaxSquare {

    private:
        int ctr_row, ctr_col, row, col;
        int max_side;
        char matrix[SIZE][SIZE];

    public:
        GetMaxSquare(int cr, int cc, int r, int c, char m[SIZE][SIZE]): ctr_row(cr), ctr_col(cc), row(r), col(c), max_side(0) {

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    matrix[i][j] = m[i][j];
                }
            }
        }

        int countMaxSide() { //計算最大邊長的方法
            int flag = 0, side = 1;
            int top = ctr_row - 1, bottom = ctr_row + 1, left = ctr_col - 1, right = ctr_col + 1;

            while (top >= 0 && bottom < row && left >= 0 && right < col) {

                for (int i = left; i <= right; i++) {
                    if (matrix[top][i] != matrix[ctr_row][ctr_col]) {
                        flag++;
                        break;
                    }
                }

                for (int j = top; j <= bottom; j++) {
                    if (matrix[j][right] != matrix[ctr_row][ctr_col]) {
                        flag++;
                        break;
                    }
                }

                for (int m = right; m >= left; m--) {
                    if (matrix[bottom][m] != matrix[ctr_row][ctr_col]) {
                        flag++;
                        break;
                    }
                }

                for (int n = bottom; n >= top; n--) {
                    if (matrix[n][left] != matrix[ctr_row][ctr_col]) {
                        flag++;
                        break;
                    }
                }

                if (flag != 0) {
                    break;
                }

                else {

                    side += 2;
                    top--;
                    bottom++;
                    left--;
                    right++;
                }
            }
            return side;
        }

        void printMaxSide() {
            max_side = GetMaxSquare::countMaxSide();
            cout << max_side << endl;
        }

};

int main() {

    int testcases;
    int M, N, Q;
    int r, c;
    char matrix[SIZE][SIZE];

    cin >> testcases;

    while (testcases--) {
        cin >> M >> N >> Q;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
            }
        }
        cout << M << " " << N << " " << Q << endl;

        for (int k = 0; k < Q; k++) {
            cin >> r >> c;
            GetMaxSquare gms(r, c, M, N, matrix);
            gms.printMaxSide();
        }
    }


    return 0;
}