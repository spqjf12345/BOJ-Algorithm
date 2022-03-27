//
//  jinu_4.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/27.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int arr[1001];
int idx = 0;
int d[1001] { 0, };

int main(){
    while(true){
        int temp = 0;
        cin >> temp;
        if(temp == 0){
            break;
        }
        arr[idx++] = temp;
    }
    int windowSize = 1;
    int minWindowSize = windowSize;
    int result = 10000;
    int startIndex = 0, endIndex = 0;
    
    while(windowSize < idx - 1){
        for(int j = 0; j <= idx - windowSize; j++){
            int minSum = 0;
            for(int k = j; k < windowSize + j; k++){
                minSum += arr[k];
            }
            if(minSum <= result){
                if(minSum == result) {
                    if(windowSize > minWindowSize){
                        continue;
                    }
                }
                result = minSum;
                startIndex = j;
                if(windowSize == 1){
                    endIndex = 0;
                }
                endIndex = j + windowSize - 1;
                minWindowSize = windowSize;
            }
            
        }
        windowSize++;
    }
    
    for(int i = startIndex; i <= endIndex; i++){
        cout << arr[i] << " ";
    }
    return 0;
    
}

//10 -5 -12 4 -13 11 7 -3 7 -10 5 0
//10 -5 -12 4 -3 11 7 -3 7 -10 5 0
//-2 5 -1 -1 0
//-3 -1 8 -1 -3 0
