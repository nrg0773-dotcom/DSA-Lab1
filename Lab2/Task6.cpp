#include <iostream>
using namespace std;
int main(){

    int total[5] = {0};
    int **ppt = new int*[5];

    for(int i = 0 ; i < 5 ; i++){
        *(ppt + i) = new int[5];
        for(int j = 0 ; j < 5 ;j++){
          cin >>  *(*(ppt + i) + j);
          total[i] += *(*(ppt + i) + j);
        }
    }

    for(int i = 0 ; i < 5 ; i++){
        for(int j=0; j < 5 ; j++){
            cout << *(*(ppt + j) + i) << " ";
            
        }
        delete[] *(ppt + i);
        cout << endl;
    }

    delete [] ppt;

    



}