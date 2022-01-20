//
//  Queue.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/01/20.
//

import Foundation

public struct Queue<T> {
    fileprivate var array = [T]()
    
    public var isEmpty: Bool {
        return array.isEmpty
    }
    
    public var count: Int {
        return array.count
    }
    
    public mutating func enqueue(_ element: T){
        array.append(element)
    }
    
    public mutating func dequeue() -> T? {
        if isEmpty {
            return nil
        }else {
            return array.removeFirst() // O(n) 시간이 들어 비효율적
        }
    }
    
     public var front: T? {
       return array.first
     }
}

//var queues = Queue<String>()
//queues.enqueue("Adam")
//queues.enqueue("Steve")
//queues.enqueue("Tim")

public struct Queue2<T> {
    fileprivate var array = [T?]()
    fileprivate var head = 0
  
    public var isEmpty: Bool {
        return count == 0
    }

    public var count: Int {
        return array.count - head
    }
  
    public mutating func enqueue(_ element: T) {
        array.append(element)
    }
    
    public mutating func dequeue() -> T? {
        guard head < array.count, let element = array[head] else { return nil }
        array[head] = nil
        head += 1
        let percentage = Double(head)/Double(array.count)
        if array.count > 50 && percentage > 0.25 {
          array.removeFirst(head)
          head = 0
        }
        return element
    }
    
    public var front: T? {
        if isEmpty {
          return nil
        } else {
          return array[head]
        }
      }
}
