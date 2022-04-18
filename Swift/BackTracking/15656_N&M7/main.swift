//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/18.
//

import Foundation

//permutation 중복 순열
var temp = [String]()
var resultStr = ""
func backtracking(_ cnt: Int){
    if cnt == c {
        resultStr += temp.joined(separator: " ") + "\n"
        return
    }
    
    for i in 0..<n {
        temp.append(String(arr[i]))
        backtracking(cnt + 1)
        temp.removeLast()
    }
}

var line = readLine()!.split(separator: " ").map { Int(String($0))! }
var n = line[0]
var c = line[1]

var arr = readLine()!.split(separator: " ").map { Int(String($0))! }
arr.sort()

backtracking(0)
print(resultStr)

