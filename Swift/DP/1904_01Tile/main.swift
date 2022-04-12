//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/12.
//

import Foundation
var n = Int(readLine()!)!
var mod = 15746
var d: [Int] = Array(repeating: 0, count: n+1)

func dp() -> Int {
    if(n == 1 || n == 2) { return n }
    else {
        d[1] = 1
        d[2] = 2
        for i in 3...n {
            d[i] = (d[i-2] + d[i-1]) % mod
        }
    }
    return d[n]
}
print(dp())
