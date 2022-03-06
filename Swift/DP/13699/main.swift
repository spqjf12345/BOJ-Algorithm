//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/04.
//

import Foundation

var n = Int(readLine()!)!
var memo: [Int] = Array(repeating: 0, count: n+1)
memo[0] = 1

func dp(_ n: Int) -> Int {
    if(n == 0) { return memo[0] }
    if(memo[n] != 0) { return memo[n] }
    var k = 0
    
    for i in 0..<n {
       k += dp(i) * dp(n - 1 - i)
    }
    memo[n] = k
    return k
}


print(dp(n))

