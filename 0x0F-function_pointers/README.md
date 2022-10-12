#Function Pointer in C
---
In C, like normal data pointers (int *, char *, etc), we can have pointers to functions. 

Following are some interesting facts about function pointers.

 
1) Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer stores the start of executable code.

2) Unlike normal pointers, we do not allocate de-allocate memory using function pointers.

 
3) A function’s name can also be used to get functions’ address.

4) Like normal pointers, we can have an array of function pointers.
 
5) Function pointer can be used in place of switch case

6) Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function.
