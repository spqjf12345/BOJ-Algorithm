//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/17.
//

import Foundation

var n = Int(readLine()!)!
func check_palindrome(_ s: String) -> Bool {
    var start = 0
    var end = s.count - 1
    var arr = Array(s)
    while start < end {
        if arr[start] != arr[end] {
            return false
        }else {
            start += 1
            end -= 1
        }
    }
    return true
}

func isPrime(_ number: Int) -> Bool {
    var bool = false
    if number == 2 || number == 3 { return true }
    let maxDivider = Int(sqrt(Double(number)))
    bool = number > 1 && !(2...maxDivider).contains { number % $0 == 0 }
    
    return bool
}

func check() -> Int {
    while true {
        if check_palindrome(String(n)) && isPrime(n) {
            break
        }
        n += 1
    }
    return n
}

print(check())

