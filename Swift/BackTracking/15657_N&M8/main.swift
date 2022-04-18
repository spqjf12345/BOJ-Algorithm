//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/17.
//

//permutation 중복 순열, 전 값이 다음 값보다 항상 커야 함
import Foundation

func backtracking(_ nowArr: [Int], _ cnt: Int, _ start: Int){
    if cnt == c {
        for i in nowArr {
            print(i, terminator: " ")
        }
        print()
        return
    }
    
    for i in start..<n { // 시작 원소를 전 원소로 함
        backtracking(nowArr + [arr[i]], cnt + 1, i)
    }
}

var line = readLine()!.split(separator: " ").map { Int($0)! }
var n = line[0]
var c = line[1]

var arr = readLine()!.split(separator: " ").map { Int($0)! }
arr.sort()

backtracking([], 0, 0)


