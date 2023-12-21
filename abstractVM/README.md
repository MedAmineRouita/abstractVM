AbstractVM

AbstractVM is a simple stack-based virtual machine that interprets programs written in a simple assembly language. It performs basic arithmetic operations on various data types.
Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.
Prerequisites

To build and run this project, you'll need:

    C++ compiler
    GNU Make

to compile the project:

make

This will create an executable file named abstractVM.
Usage

You can run AbstractVM with an assembly file as an argument:

./abstractVM example.avm

Or you can enter assembly commands directly from the standard input:

./abstractVM
push int32(2)
push int32(3)
add
assert int32(5)
dump
exit
;;

The program will stop executing with an error code 84 if there's any issue (e.g., pop instruction on an empty stack, division/modulo by 0, assert instruction not verified, etc.). Otherwise, it will exit with 0 if there's no error.

For more information about the assembly language and the operations, see ASSEMBLER LANGUAGE.
Assembler Language

AbstractVM's assembly language has the following instructions:

    push <type>(value): pushes the value to the stack. Value should be one of the following forms: int8(n), int16(n), int32(n), float(z), double(z).
    pop: removes the top value from the stack. Stops the program execution if the stack is empty.
    dump: displays each value on the stack from the newest to the oldest, without modifying the stack.
    assert <type>(value): verifies that the top value of the stack equals the provided value. Stops the program execution if it's not the case.
    Arithmetic instructions (add, sub, mul, div, mod): perform the corresponding operation on the top two values of the stack and push the result back to the stack. Stop the program execution if there are less than two values in the stack or if the divisor is 0 for div and mod.
    And others. Please refer to the project documentation for the full instruction set.

Error Handling

In case of any errors (e.g., lexical or syntactical errors, overflow or underflow on a value, etc.), AbstractVM will raise an exception and stop the program execution.