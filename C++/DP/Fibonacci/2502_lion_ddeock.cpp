////
////  2502_lion_ddeock.cpp
////  SOMA👩🏻‍💻
////
////  Created by JoSoJeong on 2021/09/03.
////
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//int D, K;
//int a, b;
//int dp[31];
//
////a - 1일날 준 떡, b - 2일 날 준 떡
//void find_day(){
//    dp[1] = dp[2] = 1;
//
//    for(int i = 3; i <= D; i++){
//        dp[i] = dp[i-1] + dp[i-2];
//    }
//
//    //a, b의 계수
//    int pre = dp[D-2];
//    int post = dp[D-1];
//
//    //k = dp[D-2]*a + dp[D-1]*b;
//
//    cout << "pre " << pre << '\n';
//    cout << "post " << post << '\n';
//
//    while(1){ //확장 유클리드 호제법
//        a++;
//        if((K - pre*a) % post){ //나누어 떨어지면
//            cout << "a : " << a <<'\n';
//            cout << "contnue : " << (K - pre*a) % post << '\n';
//            continue;
//        }
//        //위 식에서 나누어 떨어지지 x b 값이 계산 된다
//        b = (K - pre*a) / post;
//        break;
//    }
//    cout << a << "\n" << b << '\n';
//
//}
//
//int main(){
//    cin >> D >> K;
//    find_day();
//    return 0;
//}

#include <iostream>
using namespace std;
int main(void) {
    int first[31] = { 0, 1, 0, }, second[30] = { 0, 0, 1, }; int day, rc; int d1=1, d2=1; int i, j; cin >> day >> rc; for (i = 3; i <=day; i++) { first[i] = first[i - 1] + first[i - 2]; second[i] = second[i - 1] + second[i - 2]; } for (i = 1; i <= 50000; i++) { for (j = 1; j <= 50000; j++) { if (rc == (first[day] * i + second[day] * j)) { cout << i << endl << j; return 0; } else if (rc < (first[day] * i + second[day] * j)) break; } } }


