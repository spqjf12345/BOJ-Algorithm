//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/08.
//

import Foundation
var line = readLine()!.split(separator: " ").map { Int(String($0))! }
var n = line[0]
var m = line[1]

var dx = [-1, 1, 0, 0]
var dy = [0, 0, 1, -1]

var map = [[Int]]()
var visit: [[[Int]]] = Array(repeating: Array(repeating: Array(repeating: 0, count: 2), count: m), count: n) // x, y, 벽 부순 적 있는지

class Queue<T: Equatable> {
    var enqueue: [T]
    var dequeue: [T] = []
    
    var count: Int {
        return enqueue.count + dequeue.count
    }
    
    var isEmpty: Bool {
        return enqueue.isEmpty && dequeue.isEmpty
    }
    
    var first: T? {
        if dequeue.isEmpty {
            return enqueue.first
        } else {
            return dequeue.last
        }
    }
    
    var last: T? {
        if enqueue.isEmpty {
            return dequeue.first
        } else {
            return enqueue.last
        }
    }
    
    init(_ queue: [T]) {
        enqueue = queue
    }
    
    func push(_ n: T) {
        enqueue.append(n)
    }
    
    func pop() -> T? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue.removeAll()
        }
        return dequeue.popLast()
    }
    
    func removeAll() {
        enqueue.removeAll()
        dequeue.removeAll()
    }
    
    func contains(_ n: T) -> Bool {
        return enqueue.contains(n) || dequeue.contains(n)
    }
}

struct Wall: Equatable {
    var x: Int = 0
    var y: Int = 0
    var isBreak: Int = 0
}


func bfs() -> Int {
    var queue = Queue<Wall>([Wall(x: 0, y: 0, isBreak: 0)])
    //var queue = [(Int, Int, Int)]() // x, y, 벽 부쉈는지
   // queue.append((0, 0, 0))
    visit[0][0][0] = 1 // 0, 0, 0(벽 안부숴도 됨)
    
    while(!queue.isEmpty) {
        let x = queue.first!.x
        let y = queue.first!.y
        let isBreak = queue.first!.isBreak
        queue.pop()
        
        if(x == n-1 && y == m-1) { return visit[x][y][isBreak] }
        for i in 0..<4 {
            let nx = dx[i] + x
            let ny = dy[i] + y
            if(nx >= n || ny >= m || nx < 0 || ny < 0 ) { continue }
            
            if(visit[nx][ny][isBreak] != 0) { continue }

            if(map[nx][ny] == 0) {
                visit[nx][ny][isBreak] = visit[x][y][isBreak] + 1
                queue.push(Wall(x: nx, y: ny, isBreak: isBreak))
            }else if(map[nx][ny] == 1 && isBreak == 0){ // 기회 안사용 했을때
                visit[nx][ny][1] = visit[x][y][isBreak] + 1
                queue.push(Wall(x: nx, y: ny, isBreak: 1))
            }
            
            
        }
        
    }
    return -1
    
    
    
}

for _ in 0..<n {
    let l = readLine()!.map { Int(String($0))! }
    map.append(l)
}

print(bfs())

