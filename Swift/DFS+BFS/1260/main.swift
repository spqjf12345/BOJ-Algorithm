//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/05/08.
//

import Foundation

///input
var line = readLine()!.split(separator: " ").map { Int(String($0))! }
var n = line[0]
var m = line[1]
var start = line[2]
var graph = Array(repeating: [Int](), count: n + 1)

for _ in 0..<m {
    let line = readLine()!.split(separator: " ").map { Int(String($0))! }
    graph[line[0]].append(line[1])
    graph[line[1]].append(line[0])
}

for i in 0..<graph.count {
    graph[i].sort(by: <)
}

//print(graph)
var visit:[Bool] = Array(repeating: false, count: n + 1)
var root: String = ""

func DFS(start: Int) {
    visit[start] = true
    root += "\(start) "
    for i in graph[start] {
        if !visit[i] {
            DFS(start: i)
        }
    }
}

func BFS(start: Int) -> String { //using queue
    var root: String = ""
    var queue: [Int] = []
    var visit:[Bool] = Array(repeating: false, count: n + 1)
    visit[start] = true
    queue.append(start)
    
    while !queue.isEmpty {
        let next = queue.first!
        queue.removeFirst()
        root += "\(next) "
        
        for i in graph[next] {
            if !visit[i] {
                visit[i] = true
                queue.append(i)
            }
        }
    }
    return root
}

DFS(start: start)
print(root)
print(BFS(start: start))
