//
//  14889_startLink.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/05.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int N;
int power[20][20] = {0, };
vector<int> h;
vector<int> combi;
int min_score = 214700000;

int calPowerDiff(vector<int> combi){ // start team 생성

    vector<int> link;
    int i, j;
    int start_power = 0;
    int link_power = 0;

    vector<int> temp(N);
    for (i = 0; i < N / 2; i++) temp[combi[i]]++; // start team meber check
    for (i = 0; i < N; i++) if (temp[i] == 0) link.push_back(i); // link member 넣어주기

    for (i = 0; i < N / 2; ++i)
    {
        for (j = 0; j < N / 2; ++j)
        {
            if (i == j) continue;
            start_power += power[combi[i]][combi[j]];
            link_power += power[link[i]][link[j]];
        }
    }

    return start_power > link_power ? start_power - link_power : link_power - start_power;
}

void match_team(int start, int index){
    if(index == N / 2) { // 팀원 모집 끝남
        int result = calPowerDiff(combi);
        if(min_score > result) { min_score = result; }
    }else { // 조합으로 팀원 모집하기
        for(int i = start; i < h.size(); i++){
            combi[index] = h[i];
            match_team(i + 1, index + 1);

        }
    }
}






int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> power[i][j];
        }
    }
    
    combi = vector<int>(N / 2);


    for (int i = 0; i < N; i++)
    {
        h.push_back(i);
    }

    match_team(0, 0);
    cout << min_score << '\n';
    return 0;
}

