//
//  1697_hide_seek.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/21.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>


using namespace std;
#define MAX 100000
bool visit[MAX + 1];

//int hide_and_seek_bfs(int n, int k){
//    memset(visit, false, sizeof(visit));
//    
//    int time = 0;
//    int currentN = n;
//    //visit[n] = true;
//    queue<int> q;
//    q.push(n);
//    int move[3] = {2 * currentN, currentN - 1, currentN + 1};
//    
//    while(!q.empty()){
//        int nq = q.front(); q.pop();
//        if(nq == k) return time;
//        
//        //for(int i = 0; i <3; i++){
//            
//            //int nmove = nq + move[i];
//        
//            if(visit[nq] == false && n + 1 <=MAX){
//                visit[nmove] = true;
//                //currentN = nmove;
//                q.push(nmove);
//                time++;
//            }
//            if(visit[nmove] == false && n + 1 <=MAX){
//                visit[nmove] = true;
//                //currentN = nmove;
//                q.push(nmove);
//                time++;
//            }
//            if(visit[nmove] == false && n + 1 <=MAX){
//                visit[nmove] = true;
//                //currentN = nmove;
//                q.push(nmove);
//                time++;
//            }
//            
//        //}
//        
//    }
    return time;
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << hide_and_seek_bfs(n, k) << endl;
    return 0;
}
