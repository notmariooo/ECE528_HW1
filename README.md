# ECE 528/L - Homework 1

## Section I: Review Questions


### Question 1

#### (a) What is the difference between a compiler and an interpreter?

A compiler translates the entire source code into machine code before the program is executed. An interpreter executes the program through an interpreter without first creating a standalone machine-code executable.

#### (b) What is the output of a C program's main() function by default?

The main() function returns an integer value. A return value of 0 indicates that the program executed successfully.


### Question 2

#### What are header files in C and what is the purpose of the #include directive?

A header file contains C declarations and macro definitions. The #include directive is used to include a header file in a C program so that the program can use the declarations and functions provided by that header file. For example, #include <stdio.h> allows the program to use standard input and output functions such as printf().


### Question 3

#### Explain how to declare and define a function in C. What is the purpose of the return statement in a function? Can a function have more than one return statement?

A function declaration tells the compiler the function's name, return type, and parameters. A function definition contains the actual code that the function executes.The return statement ends the function and returns a value to the function that called it. A function can have more than one return statement, but only one return statement will be executed each time the function is called.


### Question 4

#### What is type casting? Provide an example C function that demonstrates explicit type casting from double to int.

Type casting is converting a value from one data type to another. Explicit type casting is done by placing the desired data type in parentheses before the value.

```c
int Add_Doubles(double a, double b)
{
    double sum = a + b;
    return (int)sum;
}
```

In this example, a and b are doubles. Their sum is stored as a double and then explicitly cast to an integer before it is returned.


### Question 5

#### Explain the difference between local and global variables. Provide an example of each.

A local variable is declared inside a function and can only be accessed within that function. A global variable is declared outside of all functions and can be accessed by functions in the program.

```c
int global_variable = 10;

int main(void)
{
    int local_variable = 5;

    return 0;
}
```


In this example, global_variable is global because it is declared outside of main(), while local_variable is local because it is declared inside main().


### Question 6

#### How are strings declared and initialized in C? What is the role of the null terminator '\0'?

C does not have a dedicated string data type. Instead, a string is represented as an array of characters. The null terminator '\0' marks the end of a string. The character array must have enough space for all of the characters and the null terminator.


### Question 7

#### What is a pointer in C? How do you pass a pointer to a function? What advantages are there to passing a pointer instead of a value?

A pointer is a variable that stores the memory address of another variable. A pointer can be passed to a function by passing the address of a variable. Passing a pointer allows a function to directly access and modify the original variable instead of working with a copy of its value. It can also avoid copying large amounts of data.


### Question 8

#### What does the * operator and the & operator do in the context of pointers?

The & operator returns the memory address of a variable. The * operator is used to dereference a pointer, which means accessing the value stored at the memory address contained in the pointer.


### Question 9

#### What is the difference between while and do...while loops?

A while loop checks its condition before executing the loop body. This means that a while loop may execute zero times if the condition is false at the beginning.


### Question 10

#### What does the break statement do? How is it different from the continue statement?

The break statement immediately exits a loop. The continue statement does not exit the loop. Instead, it skips the remaining statements in the current iteration and continues with the next iteration of the loop.


### Question 11

#### Explain the use of bitwise operators (&, |, ^, ~, <<, >>) in C. Which bitwise operators can be used to set, clear, toggle, or check a specific bit in an integer variable?

Bitwise operators perform operations on individual bits of a value.

- `&` performs bitwise AND.
- `|` performs bitwise OR.
- `^` performs bitwise XOR.
- `~` performs bitwise NOT or complement.
- `<<` shifts bits to the left.
- `>>` shifts bits to the right.


### Question 12

#### What is the purpose of the PxSEL0 and PxSEL1 GPIO registers? Write two statements that select the GPIO function for the pins P1.0 and P1.7.

The PxSEL0 and PxSEL1 registers are used to select the function of a pin. To configure a pin as GPIO, its corresponding bit must be cleared to 0 in both PxSEL0 and PxSEL1. P1.0 has the hexadecimal bitmask 0x01 and P1.7 has the hexadecimal bitmask 0x80. Together, the bitmask is 0x81.

```c
P1->SEL0 &= ~0x81;
P1->SEL1 &= ~0x81;
```


### Question 13

#### Write a void function named P1_1_and_P1_4_Init that configures P1.1 and P1.4 as GPIO inputs with pull-up resistors enabled.

```c
void P1_1_and_P1_4_Init(void)
{
    P1->SEL0 &= ~0x12;
    P1->SEL1 &= ~0x12;

    P1->DIR &= ~0x12;

    P1->REN |= 0x12;
    P1->OUT |= 0x12;
}
```


### Question 14

#### Write a void function named Buttons_Init that configures P3.1, P3.6, P5.0, and P5.4 as GPIO inputs with pull-down resistors enabled.

```c
void Buttons_Init(void)
{
    P3->SEL0 &= ~0x42;
    P3->SEL1 &= ~0x42;
    P5->SEL0 &= ~0x11;
    P5->SEL1 &= ~0x11;

    P3->DIR &= ~0x42;
    P5->DIR &= ~0x11;

    P3->REN |= 0x42;
    P5->REN |= 0x11;

    P3->OUT &= ~0x42;
    P5->OUT &= ~0x11;
}
```


### Question 15

#### Write a void function named LEDs_Init that configures P7.0 to P7.7 as GPIO outputs. Initialize the pins to zero.

P7.0 through P7.7 use all eight bits of Port 7, so the hexadecimal bitmask is 0xFF.

```c
void LEDs_Init(void)
{
    P7->SEL0 &= ~0xFF;
    P7->SEL1 &= ~0xFF;

    P7->DIR |= 0xFF;

    P7->OUT &= ~0xFF;
}
```
