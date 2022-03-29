//
//  9455_sticker.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/28.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int Tcase;

int main(){
    cin >> Tcase;
    for(int i = 0; i < Tcase; i++){
        int columns;
        int arr[2][100001];
        cin >> columns;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < columns; j++){
                cin >> arr[i][j];
            }
        }
        
        int d[2][100001]; // i번째 행, j번째 열까지 스티커의 최대값
        d[0][0] = arr[0][0];
        d[1][0] = arr[1][0];
        d[0][1] = arr[0][1] + d[1][0];
        d[1][1] = arr[1][1] + d[0][0];
        
        for(int j = 2; j < columns; j++){
            d[0][j] = arr[0][j] + max(d[1][j-1], d[1][j-2]);
            d[1][j] = arr[1][j] + max(d[0][j-1], d[0][j-2]);
        }
        
        cout << max(d[0][columns-1], d[1][columns-1]) << '\n';
    }
    return 0;
}
