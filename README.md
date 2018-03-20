# AcceleratedCPPCh12-1MemoryManagingStr

Str class is a similar class to the standard library's string class. It 
manages its own memory of array of chars, provides iterators for random 
access, and can grow as needed when append is called. 

Exercise 12-0
Implement the Str class that simplifies the string class as defined by the
standard library. 

Exercise 12-1
Implement the Str class, but choose an implementation strategy that requires
that the class manage the storage itself. For example, you might store an
array of char and a length.

Exercise 12-2
Implement the c_str, data, and copy functions that the string library
implements in order to convert a string into a null-terminated char array
without causing memory management issues */

Exercise 12-3 and 12-4
Define the relational, equality, and inequality operators for Str using strcmp


Exercise 12-5
Implement concatenation for Str without relying on conversions from const
char* 

Exercise 12-6
Give Str an operation that will let us implicitly use a Str object as a
condition. The test should fail if the Str is empty, and should succeed
otherwise. 

Exercise 12-7
Add iterators and the iterator operations begin and end to your Str class,
similar to how the string class provides random access iterators to manipulate
the string's characters. 

Exercise 12-8
Add the getline function to the Str class
