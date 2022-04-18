//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/17.
//

import Foundation

//permutation 순열
func backtracking(_ nowArr: [Int], _ cnt: Int){
    if cnt == c {
        for i in nowArr {
            print(i, terminator: " ")
        }
        print()
        return
    }
    
    for i in 0..<n {
        if !visit[i] {
            visit[i] = true
            backtracking(nowArr + [arr[i]], cnt + 1)
            visit[i] = false
        }
    }
}

var line = readLine()!.split(separator: " ").map { Int($0)! }
var n = line[0]
var c = line[1]

var arr = readLine()!.split(separator: " ").map { Int($0)! }
arr.sort()
var temp = Array(repeating: 0, count: n)
var visit: [Bool] = [Bool](repeating: false, count: n)
backtracking([], 0)


