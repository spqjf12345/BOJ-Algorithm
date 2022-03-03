//
//  10974_all_ permutation.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/27.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>


using namespace std;
vector<int> v;
bool visit[9];
int n;

///<algorithm> -> next_permutation(순열 시작, 순열 끝)
/// with recursive 
void make_permu_dfs(){
    if(v.size() == n){
        for(int i = 0; i < n; i++){
            cout << v.at(i) << " ";
        }
        cout << endl;
        return;
    }else{
        for(int i = 1; i <= n; i++){
            if(visit[i] == false){
                visit[i] = true;
                v.push_back(i);
                make_permu_dfs();
                v.pop_back();
                visit[i] = false;
            }
        }
    }
}

int main(){
    cin >> n;
    memset(visit, false, sizeof(visit));
    make_permu_dfs();
    return 0;
}
