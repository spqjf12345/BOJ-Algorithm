//
//  14501_leaveCompany.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/07.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int days, result = 0;
int work[16];
int value[16];

void make_work(int date, int ret){
    if(date == days) result = max(result, ret); //날이 되면 여태 번 돈 result에 기록
    if(date >= days) return;
    
    make_work(date + work[date], ret + value[date]); // 다음 날로 이동
    make_work(date + 1, ret);
    //cout << " date : " << date + work[date] << " result " <<  ret + value[date] <<'\n';
}

int main(){
    cin >> days;
    for(int i = 0; i < days; i++){
        cin >> work[i] >> value[i];
    }
    
    make_work(0, 0);
    cout << result << '\n';
    

  
    return 0;
    
}
