//
//  11403_path.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/18.
//

#include <stdio.h>
#include <iostream>

#define MAX 101
using namespace std;

int path[MAX][MAX];

void find_path(int n){
    int d[n][n];
    
    for(int i = 0; i< n; i++){
        for(int j = 0; j <n; j++){
            d[i][j] = path[i][j];
        }
    }
    
    //k 거쳐가는 노드
    for(int k = 0; k< n; k++){
        //i 출발 노드
        for(int i = 0; i <n; i++){
            //j 도착 노드
            for(int j = 0; j <n; j++){
                
                if(d[i][k] >0 && d[k][j] > 0){ //거쳐 가는 길 있으면
                    d[i][j] = 1;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> path[i][j];
        }
    }
    
//    for(int i = 0; i< n; i++){
//        for(int j = 0; j <n; j++){
//            cout << path[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    find_path(n);
    return 0;
}

