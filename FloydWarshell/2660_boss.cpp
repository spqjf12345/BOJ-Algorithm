//
//  2660_boss.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/18.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 51
#define INF 100000

int N;
int f[MAX][MAX];
int score[MAX];

void find_boss(){
    
    //k 거쳐가는 노드
    for(int k = 1; k< N + 1; k++){
        //i 출발 노드
        for(int i = 1; i < N + 1; i++){
            //j 도착 노드
            for(int j = 1; j < N + 1; j++){
                if(f[i][k] + f[k][j] < f[i][j] ){ //거쳐 가는 길 있으면
                    f[i][j] = f[i][k] + f[k][j];
                }
            }
        }
    }
    
}


int main(){
    int s1 = 0, s2 = 0;
    
    cin >> N;

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N + 1; j++){
            f[i][j] = INF; // 전체를 무한대로 초기화
        }
    }
    
    for(int i = 1; i <N+1; i++){
        f[i][i] = 0; //가운데 0으로 초기화
    }
    
    while(true){
        cin >> s1 >> s2;
        if(s1 == -1 and s2 == -1){
            break;
        }
        f[s1][s2] = 1; //서로 친구 관계임을 표시
        f[s2][s1] = 1;
    }
    
// 배열 잘 들어갔나 확인 용
//    for(int i = 1; i <N+1; i++){
//        for(int j = 1; j < N+1; j++){
//            cout <<f[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    find_boss();
//find_boss 탐색 후 배열
//    for(int i = 1; i <N+1; i++){
//        for(int j = 1; j < N+1; j++){
//            cout <<f[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    0 1 2 2 3
//    1 0 1 1 2
//    2 1 0 1 1
//    2 1 1 0 1
//    3 2 1 1 0

    
    int man_score = -1; // 회장 후보 점수
    
    for(int i = 1; i < N+1; i++){
        
        int max = 0;
        for(int j = 1; j < N+1; j++){
            if(f[i][j] > max){
                max = f[i][j];
            }
        }
        
        score[i] = max; //1 -> 3, 2 -> 2, 3 -> 2, 4 -> 2, 5 -> 3
        //cout << "man_score : " << man_score << endl; // -1, 3, 2, 2, --> 2 너가 되었구나
        if(man_score > max || man_score == -1){
            man_score = max; // i:1 -> 3 // i:2 -> 2
            //cout << " man : " << man_score << endl;
        }
    }
    
    int count = 0;
    for(int i = 1; i < N+1; i++){
           if(score[i] == man_score){ //점수가 같은 사람들 숫자 셈
               count++;
           }
       }

    cout << man_score << " " << count << endl; // 점수, 후보의 수
        for(int i = 1; i < N+1; i++){
                if(score[i] == man_score){
                    cout << i << " ";
                }
            }
        cout << endl;

    return 0;
}
