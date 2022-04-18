//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/18.
//

import Foundation
var n = Int(readLine()!)!

var visit = Array(repeating: false, count: n)
func backtracking(_ nowArr: [Int]) {
    if nowArr.count == n {
        for i in nowArr {
            print(i, terminator: " ")
        }
        print("")
        return
    }
    
    for i in 0..<n {
        if !visit[i] {
            visit[i] = true
            backtracking(nowArr + [i+1])
            visit[i] = false
        }
    }
}

backtracking([])
