//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/18.
//

import Foundation
var s = readLine()!
var islowcase = true

//모두 소문자인지 check
for i in s {
    if !i.isLowercase {
        islowcase = false
        break
    }
}

if islowcase && !s.contains("_") {
    print(s)
}else {
    if s.first!.isUppercase || s.first! == "_" || s.last! == "_" {
        print("Error!")
    }
    else if s.contains("_") {
        print(cToJava())
    }else {
       print(javaToC())
    }
}

func cToJava() -> String { // 대문자 있으면 안됨
    var result = ""
    for i in s {
        if i.isUppercase {
            return "Error!"
        }
    }
    let str = Array(s.split(separator: "_", omittingEmptySubsequences: false))
    
    for (idx, i) in str.enumerated() {
        if i.isEmpty { return "Error!" }
        
        if idx == 0 {
            result = "\(i)"
            continue
        }
        result += i.first!.uppercased()
        
        result += String(i).substring(from: 1, to: i.count - 1)
    }
    return result
            
}

func javaToC() -> String {
    var result = ""
    for (idx, i) in s.enumerated() {
        if idx == 0 {
            result += "\(i)"
            continue
        }
        if i.isUppercase {
            result += "_\(i.lowercased())"
        }else {
            result += "\(i)"
        }
    }
    return result
}

extension String {
    func substring(from: Int, to: Int) -> String {
        guard from < count, to >= 0, to - from >= 0 else {
            return ""
        }
        // Index 값 획득
        let startIndex = index(self.startIndex, offsetBy: from)
        let endIndex = index(self.startIndex, offsetBy: to + 1) // '+1'이 있는 이유: endIndex는 문자열의 마지막 그 다음을 가리키기 때문
        
        // 파싱
        return String(self[startIndex ..< endIndex])
    }
}
