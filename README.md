A small simulation of a computer in C. It was an experiment to create the most simple possible programming language. 

It works by taking the address of 1 bit and writing that information to another bit, it cycles from read -> write -> read -> ...

The instructions are thus two numbers.

There are two special memory locations (A, B) which are NAND'd together every cycle and written to C which allows theoretically arbitrary logic operations.

The program is stored in the virtual memory so it can itself be rewritten by its own instructions. This allows for something similar to macro programming.

The program counter is stored directly in memory so can also be manipulated by programs to do rudimentary jump instructions, it is also possible to write to a buffer and send the information to the program counter, for a slightly more refined jump instruction.

There is also a special memory location which when it becomes 1 halts the program. 

Right now this demo only shows a program which starts in memory with potentially arbitrary bits and is guaranteed to halt.
