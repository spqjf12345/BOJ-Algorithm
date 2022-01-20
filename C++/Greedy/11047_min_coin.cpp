//
//  11047_min_coin.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2020/12/20.
//

#include <iostream>
using namespace std;

int main(){
    int n, money;
    int count =0;
    
    cin>> n >> money;
    int val[n];
    
    for(int i=0; i< sizeof(val)/sizeof(int); i++){
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

