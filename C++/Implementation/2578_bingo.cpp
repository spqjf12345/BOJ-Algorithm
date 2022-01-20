//
//  2578_bingo.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/06/24.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>


using namespace std;
vector<pair<int, int>> bingo[25];

int answer_arr[5][5];
bool check[5][5];
int bingo_line = 5;


bool is_bingo(){
    int bingo = 0;
    
    //width
    for(int i = 0; i < bingo_line; i++){
        bool bingoCheck = true;
        for(int j = 0; j < bingo_line; j++){
            if(check[i][j] == true){
                continue;
            }
            bingoCheck = false;
        }
        if(bingoCheck == true){
            bingo += 1;
        }
    }
    
    //height
    for(int i = 0; i < bingo_line; i++){
        bool bingoCheck = true;
        for(int j = 0; j < bingo_line; j++){
            if(check[j][i] == true){
                continue;
            }
            bingoCheck = false;
        }
        if(bingoCheck == true){
            bingo += 1;
        }
    }
    
    
    //diagonal
    if(check[0][0] && check[1][1] && check[2][2] && check[3][3] && check[4][4]){
        bingo += 1;
    }
    
    if(check[4][0] && check[3][1] && check[2][2] && check[1][3] && check[0][4]){
        bingo += 1;
    }
    
    if(bingo >= 3){
        return true;
    }
    return false;
    
    
    
}

int find_bingo(){
    int cnt = 0;
    
    for(int i =0; i < bingo_line; i++){
        for(int j = 0; j < bingo_line; j++){
            int find_num = answer_arr[i][j];
            int x = bingo[find_num][0].first;
            int y = bingo[find_num][0].second;
            check[x][y] = true;
            cnt++;
            if(is_bingo() == true){
                return cnt;
            }
               
        }
    }
    
    return cnt;
}

int main(){
    int n;
    memset(check, false, sizeof(check));
    for(int i = 0; i < bingo_line; i++){
        for(int j = 0; j < bingo_line; j++){
            cin >> n;
            bingo[n].push_back({i, j});
        }
    }
    
    for(int i =0; i < bingo_line; i++){
        for(int j = 0; j < bingo_line; j++){
            cin >> answer_arr[i][j];
        }
    }
    
    int bingo = find_bingo();
    cout << bingo << '\n';
    return 0;
}
