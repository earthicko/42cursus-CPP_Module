# 개요

C++ templates

## ex00

|Files to turn in|Forbidden functions|
|----------------|-------------------|
|`Makefile`, `main.cpp`, `whatever.{h, hpp}`|None|

Implement the following function templates:

- `swap`: Swaps the values of two given arguments. Does not return anything.
- `min`: Compares the two values passed in its arguments and returns the smallest one. If the two of them are equal, then it returns the second one.
- `max`: Compares the two values passed in its arguments and returns the greatest one. If the two of them are equal, then it returns the second one.

These functions can be called with any type of argument. The only requirement is that the two arguments must have the same type and must support all the comparison operators.

> Templates must be defined in the header files.

Running the following code:

```cpp
int	main(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return (0);
}
```

Should output:

```
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

## ex01

|Files to turn in|Forbidden functions|
|----------------|-------------------|
|`Makefile`, `main.cpp`, `iter.{h, hpp}`|None|

Implement a function template iter that takes 3 parameters and returns nothing.

- The first parameter is the address of an array.
- The second one is the length of the array.
- The third one is a function that will be call on every element of the array.

Turn in a `main.cpp` file that contains your tests. Provide enough code to generate a test executable.

Your iter function template must work with any type of array. The third parameter can be an instantiated function template.

## ex02

|Files to turn in|Forbidden functions|
|----------------|-------------------|
|`Makefile`, `main.cpp`, `Array.{h, hpp}` and optional file: `Array.tpp`|None|

Develop a class template Array that contains elements of type T and that implements the following behavior and functions:

- Construction with no parameter: Creates an empty array.
- Construction with an `unsigned int n` as a parameter: Creates an array of n elements initialized by default.
  - Tip: Try to compile `int * a = new int();` then display `*a`.
- Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn’t affect the other array.
- You MUST use the operator `new[]` to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.
- Elements can be accessed through the subscript operator: `[ ]`.
- When accessing an element with the `[ ]` operator, if its index is out of bounds, an `std::exception` is thrown.
- A member function `size()` that returns the number of elements in the array. This member function takes no parameter and musn’t modify the current instance.

As usual, ensure everything works as expected and turn in a `main.cpp` file that contains your tests.
