ok = input()
try:
    result = eval(ok)
    print(str(result).replace(" ", ""))
except:
    print("ERROR")
