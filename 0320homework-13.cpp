#include <iostream>
#include <string>

#define MAX 100
using namespace std;

class DoOperations {
    private:
        int initialMatrix[MAX][MAX];
        int size;
        bool isEmpty;

    public:
        DoOperations(): size(0), initialMatrix{-1} {}
        
        void initializer() {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    initialMatrix[i][j] = -1;
                }
            }
        }

        void InputMatrix() {
            cin >> size;
            if (size > 0) {
                isEmpty = false;
                initializer(); 
                for (int i = 0; i < size; i++) {    //重置方陣
                    for (int j = 0; j < size; j++) {
                        cin >> initialMatrix[i][j];
                    }
                }
            }
            else {
                isEmpty = true;
            }
        }

        void rotateRight() { //先將矩陣轉置，在順時針旋轉矩陣
            if (isEmpty || initialMatrix[0][0] == -1) {
                cout << "No element in matrix can be rotated." << endl;
                return;
            }
            
            for (int i = 0; i < size; i++) {
                for (int j = i; j < size; j++) {
                    swap(initialMatrix[i][j], initialMatrix[j][i]);
                }
            }
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size / 2; j++) {
                    swap(initialMatrix[i][j], initialMatrix[i][size - j - 1]);
                }
            }
            
        }
        void rotateLeft() {
            if (isEmpty || initialMatrix[0][0] == -1) {
                cout << "No element in matrix can be rotated." << endl;
                return;
            }
    
            for (int i = 0; i < size; i++) {
                for (int j = i; j < size; j++) {
                    swap(initialMatrix[i][j], initialMatrix[j][i]);
                }
            }
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size / 2; j++) {
                    swap(initialMatrix[j][i], initialMatrix[size - j - 1][i]);
                }
            }
        }
        void printMatrix() {
            
            if (isEmpty || initialMatrix[0][0] == -1) {
                cout << "No element in matrix can be printed." << endl;
                return;
            }

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    cout << initialMatrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
};

int main() {
    DoOperations operate;
    string command;

    while (getline(cin, command) && command != "stop") { 

        if (command == "scan") {
            operate.InputMatrix(); //調用 cin.ignore() 忽略之後的換行符，因為 getline 會讀取換行符之前的所有內容，而 cin>>函數則會留下換行符。
            cin.ignore();
        }
        else if (command == "rotate right") {
            operate.rotateRight();
        }

        else if (command == "rotate left") {
            operate.rotateLeft();
        }
        else if (command == "print") {
            operate.printMatrix();
        }
        else {
            cout << "unknown" << endl;
        }     
    }
}
