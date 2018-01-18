### Brian Kernighan’s Algorithm:
#### Each time remove the right 1 (when n>0)       
Subtraction of 1 from a number toggles all the bits (from right to left) till the rightmost set bit(including the righmost set bit). So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the righmost set bit. If we do n & (n-1) in a loop and count the no of times loop executes we get the set bit count.
Beauty of the this solution is number of times it loops is equal to the number of set bits in a given integer.

1.  Initialize count: = 0   
2.  If integer n is not zero

      (a) Do bitwise & with (n-1) and assign the value back to n
      
          n: = n&(n-1)
          
      (b) Increment count by 1
      
      (c) go to step 2
3.  Else return count

#### Eg:
##### 1st iteration of loop : n = 52
###### 00110100 (n)    &    
###### 00110011 (n-1)     
###### ========  
###### 00110000    
##### 2nd iteration of loop : n = 48
###### 00110000  (n)    &    
###### 00101111  (n-1)     
###### ========  
###### 00100000 
##### 3rd iteration of loop : n = 32
###### 00100000 (n)    &    
###### 00011111 (n-1)     
###### ========  
###### 00000000 
