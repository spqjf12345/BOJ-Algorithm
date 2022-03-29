//
//  File.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/29.
//

import Foundation
var n = Int(readLine()!)!

func check_palindrome(_ s: String) -> Bool {
    var start = 0
    var end = s.count - 1
    while(start < end){
        if(s[s.index(s.startIndex, offsetBy: start)] == s[s.index(s.startIndex, offsetBy: end)]){
            start += 1
            end -= 1
        }else {
            return false
        }
    }
    return true
}

for _ in 0..<n {
    let s = readLine()!
    if(check_palindrome(s)) {
        print(0)
    }else {
        var similar = false
        for i in 0..<s.count {
            var temp: String = s
            temp.remove(at: temp.index(temp.startIndex, offsetBy: i))
            if(check_palindrome(temp)) {
                print(1)
                similar = true
                break
                
            }
        }
        if(!similar) {
            print(2)
        }
        
    }
}

//func check_palindrome(_ left: Int, _ right: Int ,_ s: String, once: Bool) -> Int {
//    var start = left
//    var end = right
//    while(start < end){
//        if(s[s.index(s.startIndex, offsetBy: start)] != s[s.index(s.startIndex, offsetBy: end)]){
//            if(once){
//                if(check_palindrome(start+1, end, s, once: false) == 0 || check_palindrome(start, end-1, s, once: false) == 0) { return 1 }
//            }
//            return 2;
//           
//        }else {
//            start += 1
//            end -= 1
//        }
//    }
//    return 0
//}
