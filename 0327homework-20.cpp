#include <iostream> 
#include <vector>   
#include <utility>  // pair模板
#include <cstring>
#include <stack>
using namespace std;
char maze[1000][1000];

void createGrid(int M, int N) {
    for (int i = 0; i < (N * 2) + 1; ++i)  //天花板(每一列，都有一个下劃線 _ 當作邊界和空格分隔在加字符表示結尾)
        maze[0][i] = (i % 2 == 1 ? '_' : ' ');
    maze[0][N*2] = '\0';
    for (int j = 1; j < M + 1; ++j) { //天花板以下(j 從 1 開始是因為天花板設在第 0 行)
        for (int k = 0; k < (N * 2) + 1; ++k) 
            maze[j][k] = (k % 2 == 0 ? '|' : '_');
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        stack<pair<int, int>> p; //記錄點 給flip使用
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        createGrid(M, N);

        int checkX = (M+1) - x, checkY = y; // 轉換起始位置到迷宮的索引位置
        int count = 2;
        p.push({checkX, checkY});
        char cmd;
        while (cin >> cmd && count < M * N) { 
            if (cmd == 'U') {
                maze[--checkX][checkY] = ' ';
                p.push({checkX, checkY});
                ++count;
            }
            else if (cmd == 'D') {
                maze[checkX][checkY] = ' ';
                p.push({checkX, checkY});
                ++checkX;
                ++count;
            }
            else if (cmd == 'L') {
                maze[checkX][--checkY] = ' ';
                --checkY;
                p.push({checkX, checkY});
                ++count;
            }
            else if (cmd == 'R') {
                maze[checkX][++checkY] = ' ';
                ++checkY;
                p.push({checkX, checkY});
                ++count;
            } 
            else { 
                int num;
                cin >> num;
                for (int i = 1; i <= num; ++i) p.pop();
                checkX = p.top().first, checkY = p.top().second;
            }
        }
        //確保最後一個命令可執行
        if (cmd == 'U') maze[--checkX][checkY] = ' ';
        else if (cmd == 'D') maze[++checkX][checkY] = ' ';
        else if (cmd == 'L') maze[checkX][--checkY] = ' ';
        else if (cmd == 'R') maze[checkX][++checkY] = ' ';

        for (int i = 0; i < M + 1; ++i) {
            for (int j = 0; j < (N * 2) + 1; ++j) {
                if (i == 0 && j == N * 2) continue;//忽略最後一個多餘的下劃線
                else cout << maze[i][j];
            }
            cout << endl;
        }
        memset(maze, ' ', sizeof(maze));
        cout << endl;
    }
}
//另解:物件導向寫法
/*#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <stack>

using namespace std;

class Maze {
private:
    char maze[1000][1000];
    stack<pair<int, int>> p;

public:
    Maze() {
        memset(maze, ' ', sizeof(maze));
    }

    void createGrid(int M, int N) {
        for (int i = 0; i < (N * 2) + 1; ++i)
            maze[0][i] = (i % 2 == 1 ? '_' : ' ');
        maze[0][N*2] = '\0';
        for (int j = 1; j < M + 1; ++j) {
            for (int k = 0; k < (N * 2) + 1; ++k)
                maze[j][k] = (k % 2 == 0 ? '|' : '_');
        }
    }

    void move(char cmd, int& checkX, int& checkY, int& count) {
        if (cmd == 'U') {
            maze[--checkX][checkY] = ' ';
            p.push({checkX, checkY});
            ++count;
        }
        else if (cmd == 'D') {
            maze[checkX][checkY] = ' ';
            p.push({checkX, checkY});
            ++checkX;
            ++count;
        }
        else if (cmd == 'L') {
            maze[checkX][--checkY] = ' ';
            --checkY;
            p.push({checkX, checkY});
            ++count;
        }
        else if (cmd == 'R') {
            maze[checkX][++checkY] = ' ';
            ++checkY;
            p.push({checkX, checkY});
            ++count;
        }
        else {
            int num;
            cin >> num;
            for (int i = 1; i <= num; ++i) p.pop();
            checkX = p.top().first, checkY = p.top().second;
        }
    }

    void printMaze(int M, int N) {
        for (int i = 0; i < M + 1; ++i) {
            for (int j = 0; j < (N * 2) + 1; ++j) {
                if (i == 0 && j == N * 2) continue;
                else cout << maze[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        Maze maze;
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        maze.createGrid(M, N);

        int checkX = (M+1) - x, checkY = y;
        int count = 2;
        char cmd;
        while (cin >> cmd && count < M * N) {
            maze.move(cmd, checkX, checkY, count);
        }

        if (cmd == 'U') maze.move('U', checkX, checkY, count);
        else if (cmd == 'D') maze.move('D', checkX, checkY, count);
        else if (cmd == 'L') maze.move('L', checkX, checkY, count);
        else if (cmd == 'R') maze.move('R', checkX, checkY, count);

        maze.printMaze(M, N);
        cout << endl;
    }
}*/
