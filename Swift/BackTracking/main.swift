//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/07.
//

import Foundation
//https://www.acmicpc.net/problem/1759

var line = readLine()!.split(separator: " ").map{ Int($0)! }
var n = line[1]
var m = line[0]
let vowel = ["a","e","i","o","u"]
let consonant = ["b","c","d","f","g","h","j","k","l","m","n","p","q","r","s","t","v","w","x","y","z"]

var str = readLine()!
var c = [Character]()
for i in str {
    if(i.isWhitespace){
        continue
    }
    c.append(i)
}
c.sort()

var arr: [Character] = Array(repeating: ".", count: m)

func backTracking( cnt: Int, num: Int){
    if(cnt == m){
        var bCnt = 0
        var cCnt = 0
        for i in arr {
            if vowel.contains("\(i)") {
                bCnt += 1
            }
            if consonant.contains("\(i)") {
                cCnt += 1
            }
        }
        if bCnt >= 1 && cCnt >= 2 { // 최소 한개의 모음, 최소 두개의 자음
            print(arr.map{ String($0)}.joined(separator: ""))
        }
        
        return
    }else {
        for i in stride(from: num, to: n, by: 1){
            arr[cnt] = c[i]
            backTracking(cnt: cnt+1, num: i + 1)
        }
    }
    
    
}

backTracking(cnt: 0, num: 0)



