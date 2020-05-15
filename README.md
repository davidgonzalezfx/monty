![GitHub contributors](https://img.shields.io/github/contributors/davidgonzalezfx/monty?color=success)
![GitHub stars](https://img.shields.io/github/stars/davidgonzalezfx/monty?color=yellow)
![Twitter Follow](https://img.shields.io/twitter/follow/davidgonzalezfx?color=blue&label=%40davidgonzalezfx)
![Twitter Follow](https://img.shields.io/twitter/follow/elhumanimal?logoColor=red&style=social&label=@elhumanimal)

<h3 align="center"> Stack, Queues - LIFO, FIFO </h3>

#### Description
We built and monty files (.m) interpreter with C programming language. Monty 0.98 is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack, with specific instructions to manipulate it. We implement some op_codes like add, pop and print elements from the stack/queue.

**Monty byte code files**

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

#### Usage
You have to clone this repo and compile with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic 
``` bash
$ git clone https://github.com/davidgonzalezfx/monty
$ cd monty
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$ ./monty 001.m
```

