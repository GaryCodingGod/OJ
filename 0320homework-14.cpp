#include <bits/stdc++.h>
using namespace std;

int judge(string a){ //檢查字串是否為回文
    //用兩個索引攔檢查字串對應是否相等
    for(int i = 0, j = a.length()-1; i < a.length() / 2 && j >= a.length() / 2; i++, j--){  
        if(a[i] != a[j]) 
        return 0;
    }
    return 1;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        string a, b;
        cin >> a;

    // 確認a是否只有一位數，如果是小於5的個位數，就不需要做其他的檢查，因為如果我把它加到它自己上，得到的數字一定是個迴文
        if(a.length() == 1 && a[0] - '0' < 5){ 
            cout << "1" << (a[0]-'0') * 2 << endl;
              continue;//而2加2得到了4，這是個迴文。所以，我們得到的結果是「1 4」，意思是「經過1次操作後得到迴文4」。

        }

        b = a;
        reverse(b.begin(), b.end());//如果不是回文，將字串a翻轉，存儲到字串b中。

        int flag = 0, count = 1;
        string c;
        while(1){
            int sum = stoi(a) + stoi(b); //將字串轉整數的函式
            c = to_string(sum);
            
            flag = judge(c);
            if(flag == 0){
                a = b = c;
                reverse(b.begin(), b.end());
                count++;
            } else{
                break;
            }
        }

        cout << count << " " << c << endl;
    }
}