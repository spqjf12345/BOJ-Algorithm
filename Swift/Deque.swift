//
//  Deque.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/01/20.
//
///https://github.com/raywenderlich/swift-algorithm-club/tree/master/Deque

import Foundation

public struct Deque<T> {
    private var array = [T]()
    
    public var isEmpty: Bool {
        return array.isEmpty
    }
    
    public var count: Int {
        return array.count
    }
    
    public mutating func enqueue(_ element: T){
        array.append(element)
    }
    
    public mutating func enqueueFront(_ element: T) {
       array.insert(element, at: 0) //O(n)
     }
    
    public mutating func dequeue() -> T? {
        if isEmpty {
          return nil
        } else {
          return array.removeFirst() //O(n)
        }
      }
    
    public mutating func dequeueBack() -> T? {
        if isEmpty {
          return nil
        } else {
          return array.removeLast()
        }
      }
    
    public func peekFront() -> T? {
        return array.first
      }

      public func peekBack() -> T? {
        return array.last
      }
}

//var deque = Deque<Int>()
//deque.enqueue(1)
//deque.enqueue(2)
//deque.enqueue(3)
//deque.enqueue(4)
//
//deque.dequeue()       // 1
//deque.dequeueBack()   // 4
//
//deque.enqueueFront(5)
//deque.dequeue()       // 5


//효율적인 방법
//[ x, x, x, 1, 2, 3, 4, x, x, x ]


public struct Deque2<T> {
    private var array: [T?]
    private var head: Int
    private var capacity: Int
    private var originalCapacity: Int
    
    public init(_ capacity: Int = 10){
        self.capacity = max(capacity, 1)
        originalCapacity = self.capacity
        array = [T?](repeating: nil, count: capacity)
        head = capacity
    }
    
    public var isEmpty: Bool {
       return count == 0
     }

     public var count: Int {
       return array.count - head
     }

     public mutating func enqueue(_ element: T) {
       array.append(element)
     }
    
    public mutating func enqueueFront(_ element: T) {
        
        //앞 공간이 모자랄 때
        if head == 0 {
            capacity *= 2
            let emptySpace = [T?](repeating: nil, count: capacity)
            array.insert(contentsOf: emptySpace, at: 0)
            head = capacity
        }
        
        head -= 1
        array[head] = element
      }

      public mutating func dequeue() -> T? {
          guard head < array.count, let element = array[head] else { return nil }
          array[head] = nil
          head += 1

        //공간 낭비를 막기 위해 사이즈 줄임
          if capacity >= originalCapacity && head >= capacity*2 {
            let amountToRemove = capacity + capacity/2
            array.removeFirst(amountToRemove)
            head -= amountToRemove
            capacity /= 2
          }
          
         return element
      }

      public mutating func dequeueBack() -> T? {
        if isEmpty {
          return nil
        } else {
          return array.removeLast()
        }
      }
    
    public func peekFront() -> T? {
        if isEmpty {
          return nil
        } else {
          return array[head]
        }
      }

      public func peekBack() -> T? {
        if isEmpty {
          return nil
        } else {
          return array.last!
        }
      }
}

//[ x, x, x, x, x, x, x, x, x, x ]
//                                 |
//                                 head


