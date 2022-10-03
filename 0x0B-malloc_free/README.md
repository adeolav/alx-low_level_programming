Automatic and dynamic allocation, malloc and free
The malloc function is used to allocate a certain amount of memory during the execution of a program. It will request a block of memory from the heap. If the request is granted, the operating system will reserve the requested amount of memory and malloc will return a pointer to the reserved space.

When the amount of memory is not needed anymore, you must return it to the operating system by calling the function free.
----
Tasks

0. Float like a butterfly, sting like a bee

0-create_array.c: C function that returns a pointer to a newly-allocated space in memory containing an array of characters.
The array of characters is initialized to the parameter c.
If the function fails or receives size equal to 0 - returns NULL.
1. The woman who has no imagination has no wings

1-strdup.c: C function that returns a pointer to a newly-allocated space in memory containing a copy of the string passed as parameter.
Returns a pointer to a new string which is a duplicate of the string str.
Memory for the new string is obtained with malloc and can be freed with free.
If str is NULL or insufficient memory was available - returns NULL.
2. He who is not courageous enough to take risks will accomplish nothing in life

2-str_concat.c: C function that returns a pointer to a newly-allocated space in memory containing the concatenation of two strings passed as parameters.
The returned pointer contains the contents of s1 followed by s2 and is null-terminated.
The function treats NULL as an empty string.
If the function fails - returns NULL.
3. If you even dream of beating me you'd better wake up and apologize

3-alloc_grid.c: C function that returns a pointer to a newly-allocated space in memory containing a two-dimensional array of integers.
Each element of the two-dimensional array is initialized to 0.
If the function fails or either of width or height is 0 or negative - returns NULL.
4. It's not bragging if you can back it up

4-free_grid.c: C function that frees a two-dimensional array previsouly created by the alloc_grid function defined in 3-alloc_grid.c.
The program does not crash upon receiving invalid two-dimensional arrays.
5. It isn't the mountains ahead to climb that wear you out; it's the pebble in your shoe

5-argstostr.c: C function that returns a pointer to a newly-allocated space in memory containing the concatenation of all the arguments of the program.
Each argument is followed by a \n in the new string.
If ac == 0, av == NULL, or the function fails - returns NULL.
6. I will show you how great I am

100-strtow.c: C function that splits a string into words.
Returns a pointer to a newly-allocated space in memory containing an array of strings (words).
Each element of the array of strings contains a single word, null-terminated.
The last element of the returned array is NULL.
Words are separated by spaces.
If str == NULL, str == "", or the function fails - returns NULL.
