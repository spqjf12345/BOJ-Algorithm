//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/07.
//

import Foundation
var Tcase = Int(readLine()!)!
func do_command(_ n: Int, _ command: String, _ array: [Int]) -> String {
    var head = 0, tail = n-1
    var isReversed = false

    let arr:[Int] = array

    for i in command {
        if i == "R" {
            isReversed.toggle()
        }else if i == "D" {
            if head > tail {
                return "error"
            }
            if isReversed {
                tail -= 1
            }else {
                head += 1
            }
        }
    }
    
    if head > tail {
        return "[]"
    }else {
        if !isReversed {
          return "[" + arr[head...tail].map { String($0)}.joined(separator: ",") + "]"
        }else {
            return "[" + arr[head...tail].reversed().map { String($0)}.joined(separator: ",") + "]"
        }
    }
    
}

for _ in 0..<Tcase {
    let command = readLine()!
    let n = Int(readLine()!)!
    let arr = readLine()!.dropFirst().dropLast().split(separator: ",").map{Int(String($0))!}
    
    print(do_command(n, command, arr))
}

extension Array where Element: Hashable {
    mutating func remove(values: [Element]) {
        let set = Set(values)
        removeAll { set.contains($0) }
    }
}
