//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/17.
//

import Foundation
var Tcase = Int(readLine()!)!

func dfs(_ arr:[Int]) -> Int {
    var answer = 0
    for (idx, i) in arr.enumerated() { // me, friend
        var cnt = 0
        let start = idx + 1
        var friend = i
        while(start != friend) {
            if( friend == arr[friend-1]) {
                break
            }else {
                print("\(start) \(friend)")
                friend = arr[friend-1]
                print("next friend \(friend)")
                //cnt += 1
            }
        }
        if(start == friend){
            cnt += 1
        }else {
            cnt = 0
        }
        answer += cnt
    }
    return arr.count - answer
}

for _ in 0..<Tcase {
    var n = Int(readLine()!)!
    var arr = readLine()!.split(separator: " ").map{ Int($0)!}
    print(dfs(arr))
}
