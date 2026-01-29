def greet(fx):
    def mfx(*args,**kwargs):
        print("Good Morning")
        fx(*args,**kwargs)
        print("Code executed successfully")
    return mfx

@greet 
def hello(a,b):
    print(a+b)

greet(hello)(5,5)

# --- Add this line to run the code ---
hello(10, 20)

