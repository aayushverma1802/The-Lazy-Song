class Con:
    def __init__(self):
        print("This is the contructor output")

class manual:
    def __init__(self,a,b):
        self.result= a+b
        print(self.result)
    
Con()
manual(12,23)   