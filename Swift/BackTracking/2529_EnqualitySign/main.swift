//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/31.
//

import Foundation

var n = Int(readLine()!)!
var signArr: [String] = readLine()!.split(separator: " ").map { String($0) }
var boolArr:[Bool] = Array(repeating: false, count: 10)
var answer: [String] = []

func signCheck(_ num1: Character, _ num2: Int, _ sign: String) -> Bool {
    if(sign == "<") {
        if(num1.asciiValue! - 48 > num2) { return false }
    }else {
        if(num1.asciiValue! - 48 < num2) { return false }
    }
    return true
}

func backTracking_sign(_ index: Int, _ s: String){
    if(index == n+1) {
        answer.append(s)
        return
    }
    
    for i in 0...9 {
        if(boolArr[i]) { continue } // 이미 사용한 숫자
        if(index == 0){
            boolArr[i] = true
            backTracking_sign(index+1, "\(s)\(i)") // 다름 자리, 다음 숫자
            boolArr[i] = false
        }else {
            let num1 = s[s.index(s.startIndex, offsetBy: index - 1)]
            let num2 = i
            if(signCheck( num1, num2, signArr[index-1])) {
                boolArr[i] = true
                backTracking_sign(index+1, "\(s)\(i)") // 다름 자리, 다음 숫자
                boolArr[i] = false
            }
        }

    }
}

backTracking_sign(0, "")
answer.sort()
print(answer.last!)
print(answer.first!)
