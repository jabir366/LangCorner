#given an int. 
# if it is power or not

def ispowerof_two(number):
    
    # 16/2 8/2 4/2 2 
    # 18/9 
    result = number/2
    # print("result is",result)
    # roeturn False
    if result != int(result):
        return False
    while result >0:
        print("result is",result)
        if result == 2 :
            return True
        if result %2 == 1 :
            return False
        result = result/2
    return True

print("Giving 16")

num  = 34
if ispowerof_two(num):
    print( f"{num} is Power of 2")
else:
    print( f"{num} is not Power of 2")


