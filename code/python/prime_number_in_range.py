##Enter the range of numbers
## m is the starting number
## n is the ending number
## both m and n are included.
m=int(input())
n=int(input())
for num in range(m,n+1):
   if num > 1:
       for i in range(2,num):
           if (num % i) == 0:
               break
       else:
           print(num)
    
##Output:
##4
##10
##5
##7
