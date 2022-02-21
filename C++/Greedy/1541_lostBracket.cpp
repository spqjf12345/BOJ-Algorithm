//
//  1541_lostBracket.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/21.
//

#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string s;
    string num = "";
    int answer = 0;
    bool isMinus = false;
    cin >> s;
    for(int i =0; i <= s.length(); i++){
        char target = s[i];
        
        if(48 <= target && target <= 57){ // number
            num += target;
        }else if(target == '-' || target == '+' || i== s.size()){
            //operator
            //- 기호가 한번이라도 나타나면 빼준다. ex > -(50 + 20) - (30 + 10)
            if(isMinus){
                answer -= stoi(num);
            }else {
                answer += stoi(num);
            }
            num = "";
        }
        
        if(target == '-'){
            isMinus = true;
        }
    }
    
    cout << answer << '\n';
    return 0;
}
