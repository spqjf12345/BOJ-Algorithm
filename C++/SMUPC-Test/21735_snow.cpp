//
//  21735_snow.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/06/13.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int Tcase, t;
int arr[1000001];
int now = 1; // 현재 눈덩이 크기
int n = 0;
int bactracking(int move, int value, int time){
    //cout << "move : " << move << " " << "value : " << value  << " time : " << time << '\n';
    if(time == t || move == Tcase){
        return value;
    }
    if(time > t || move > Tcase){
        return 0;
    }
    
    if(move < Tcase){
        n = max(bactracking(move + 1, value + arr[move + 1], time + 1), bactracking(move + 2, value/2 + arr[move + 2], time + 1));
    }
    
    return n;
    
    
}


int main(){
    cin >> Tcase >> t;
    
    for(int i = 1; i <= Tcase; i++){
        cin >> arr[i];
    }
        
    cout << bactracking(0, 1, 0) << '\n';
    
    return 0;
}
