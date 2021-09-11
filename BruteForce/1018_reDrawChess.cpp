//
//  1018_reDrawChess.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/10.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int col, row;
int arr[51][51];

int main(){
    cin >> col >> row;
    for(int i =0; i < col; i++){
        for(int j = 0; i < row; j++){
            cin >> arr[i][j];
        }
    }
    
    //make_chess_board();
    //find_re_draw()
    return 0;
}
