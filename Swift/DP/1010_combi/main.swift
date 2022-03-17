//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/17.
//

import Foundation
var Tcase = Int(readLine()!)!
var dp: [[Int]] = Array(repeating: Array(repeating: 0, count: 30), count: 30)

func combi(_ n: Int, _ m: Int) -> Int {
    if(dp[n][m] != 0) { return dp[n][m] }
    if(n == m || m == 0) { return 1 }
    dp[n][m] = combi(n-1, m) + combi(n-1, m-1)
    return dp[n][m]
}

for _ in 0..<Tcase {
    var n = 0, m = 0
    var line = readLine()!.split(separator: " ").map { Int($0)! }
    n = line[0]
    m = line[1]
    print(combi(m, n))
    dp = Array(repeating: Array(repeating: 0, count: 30), count: 30)
}
