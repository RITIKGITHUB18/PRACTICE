# print("Hello World")

# friends = ["APPLE","ORANGE",1,2,False];
# print(friends[1]);

# n = int(input("Enter the number: "))

# for i in range(1,n+1):
#     print(" " * (n-i),end="")
#     print("*" * (2*i-1),end="")
#     print("")

# print("\n")

# for j in range(1,n+1):
#     print("*" * (j),end="")
#     print("")

# print("\n")

# for k in range (1,n+1):
#     if(k==1 or k==n):
#         print("*"*(n),end="")
#         print("")
#     else:
#         print("*",end="")
#         print(" "*(n-2),end="")
#         print("*",end="")
#         print("")
        
        
# m = int(input("Enter the number for table: "))

# for i in range(1,11):
#     print(f"{m}X{11-i} = {m*(11-i)}")


# for i in range(10,0,-1):
#     print(f"{m}X{i} = {m*i}")




# def greet():
#     name = input("Enter the name of user: ")
#     print(f"Have a nice day, {name}")

# greet()

# def factorial(m):
#     if (m==1 or m==0):
#         return 1
#     else:
#         return m*factorial(m-1)

# result = factorial(5)    
# print("factorial of 5: ",result)

# I. Write a program using functions to find greatest of three numbers.

# def greatest(a,b,c):
#     if(a>b and a>c):
#         print("a is greatest number")
#     elif(b>a and b>c):
#         print("B is the greatest number")
#     else:
#         print("c is the greatest number")        

# greatest(4,9,3)


def sum_n(n):
    if(n==0):
        return 0
    else:
        return n + sum_n(n-1)

result = sum_n(5)
print("Sum of n number using recursion: ",result)    