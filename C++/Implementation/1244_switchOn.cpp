//
//  1244_switchOn.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/03.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int c;
int arr[101];
pair<int, int> studentArr[101];
int studentCount;

void change_boy(int i){
    int num = studentArr[i].second;
    for(int i = num; i <= c; i+= num){
        if(arr[i] == 0){
            arr[i] = 1;
        }else {
            arr[i] = 0;
        }
    }

    
}

void change_girl(int i){
    int num = studentArr[i].second;
    cout << "num " << num << '\n';
    int left = num - 1;
    int right = num + 1;
    if(arr[num] == 0) { arr[num] = 1; } else { arr[num] = 0;}
    while(left > 0 && right <= c){
        if(arr[left] == arr[right]){
            if(arr[left] == 1) { arr[left] = arr[right] = 0; }
            else { arr[left] = arr[right] = 1;}
        }else { // 같지 않다면 x
            break;
        }
        left--;
        right++;
    }
    
}

void turnSwitch(){
    for(int i = 0; i < studentCount; i++){
        if(studentArr[i].first == 1){
            change_boy(i);
            for(int i = 1; i <= c; i++){
                cout << arr[i] << " ";
            }
            cout << '\n';
        }else{
            change_girl(i);
            for(int i = 1; i <= c; i++){
                cout << arr[i] << " ";
            }
            cout << '\n';
        }
    }
}



int main(){
    
    cin >> c;
    for(int i = 1; i <= c; i++){
        cin >> arr[i];
    }
    
    cin >> studentCount;
    
    for(int i =0; i < studentCount; i++){
        cin >> studentArr[i].first >> studentArr[i].second;
    }
    
    turnSwitch();
    
    
    //result
    for(int i = 1; i <= c; i++){
        cout << arr[i] << " ";
        if(i % 20 == 0){
            cout << '\n';
        }
    }
    
    return 0;
}
