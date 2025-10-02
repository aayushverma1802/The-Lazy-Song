class Node:
    def __init__(self,value):
        self.data=value
        self.next=None
    
class Stack:
    def __init__(self):
        self.top=None
    
    def isempty(self):
        return self.top==None 
    
    def push(self,value):
        new_node=Node(value)
        new_node.next=self.top
        self.top=new_node
         
    def traverse(self):
        temp=self.top
        while temp!=None:
            print(temp.data)
            temp=temp.next

    def peek(self):
        if(self.isempty()):
            return "Stack Empty"
        else:
            return self.top.data
    
    def pop(self):
        if(self.isempty()):
            return "Stack Empty"
        else:
            self.top=self.top.next

s=Stack()
print(s.isempty())
s.push(10)
s.push(20)
s.push(30)
s.push(40)
s.traverse()
s.peek()
print(s.isempty())
print(s.peek())