#include <iostream>
using namespace std;

int ctl, num[4];
string inp;

bool check(string s) {
    int arr[10] = {0};
    if (s.size() != 4) {
        cout << "Wrong input length. Please enter again.\n";
        return 0;
    }
    for (int i = 0;i < s.size(); i++) if (s[i] < '0' || s[i] > '9') {
        cout << "Illegal character detected. Please enter again.\n";
        return 0;
    }
    for (int i = 0;i < s.size(); i++) {
        arr[s[i] - '0'] += 1;
        if (arr[s[i] - '0'] > 1) {
            cout << "Duplicate digit detected. Please enter again.\n";
            return 0;
        }
    }
    return 1;
}

int main() {
    cout << "Please choose mode. 1 - random, 2 - user input :\n";
    cin >> ctl;
    getline(cin, inp);
    if (ctl == 1) {
        // random
        for (int i = 0;i < 4; i++) {
            num[i] = rand() % 10;
        }
        for (int i = 0;i < 4;i++) {
            for (int j = i + 1;j < 4; j++) {
                while (num[j] == num[i]) num[j] = rand() % 10;
            }
        }
   } 
    else {
        cout << "Please enter correct answer :\n";
        getline(cin, inp);
        while (!check(inp)) {
            getline(cin, inp);
        }
        for (int i = 0;i < 4; i++) num[i] = inp[i] - '0';
    }
    int cnt = 1;
    for (cnt = 1;cnt <= 7; cnt++) {
        int a = 0, b = 0;
        cout << "Please enter your guess number :\n";
        getline(cin, inp);
        while (!check(inp)) {
            getline(cin, inp);
        }
        for (int i = 0;i < 4; i++) {
            for (int j = 0;j < 4; j++) {
                if (inp[j] - '0' == num[i]) {
                    if (j == i) a++;
                    else b++;
                }
            }
        }
        cout << "Hint " << cnt <<  " : " << a << "A" << b << "B\n";
        if (a == 4) {
            cout << "Correct! You only guessed for " << cnt << " times.\n";
            return 0;
        }
    }
    cout << "You lose this game! QQ\nThe correct answer is : " << num[0] << num[1] << num[2] << num[3] << endl;

}