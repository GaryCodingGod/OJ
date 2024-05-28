#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Date {
private:
    int day;  //從1700年1月1日以來的天數

    bool isLeap(int y) const {
        return ((!(y % 4) && (y % 100)) || !(y % 400));
    }

public:
    Date() : day(620548) {}

    Date(int _day) : day(_day) {}

    // 用字串初始化日期
    Date(string s) {
        day = 620548;
        const int month_i[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};  
        string year = s.substr(0, 4), month_s = s.substr(4, 2), day_s = s.substr(6, 2);
        bool leap = isLeap(stoi(year));
        for (int i = 1700; i < stoi(year); i++) {
            day += isLeap(i) ? 366 : 365;
        }
        day += month_i[stoi(month_s) - 1] + (stoi(month_s) > 2 && leap) + stoi(day_s);
    }

    int getDay() const {
        return day;
    }

    // 將日期轉換為 "MM/DD/YYYY" 格式的字符串
    string toString() const {
        int tmp = day - 620548, y = 1700, month = 0;
        int month_arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string s;
        while (tmp >= 366) {
            tmp -= isLeap(y) ? 366 : 365;
            y++;
        }
        if (isLeap(y)) {
            month_arr[1]++;
        }
        for (int i = 0; i < 12; i++) {
            if (tmp > month_arr[i]) {
                tmp -= month_arr[i];
            } else {
                month = i + 1;
                break;
            }
        }
        if (tmp == 0) {
            if (month == 1) {
                month = 12;
                tmp = month_arr[month - 1];
                y--;
            } else {
                month--;
                tmp = month_arr[month - 1];
            }
        }
        s = to_string(month) + "/" + to_string(tmp) + "/" + to_string(y);
        return s;
    }
};

int main() {
    int time = 1, NX, NR;
    while (scanf("%d %d", &NX, &NR)) {
        if (NX == 0 && NR == 0)
            break;

        // 使用 map 來儲存日期索引
        map<int, int> index;
        Date record[NX][2], new_date[NR][2];
        string s1, s2;

        // 讀取已存在的日期範圍
        for (int i = 0; i < NX; i++) {
            cin >> s1 >> s2;
            record[i][0] = Date(s1);
            record[i][1] = Date(s2);
            int tmp1 = record[i][0].getDay(), tmp2 = record[i][1].getDay();
            index[tmp1] = 0;
            index[tmp1 + 1] = 0;
            index[tmp1 - 1] = 0;
            index[tmp2] = 0;
            index[tmp2 + 1] = 0;
            index[tmp2 - 1] = 0;
        }

        for (int i = 0; i < NR; i++) {
            cin >> s1 >> s2;
            new_date[i][0] = Date(s1);
            new_date[i][1] = Date(s2);
            int tmp1 = new_date[i][0].getDay(), tmp2 = new_date[i][1].getDay();
            index[tmp1] = 0;
            index[tmp1 + 1] = 0;
            index[tmp1 - 1] = 0;
            index[tmp2] = 0;
            index[tmp2 + 1] = 0;
            index[tmp2 - 1] = 0;
        }

        // 建立日期索引
        int size = 0;
        vector<int> date;
        for (auto it = index.begin(); it != index.end(); it++) {
            it->second = size++;
            date.push_back(it->first);
        }

        // 檢查需要輸出的日期範圍
        vector<int> mark(size, 0);
        for (int i = 0; i < NR; i++) {
            int l = index[new_date[i][0].getDay()];
            int r = index[new_date[i][1].getDay()];
            for (int j = l; j <= r; j++) {
                mark[j] = 1;
            }
        }

        // 排除已存在的日期範圍
        for (int i = 0; i < NX; i++) {
            int l = index[record[i][0].getDay()];
            int r = index[record[i][1].getDay()];
            for (int j = l; j <= r; j++) {
                mark[j] = 0;
            }
        }

        // 輸出結果
        printf("Case %d:\n", time++);
        bool flag = false;
        for (int i = 0; i < mark.size(); i++) {
            if (mark[i] == 1) {
                flag = true;
                Date tmp(date[i]);
                cout << tmp.toString();
                if (i + 1 < mark.size() && mark[i + 1] == 1) {
                    printf(" to ");
                    while (i + 1 < mark.size() && mark[i + 1] == 1)
                        i++;
                    tmp = Date(date[i]);
                    cout << tmp.toString();
                }
                printf("\n");
            }
        }
        if (!flag)
            printf("No additional quotes are required.\n");
    }
    return 0;
}

//另解:
/*
#include <stdio.h> 
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 128;
map<int, int> R;
int prevDay(int x) {
 int mday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
 int yy = x/10000, mm = x%10000/100, dd = x%100;
 if ((yy%4 == 0 && yy%100 != 0) || yy%400 == 0)
  mday[2] = 29;
 if (mm == 1 && dd == 1) {
  yy--, mm = 12, dd = 31;
 } else {
  dd--;
  if (dd < 1)   mm--, dd = mday[mm];
 }
 return yy * 10000 + mm * 100 + dd;
}
int nextDay(int x) {
 int mday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
 int yy = x/10000, mm = x%10000/100, dd = x%100;
 if ((yy%4 == 0 && yy%100 != 0) || yy%400 == 0)
  mday[2] = 29;
 dd++;
 if (dd > mday[mm]) dd = 1, mm++;
 if (mm == 13)  mm = 1, yy++;
 return yy * 10000 + mm * 100 + dd;
}
void record(int x) {
 R[x] = 0, R[nextDay(x)] = 0, R[prevDay(x)] = 0;
// printf("-- %d %d %d\n", prevDay(x), x, nextDay(x));
}
void printDate(int x) {
 int yy = x/10000, mm = x%10000/100, dd = x%100;
 printf("%d/%d/%d", mm, dd, yy);
}
int main() {
 int cases = 0;
 int N, M;
 int aSt[MAXN], aEd[MAXN];
 int bSt[MAXN], bEd[MAXN];
 while (scanf("%d %d", &N, &M) == 2) {
  if (N == 0 && M == 0)
   break;
   
  R.clear();
  for (int i = 0; i < N; i++) {
   scanf("%d %d", &aSt[i], &aEd[i]);
   record(aSt[i]);
   record(aEd[i]);
  }
  for (int i = 0; i < M; i++) {
   scanf("%d %d", &bSt[i], &bEd[i]);
   record(bSt[i]);
   record(bEd[i]);
  }
  
  int size = 0;
  vector<int> date;
  for (map<int, int>::iterator it = R.begin();
   it != R.end(); it++)
   it->second = size++, date.push_back(it->first);
   
  vector<int> mark(size, 0);
  for (int i = 0; i < M; i++) {
   int l = R[bSt[i]], r = R[bEd[i]];
   for (int j = l; j <= r; j++)
    mark[j] = 1;
  }
  for (int i = 0; i < N; i++) {
   int l = R[aSt[i]], r = R[aEd[i]];
   for (int j = l; j <= r; j++)
    mark[j] = 0;
  }
  printf("Case %d:\n", ++cases);
  int has = 0;
  for (int i = 0; i < mark.size(); i++) {
   if (mark[i] == 1) {
    has = 1;
    printDate(date[i]);
    if (i+1 < mark.size() && mark[i+1] == 1) {
     printf(" to ");
     while (i+1 < mark.size() && mark[i+1] == 1)
      i++;
     printDate(date[i]);
    }
    printf("\n");
   }
  }
  
  if (!has)
   puts("No additional quotes are required.");
 }
 return 0;
}
*/