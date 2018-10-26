#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream textFile;
    textFile.open("inputFile.txt");

    int n,i = 0;
    int ara[1000];

    textFile >> n;
    cout << n << endl;
    while(!textFile.eof()){
        textFile >> ara[i];
        cout << ara[i] << " ";
        i++;
    }

    textFile.close();
}
