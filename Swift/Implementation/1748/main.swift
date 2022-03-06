//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/06.
//

import Foundation
var n: Int = Int(readLine()!)!
var ans: Int = 0
var div: Int = 1

while(div < n){
    ans += (n - div + 1) // 그 전 자리수 더해준거 빼준다.
    div *= 10
}

print(ans)


