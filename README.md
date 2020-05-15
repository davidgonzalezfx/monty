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

#### Valid op_codes
- [X] **push**: pushes an element to the stack
- [X] **pall**: prints all the values on the stack
- [X] **pint**: prints the value at the top of the stack
- [X] **pop**:  removes the top element of the stack
- [X] **swap**: swaps the top two elements of the stack
- [X] **add**: adds the top two elements of the stack
- [X] **nop**: doesn’t do anything
- [X] **sub**: subtracts the top element of the stack from the second top element of the stack
- [X] **div**: divides the second top element of the stack by the top element of the stack
- [X] **mul**: multiplies the second top element of the stack with the top element of the stack
- [X] **mod**: computes the rest of the division of the second top element of the stack by the top element of the stack
- [X] **\#:** Every good language comes with the capability of commenting. 
- [X] **pchar**: prints the char at the top of the stack
- [X] **pstr**: prints the string starting at the top of the stack
- [X] **rotl**: rotates the stack to the top
- [X] **rotr**: rotates the stack to the bottom
- [X] **stack**: sets the format of the data to a stack (LIFO). This is the default behavior of the program
- [X] **queue**: sets the format of the data to a queue (FIFO)

#### Examples

``` bash
$ cat 00.m
push 0 working with stacks
push 1
push 2
  push 3
                   pall
      push    4        
pall
pint
$ ./monty 00.m
3
2
1
0
4
3
2
1
0
4
```
``` bash
$ cat 01.m
push 1
push 2
push 3
pall
pop
pint
$ ./monty 01.m
3
2
1
2
```
``` bash
$ cat 02.m
push 1
push 2
push 3
pall
swap
$ ./monty 02.m
3
2
1
2
3
1
```
``` bash
$ cat 03.m
push 1
push 2
push 3
pall
add
pall
$ ./monty 03.m
3
2
1
5
1
```

#### Project files
| File | Description/functions |
|-------|-----------|
| **[README.md](./README.md)** | *All what you need to understand this project*|
| **[main.c](./main.c)** | *Entry point function of project* |
| **[monty.h](./monty.h)** | **Header File**: contains all prototypes |
| **[stack_aux_funs.c](./stack_aux_funs.c)** | **delete_dnodeint_at_end**: deletes the node at end <br> **add_dnodeint_end**: adds a new node at the end <br> **add_dnodeint**: adds a new node at the beginning <br> **print_dlistint**: prints all the elements of a stack_t list <br> **free_dlistint**: free a stack_t list |
| **[stack_aux2_funs.c](./stack_aux2_funs.c)** | **dlistint_len**: return length of linkedlist <br> **is_num**: check if string is a number <br> **pstr**: prints the string starting at the top of the stack <br> **rotl**: rotate the stack to the top <br> **rotr**: rotate the stack to the bottom |
| **[stack_core_funs.c](./stack_core_funs.c)** | **swap**: swap last two elements  <br> **pall**: print all function <br> **pint**: print top element <br> **pop**: remove top element <br> **add**: add last to elements in one |
| **[stack_logic_funs.c](./stack_logic_funs.c)** | **validate_opcode**: function that validates first token against valid opcodes in dictonary <br> **monty_logic**: core project <br> **empty**: function for non executable op_codes <br> **push**: fuction to push elements <br> **handle_errors**:print errors handler |
| **[stack_advanced_funs.c](./stack_advanced_funs.c)** | **sub**: sub last to elements in one <br> **_div**: div last to elements in one <br> **mul**: mul last to elements in one <br> **mod**:  mod last to elements in one <br> **pchar** :prints the char at the top of the stack <br> |

Jairo Sandoval - [@sandovbarr](https://github.com/sandovbarr)<br>
David Gonzalez - [@davidgonzalezfx](https://github.com/davidgonzalezfx)<br>
