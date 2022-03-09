//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/09.
//

import Foundation

var n: Int = Int(readLine()!)!
var s: String = readLine()!
var num: String = ""
var nextNum: String = ""
var answer = 0
var isOP = false
var curOP: Character = "."
var isC: Bool = false
var totalAnswer = ""

func updateAnswer() {
    //print("current op \(curOP) // nextNum \(nextNum) // num \(num)")
    if curOP == "S" {
        answer = Int(nextNum)! - Int(num)!
    }else if curOP == "M" {
        answer = Int(nextNum)! * Int(num)!
    }else if curOP == "U" {
        if(answer < 0){
            answer = -(-Int(nextNum)! / Int(num)!)
        }else {
            answer =  Int(nextNum)! / Int(num)!
        }
    }else if curOP == "P" {
        answer = Int(nextNum)! + Int(num)!
    }else if curOP == "." {
        answer = Int(num)!
    }
    //print("answer \(answer)")
}

for i in s {
    if i.isNumber {
        if Int(String(i))! == 0 {
            continue
        }
       
        num += String(i)

    }else if i == "C" {
       // 출력
        isC = true
        updateAnswer()
        totalAnswer += String(answer) + " "
    }else {
        if isOP == false {
            isOP = true
            curOP = i
            nextNum = num
            num = ""
            continue
        }
        updateAnswer()
        curOP = i
        nextNum = String(answer)
        num = ""
    }
}
if(isC == false ) {
    print("NO OUTPUT")
}else {
    print(totalAnswer)
}

