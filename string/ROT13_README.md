# REFERENCES:
>> 
https://stackoverflow.com/questions/2603039/warning-comparison-with-string-literals-results-in-unspecified-behaviour

>>
The expression argc[i] == "&" checks if the two pointers
are the same (point to the same memory location).

The expression strcmp( argc[i], "&") == 0 will check
if the contents of the two strings are the same.



>>
There is a distinction between 'a' and "a":
 'a' means the value of the character a.
 "a" means the address of the memory location
     where the string "a" is stored 
     (which will generally be in the data section of your program's memory space). At that memory location, you will have two bytes -- the character 'a' and the null terminator for the string.



>> if (args[i] == "&")

args is an array of pointers. So, here you are comparing args[i] (a pointer) to "&" (also a pointer).
Well, the only way this will every be true is if somewhere you have args[i]="&" and even then, "&" is not guaranteed to point to the same place everywhere.
either strcmp to compare the entire string or your wanting to do if (*args[i] == '&') to compare the first character of the args[i] string to the & character


>> 
https://stackoverflow.com/questions/13006672/i-got-this-warning-sizeof-on-array-function-parameter-will-return-size-of-cons

use strlen(array) instead of sizeof(array[])

