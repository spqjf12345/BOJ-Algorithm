//
//  2798_blackJack.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/06/23.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int N, M, result = 0;
int arr[101] = {0, };
int sum = 0 ;
//3장의 카드를 골라야 한다.

void black_jack(){
    for(int i = 0; i < N - 2; i++){ // j가 +1이므로 n -2
        for (int j = i + 1; j < N - 1; j++){ // k가 + 1이므로 n - 1
            for(int k = j + 1; k < N; k++){
                sum = arr[i] + arr[j] + arr[k];
                if(sum <= M && sum > result) {
                    result = sum;
                }
            }
        }
    }
    
}

int main(){
    cin >> N >> M;
    
    for(int i =0; i <N; i++){
        cin >> arr[i];
    }
    
    black_jack();
    cout << result << '\n';
    return 0;
}
