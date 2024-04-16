#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Translater {
    private:
        string token, subtoken; 
        string binary, funct, reg;
        int order[3];
        vector <string> parts;
        size_t pos = 0;

    public:

        Translater(string instructions): token(instructions), order{0} {
        }

        void split() {
            while ((pos = token.find(' ')) != string::npos) {
                subtoken = token.substr(0, pos);
                parts.push_back(subtoken);
                token.erase(0, pos + 1);
            }
            parts.push_back(token);
        }

        void check_type() {
            if (parts[0] == "add" || parts[0] == "sub" || parts[0] == "and" || parts[0] == "or") {
                arrange();
                checkRegister();
                chechFunct();
                R_type_print();
            }
            else if (parts[0] == "addi") {
                arrange();
                checkRegister();
                changeToBinary();
                I_type_print();
            }
        }
       
        void arrange() {
            if (parts[0] == "addi") {
                swap(parts[1], parts[2]);
            }
            else {
                swap(parts[1], parts[2]);
                swap(parts[2], parts[3]);
            }
        }
        void checkRegister() {
            int n;
            if (parts[0] == "addi")
                n = 2;
            else
                n = 3;

            for (int i = 1; i <= n; i++) {
                switch((parts[i][2])) {
                    case '0':
                        reg += "01000";
                        break;
                    case '1':
                        reg += "01001";
                        break;
                    case '2':
                        reg += "01010";
                        break;
                    case '3':
                        reg += "01011";
                        break;
                    case '4':
                        reg += "01100";
                        break;
                    case '5':
                        reg += "01101";
                        break;
                    case '6':
                        reg += "01110";
                        break;
                    case '7':
                        reg += "01111";
                        break;
                }
            }
        }

        void changeToBinary() { //addi 後面會有數字
            int num = atoi(parts[3].c_str());
            while (num > 0) {
                binary = to_string(num % 2) + binary;
                num /= 2;
            }
        }
        void chechFunct() {
            if (parts[0] == "add") {
                funct = "100000";
            }
            else if (parts[0] == "sub") {
                funct = "100010";
            }
            else if (parts[0] == "and") {
                funct = "100100";
            }
            else if (parts[0] == "or") {
                funct = "100101";
            }  
        }
        void R_type_print() {
            cout << "000000" << reg << "00000" << funct << endl;
        }
        void I_type_print() {
            string immediate = "0000000000000000"; // 用字串去取代數字
            immediate.replace(16 - binary.length(), binary.length(), binary);
            cout << "001000" << reg << immediate << endl;
        }
};

string remove(string str) {
    string result;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ',') {
            result += str[i];
        }
    }
    return result;
}

int main() {
    
    
    string instructions;
    string token;

    while (getline(cin, instructions)) {
        token = remove(instructions);//remove 可以把逗號去掉
        Translater trans(token);
        trans.split();
        trans.check_type();
    } 
    return 0;
}