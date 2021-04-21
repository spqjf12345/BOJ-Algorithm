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
int n, k;


int main(){

    cin >> n >> k;
    cout << hide_and_seek_bfs() << endl;
    return 0;
}
