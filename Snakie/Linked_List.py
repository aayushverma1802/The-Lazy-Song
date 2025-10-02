class Node:
    def __init__(self,value):
        self.data=value
        self.next=None
    
a=Node(23) 
print(a)
print(a.data)
print(a.next)

print(id(a))