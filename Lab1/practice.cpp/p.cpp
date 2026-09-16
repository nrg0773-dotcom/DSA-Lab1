#include <iostream>


int findMax(int* ptr , int size , int max1 = 0   ,int index = 0  ){
    if(index < size){
        if(ptr[index] > max1){
            max1 = ptr[index];
        }
         std::cout << max1;

        return findMax(ptr , size  , max1  , index + 1);
       

    }

   return max1;

}


int main(){
 int arr[] = {1 ,2 ,3 ,4 ,7 ,2 ,9 ,1};
 int a = 0;
 int b = 0;
 int *max = &a;
 int *max2 = &b;

 int c = findMax(arr , 7  );

 std::cout << c;
}