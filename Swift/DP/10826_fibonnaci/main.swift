//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/07.
//

import Foundation

let N = Int(readLine()!)!
var answer = ([0],[1]) // 123 + 123
if N == 0 {
    print(0)
}else {
    for _ in 1..<N {
        var temp = (answer.1+[0], [Int]())
        var s = 0
        var next = [Int]()
        zip(answer.0+[0], temp.0).forEach{
            next.append(($0+$1+s)%10)
            s = ($0+$1+s)<10 ? 0 : 1
        }
        temp.1 = next
        if temp.1.last == 0 {
            temp.1.removeLast()
            temp.0.removeLast()
        }
        answer = temp
    }
    print(String(answer.1.map{String($0)}.joined().reversed())) // 10 -> answer ([4, 3, 0], [5, 5, 0])

}
