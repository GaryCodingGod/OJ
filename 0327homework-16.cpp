/*//判斷兩個字串是否由相同字母以不同順序組成
//重載 == 運算子的方法，比較兩個 Anagram 物件
class Anagram : public string {
    private:
        string str1;
    public:
        Anagram(string buf): str1(buf) {
            removeNonAlpha();
            changeCase();
        };
        void removeNonAlpha() {
            for (int i = 0; i < str1.length(); ) { //用迴圈檢查是否不是字母
                if (!isalpha(str1[i])) {
                    str1.erase(i, 1);
                }
                else {
                    i++;
                }
            }
        }
        void changeCase() {
            for (int i = 0; i < str1.length(); i++) {
                if (str1[i] >= 'A' && str1[i] <= 'Z') { 
                    str1[i] = str1[i] - 'A' + 'a';
                }
            }
        }
        bool operator==(const Anagram &str) const { //比較兩個 Anagram 物件
            if (str1.length() != str.str1.length()) {
                return false;
            }
            int coutStr1[26] = {0};
            int coutStr[26] = {0};
            for (int i = 0; i < str.str1.length(); i++) {
                coutStr1[str.str1[i] - 'a']++;
            }
            for (int i = 0; i < str1.length(); i++) {
                coutStr[str1[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (coutStr1[i] != coutStr[i]) {
                    return false;
                }
            }
            return true;

        }
};*/
