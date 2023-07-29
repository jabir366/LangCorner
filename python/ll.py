#!/usr/bin/python3

class Node:
    def __init__(self,data):
        self.data = data
        self.next=None

class LinkedList:
    def __init__(self):
        self.head = None
    def push(self, new_data):
        node = Node(new_data)
        node.next=self.head
        self.head = node
    def print(self):
        point = self.head
        while(point is not None):
            print(point.data,'->')
            point=point.next
        


print("hello")
ll= LinkedList()
ll.push(4)
ll.push(5)
ll.print()


