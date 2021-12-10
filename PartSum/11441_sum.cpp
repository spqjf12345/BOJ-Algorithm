//
//  11441_sum.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/12/10.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int n, Tcase;
int arr[100001];
int sumArr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    sumArr[0] = 0;
    
    for(int i = 1; i <= n; i++){
        sumArr[i] = sumArr[i-1] + arr[i];
    }
    
    cin >> Tcase;
    
    for(int i =0; i < Tcase; i++){
        int start, end;
        cin >> start >> end;
        cout << sumArr[end] - sumArr[start-1] << "\n";
    }
    return 0;
}
