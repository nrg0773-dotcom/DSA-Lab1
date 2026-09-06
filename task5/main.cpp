#include <iostream>
#include <vector>
/*
Task 5 – Pascal’s Triangle 

Write a function that generates Pascal’s Triangle up to n rows. 

Test cases: 

n = 0, n = 1, n = 5. 

Verify row 5 → {1, 4, 6, 4, 1}. 
*/

// used to display the row
void Print(std::vector<int> previous , int size){


    for(int i = 0 ; i < size ; i++){
        std::cout<<previous[i]<<" ";
    }
    std::cout<<std::endl;
}

void drawPascalTriangle(int rows){

    //invalid rows edge case handling
    if(rows <= 0)return ;


    std::vector<int> previous = {1};
    for(int i = 0 ; i < rows  ; i++){
        std::vector<int> next;
        int size = previous.size();
        Print(previous , size);
        for(int j = 0 ; j < size ; j++){
            if(j == 0)next.push_back(1);
            if(j+1 == size){ next.push_back(1); continue;}
            next.push_back(previous[j] + previous[j+1]);
        }
        previous = next;
    }

}

void gap(int number){for(int i = 0 ; i < number ; i++)std::cout<<std::endl;}



int main(){

    //case 1 nothing white space
    drawPascalTriangle(0);
    gap(2);
    //case 2 only element 1
    drawPascalTriangle(1);
    gap(2);
    //case 3 a valid passcalTriangle
    drawPascalTriangle(5);
    
  
    
}
