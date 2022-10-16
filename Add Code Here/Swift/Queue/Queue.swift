//
//  Queue.swift
//  Queue
//
//  Created by Stevhen on 13/10/22.
//

import Foundation

public class BookStoreCustomer {
    var queueId: String
    var bookQty: Int
    
    init(queueId: String, bookQty: Int) {
        self.queueId = queueId
        self.bookQty = bookQty
    }
}

//To create Node property
public class Node<T> {
    var value: T
    
    init(value: T){
        self.value = value
    }
    
    var next: Node<T>?
    weak var prev: Node<T>?
}

//Data Structure logics
public class DoubleLinkedList<T> {
    fileprivate var head: Node<T>?
    private var tail: Node<T>?
    
    public var isEmpty: Bool {
        return head == nil
    }
    
    public var first: Node<T>? {
        return head;
    }
    
    public var last: Node<T>? {
        return tail
    }
    
    public func push(value: T) {
        
        let curr = Node(value: value)
        
        if let tailNode = tail {
            curr.prev = tailNode
            tailNode.next = curr
        } else {
            head = curr
        }
        
        tail = curr
    }
    
    public func getNode(index: Int) -> Node<T>? {
        
        if index >= 0 {
            var curr = head
            var i = index
            
            while curr != nil {
                if i == 0 { return curr }
                i -= 1
                curr = curr!.next
            }
        }
        
        return nil
    }
    
    public func getSize() -> Int{
        var curr = head
        var  i: Int = 0
        
        while curr != nil {
            i += 1
            curr = curr!.next
        }
        
        return i
    }
    
    public func pop(curr: Node<T>) -> T {
        let prev = curr.prev
        let next = curr.next
        
        if let prev = prev {
            prev.next = next
        } else {
            head = next
        }
        
        next?.prev = prev
        
        if next == nil {
            tail = prev
        }
        
        curr.prev = nil
        curr.next = nil
        
        return curr.value
    }
    
    public func popAll() {
        head = nil
        tail = nil
    }
}


public struct Queue<T> {
    
    fileprivate var list = DoubleLinkedList<T>()
    
    public var isEmpty: Bool {
        return list.isEmpty
    }
    
    public mutating func enqueue(_ element: T){
        list.push(value: element)
    }
    
    public mutating func dequeue() -> T? {
        guard !list.isEmpty, let element = list.first else { return nil }
        
        let removedElement = list.pop(curr: element)
        
        return removedElement
    }
    
    public func peek() -> T? {
        return list.first?.value
    }
    
    public func getSize() -> Int {
        return list.getSize()
    }
    
    public func peekAt(index: Int) -> Node<T>? {
        return list.getNode(index: index)
    }
    
    public func dequeueAll(){
        list.popAll()
    }

}

//Main Program
public func enqueueBuyer(){
    print("Enter queue id: ", terminator: "")
    let queueId: String? = readLine()
    print("Enter book quantity to buy: ", terminator: "")
    let bookQty: Int? = Int(readLine()!)

    queue.enqueue(BookStoreCustomer(queueId: queueId!, bookQty: bookQty!))
}

public func clrScr(){
    for _ in 1...25 {
        print("")
    }
}

public func separatorBar(length : Int){
    for _ in 1...length {
        print("=", terminator: "")
    }
    print("")
}

public func showQueue(){

    if queue.isEmpty {
        print("No data yet")
    }
    else{
        let header: String = String(format: "| %-4s | %-12s | %-10s |", ("No" as NSString).utf8String!,("ID" as NSString).utf8String!, ("Quantity" as NSString).utf8String!)
        
        separatorBar(length: header.count)
        print(header)
        separatorBar(length: header.count)
        for i in 0 ..< queue.getSize()  {
            let curr = queue.peekAt(index: i)
            print(String(format: "| %-4d | %-12s | %-10d |", i+1, (curr!.value.queueId as NSString).utf8String!, curr!.value.bookQty))
        }
        separatorBar(length: header.count)
    }

}

public func dequeueBuyer(){
    if queue.isEmpty {
       print("No data yet")
   }
   else{
        if let buyer = queue.dequeue() {
            print("Buyer with ID: \(buyer.queueId) served")
        }
    }
}

public func dequeueAllBuyer(){
    queue.dequeueAll()
    
    print("All Buyer served")
}

var queue = Queue<BookStoreCustomer>()

//Dummy data
queue.enqueue(BookStoreCustomer(queueId: "Q12", bookQty: 2))
queue.enqueue(BookStoreCustomer(queueId: "Q14", bookQty: 3))
queue.enqueue(BookStoreCustomer(queueId: "Q16", bookQty: 4))

while true {

    clrScr()
    var choose: Int! = 0;

    print("Buying Book Queue Program")
    print("=====================")
    if let nextCustomer = queue.peek() {
        print("Next Queue ID to Serve: \(nextCustomer.queueId)")
        print("=====================")
    }
    print("Menu")
    print("1. Queue Buyer")
    print("2. Show")
    print("3. Serve Buyer")
    print("4. Serve All Buyer")
    print("5. Exit")

    repeat {
        print("Input: ", terminator: "")
        if let str = readLine(){
         choose = Int(str)
        }
    } while choose < 1 || choose > 5;

    switch choose {
        case 1:
            enqueueBuyer()
        case 2:
            showQueue()
        case 3:
            dequeueBuyer()
        case 4:
            dequeueAllBuyer()
        case 5:
            print("Thank you for using this program :)")
        default:
            print("")
    }

    _ = readLine()

    if choose == 5 {
        break
    }
}
