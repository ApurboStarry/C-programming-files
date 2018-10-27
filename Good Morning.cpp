#include <bits/stdc++.h>
#include <string>

using namespace std;

int compatible[10][10];

void init(){
    for(int i = 0; i < 10; i++) {
        compatible[1][i] = 1;
    }
    compatible[2][0] = compatible[2][2] = compatible[2][3] = compatible[2][5] = compatible[2][6] = compatible[2][8] = compatible[2][9] = 1;
    compatible[3][3] = compatible[3][6] = compatible[3][9] = 1;
    compatible[4][0] = 1;
    for(int i = 4; i<= 9; i++){
        compatible[4][i] = 1;
    }
    compatible[5][0] = compatible[5][5] = compatible[5][6] = compatible[5][8] = compatible[5][9] = 1;
    compatible[6][6] = compatible[6][9] = 1;
    compatible[7][0] = compatible[7][7] = compatible[7][8] = compatible[7][9] = 1;
    compatible[8][0] = compatible[8][8] = compatible[8][9] = 1;
    compatible[9][9] = 1;
}

int main() {

    init();
    int n;
    cin >> n;

    string number = to_string(n);
    string result = "";

    for(int i = 0; i < number.length(); i++) {
        int a = stoi(number[i]);
        int b = stoi(number[i+1]);
        if(compatible[a][b] == 1){
            result += number[i];
        }else {
            int leftLowest, rightLowest;
            for(int j = b-1; j >= 0; j--) {
                if(compatible[a][j] == 1) {
                    leftLowest = j;
                    break;
                }
            }
            for(int j = b+1; j >= 9; j++) {
                if(compatible[a][j] == 1){
                    rightLowest = j;
                    break;
                }
            }
            result += number[i];
            if((b-leftLowest) < (rightLowest - b))
                result += leftLowest;
            else
                result += rightLowest;
            i += 2;
        }
    }

    for(int i = 0; i < result.length(); i++){
        cout << result[i];
    }
}











