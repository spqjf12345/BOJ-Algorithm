//
//  11047_min_coin.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2020/12/20.
//

#include <iostream>
using namespace std;
int val[1000001];
int n, money;
int count =0;

int main(){
    
    cin>> n >> money;

    for(int i=0; i< n); i++){
        cin >> val[i];
    }
    
    
    for(; n>0;n--){
        if (money ==0) break;
        count += money / val[n-1];
        money = money % val[n-1];
       
    }
    cout <<count << endl;
    
    
    return 0;
    
}

