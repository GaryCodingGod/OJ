//Question:  to write the same program which can decode that mad teacher’s speech!
//Input: The input file will contain only one test case i.e. the encoded message. and The test case consists of one or more words.

#include <iostream>
#include <cstring>

using namespace std;

    class Decoder {
        private:
            char word;

        public:
            Decoder(char w): word(w) {};

            void decodeTheWord() {
                string input = " 234567890-=ertyuiop[]\\dfghjkl;'cvbnm,./"; 
                string output = " `1234567890qwertyuiop[asdfghjklzxcvbnm,";//這個是找到字串對應的字母

                for (int i = 0; i < input.length(); i++) {
                    if (input[i] == word) {
                        cout << output[i];
                    }
                }
                if (word == '\n')
                    cout << endl;
                
            }
    };

    int main() {
        char word;

        do {
            
            word = getchar();
            Decoder d(word);
            d.decodeTheWord();
            
        } while (word != EOF);

        return 0;
    }