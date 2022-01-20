//
//  2501.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/08.
//

//약수 구하기
//p를 q로 나누었을때 나머지가 0이라면 q는 p의 약수
#include <stdio.h>
#include <iostream>
using namespace std;
int N, K;
int arr[10001] = {0, };

int main(){
    cin >> N >> K;
    int i = 1;
    int j = 0;

    while(i <= N){
        if(N % i == 0){
            arr[j++] = i;
        }
        i++;
    }
    
    cout << arr[K-1] << '\n';
    
    return 0;
}
