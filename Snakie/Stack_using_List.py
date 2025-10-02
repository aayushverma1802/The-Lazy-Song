# Stack using the list 
stack=[]
#push
stack.append(10)
stack.append(20)
stack.append(30)
stack.append(40)
stack.append(50)
#pop
print("Stack pop: ",stack.pop()) 
#top
print("Stack Top",stack[-1])
# Check if empty
print("Is stack empty ?",len(stack)==0)

#Queue using deque
from collections import deque
queue=deque()
# Enqueue
queue.append(10)
queue.append(20)
queue.append(30)

# Dequeue
print("Queue Dequeue:",queue.popleft())
# Front
print("Queue Front:,",queue[-1])

# Check if empty
print("Is Queue Empty?",len(queue)==0)
