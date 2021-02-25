//
//  1987_DFS.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/04.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

bool visit[26];
char arr[20][20];
int C, R;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int answer;

void DFS(int x, int y, int cnt){
    answer = max(answer, cnt);
    for(int i =0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < R && ny < C){
            if(visit[arr[nx][ny] - 'A'] == false){
                visit[arr[nx][ny] - 'A'] = true;
                DFS(nx, ny, cnt + 1);
                visit[arr[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main(){
    
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
        }
    }
    
    visit[arr[0][0] - 'A'] = true;
    DFS(0,0,1);
    cout << answer << endl;
    return 0;
}

    
//    char horse = arr[0][0];
//    char next;
//    set<char> nt;
//    nt.insert(horse);
//    int i = 0;
//    int j =0;
//    int count = 1;
//    while(i < C && j < R){
//        next = arr[i][++j];
//        //cout << "next0 " << next <<endl;
//
//        if(horse == next){
//            if(*nt.find(next)){
//                break;
//            }
//            next = arr[++i][--j];
//            //cout << "next1 " << next <<endl;
//            if(horse == next){
//                //cout << "next2 " << next <<endl;
//                break;
//            }else{
//                if(*nt.find(next)){
//                    break;
//                }
//            }
//            nt.insert(next);
//
//        }else{
//            if(*nt.find(next)){
//                break;
//            }
//        }
//        count++;
//        horse = next;
//    }
//    cout<< count << endl;

