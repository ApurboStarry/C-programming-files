#include<iostream>

using namespace std;

void asp(int start[], int finish[],int fl){
    int temp;
    for(int i = 0;i<fl-1;i++){
        for(int j = 0;j<fl - i -1;j++){
            if(finish[j] > finish[j+1]){
                temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;

                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }

    cout << "Maximum number of activities are : ";
    cout << 0 << " ";
    int flag = finish[0];
    for(int i = 1;i<fl;i++){
        if(start[i] >= flag){
            cout << i << " ";
            flag = finish[i-1];
        }
    }

}

int main(){
    int start[] = {1,5,8,0,3,5};
    int finish[] = {2,7,9,6,4,9};
    int fl = sizeof(finish) / sizeof(finish[0]);
    cout << fl << endl;
    asp(start,finish,fl);

    cout << "\nStart array : ";
    for(int i = 0;i<fl;i++){
        cout << start[i] << " ";
    }

    cout << "\nfinish array : ";
    for(int i =0 ;i< fl ;i++){
        cout << finish[i] << " ";
    }
}
