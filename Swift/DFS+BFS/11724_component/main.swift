//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/17.
//

import Foundation

var line = readLine()!.split(separator: " ")
var N = Int(line[0])!
var M = Int(line[1])!
var arr: [[Int]] = Array(repeating: [], count: N+1)
var visit = [Bool](repeating: false, count: N+1)
var cnt = 0

func dfs_component(start: Int) {
    var s:[Int] = [start]
    visit[start] = true
    
    while(!s.isEmpty){
        let node = s.last!
        s.removeLast()
        for i in 0..<arr[node].count {
            let next = arr[node][i]
            if(!visit[next]){
                visit[next] = true
                s.append(next)
            }
        }
        
    }
    
}

for _ in 0..<M {
    let temp = readLine()!.split(separator: " ")
    let a = Int(temp[0])!
    let b = Int(temp[1])!
    
    arr[a].append(b)
    arr[b].append(a)
}

for i in 1..<N+1 {
    if(!visit[i]) {
        dfs_component(start: i)
        cnt += 1
    }
}

print(cnt)
