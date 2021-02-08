//
//  14720_milkfev.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2020/12/23.
//

#include <iostream>
#include <vector>

using namespace std;

int circle(int two){
    if(two == 2) return 0;
    else return two+1;
}

int main (){
    int n;
    int input, count = 1;
    int startPoint, nextPoint;
    cin >> n;
    if (n ==0) return 0;
    vector <int> store;
    for(int i=0; i< n;i++){
        cin >> input;
        store.push_back(input);
    }
    int i = 1;
    startPoint = store.at(i-1); //real value
    nextPoint = circle(startPoint); // expected value
    while(i< store.size()){
        if (nextPoint == store.at(i)) {
            count++;
            nextPoint = store.at(i);
        }else{
            startPoint = store.at(i-1); //real value
            nextPoint = circle(startPoint); // expected value
        }
        i++;

    }
    
    cout << count << endl;

    return 0;
}

/*#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    int m[1000];
    int max = 0;
    int c = 0;

    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    for (int j = 0; j < n; j++) {
        if (m[j] == 0 && c == 0) {
            max++;
            c = 1;
        }
        if (m[j] == 1 && c == 1) {
            max++;
            c = 2;
        }
        if (m[j] == 2 && c == 2) {
            max++;
            c = 0;
        }
    }

    cout << max;
    return 0;
}*/

