#include <iostream>
#include <cstring>

using namespace std;

int main () {
    string str;
    cin >> str;
    int length = str.length();

    if(((int)str[0] >= 65 && (int)str[0] <= 90) && ((int)str[1] >= 65 && (int)str[1] <= 90)){
        string extractedColumn = "";
        string extractedRow = "";
        int i;
        for(i = 0; i < length; i++) {
            if((int)str[i] >= 48 && (int)str[i] <= 57) {
                break;
            }else {
                extractedColumn += str[i];
            }
        }
        for(int j = i; j < length; j++) {
            extractedRow += str[j];
        }

        int column;
        if(extractedColumn.length() == 1) {
            column = (int)extractedColumn[0] - 65;
        }else if(extractedColumn.length() == 2) {
            column = 26 * ((int)extractedColumn[0] - 64) + ((int)extractedColumn[1] - 64);
        }else if(extractedColumn.length() == 3) {
            column = 26 * (26 * ((int)extractedColumn[0] - 64) + ((int)extractedColumn[1] - 64)) + ((int)extractedColumn[2] - 64);
        }else if(extractedColumn.length() == 4) {
            column = 26 * (26 * (26 * ((int)extractedColumn[0] - 64) + ((int)extractedColumn[1] - 64)) + ((int)extractedColumn[2] - 64)) + ((int)extractedColumn[3] - 64);
        }
        cout << "R" << extractedRow << "C" << column << endl;
    }
    else {
        string column = "";
        string row = "";
        int i;
        for(i = 1; i < length; i++) {
            if(str[i] == 'C')
                break;
            row += str[i];
        }
        for(int j = i+1; j < length; j++) {
            column += str[j];
        }
        int columnNumber = stoi(column);

        int storage[column.length()];
        int index = 0;
        while(columnNumber > 0) {
            storage[index++] = columnNumber % 26;
            columnNumber = columnNumber / 26;
        }

        string resultantColumn = "";
        for(int i = index - 1; i >= 0; i--) {
            resultantColumn += (char) (storage[i] + 64);
        }
    }
}


















