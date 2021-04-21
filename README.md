# SIMPLE SHELL

The ***shell*** is your interface to the operating system. It acts as a
***command interpreter***; takes each command and passes it to the operating
system. It then displays the results of this operation on your screen.

`the shell` works like the bash and other basic shells.

The shell works by being compiled using GCC 4.8.4 compiler or later versions.
The shell can compile using `gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o shell`.

## How to launch the shell after compiling:

`./shell`

- Output: prompt to terminal: $


### Syntax

The shell works once the user enters a command. The shell commands take in the following
syntax: `command name {arguments}`. The shell will execute a command ater it is keyed
in by the user using the command followed by the arguments.

`mkdir shell.h` This example takes in a command by the user followed by the arguments.
In this case the command is `mkdir` (to make a new directory) followed by argument
the file name, in this case `holberton.h`.

For more information on mkdir, one can use `man` command which will show a manual of the given
command or any other command.

### Built-ins

The shell also includes two built-ins which are commands that are within the shell itself.
The two built-ins are `exit` and `env`.

- `env` - it is a command that that tells the shell program to display all the environment
variables with their values. It is a way of accessing the values throught the shell.

- `exit` - if the user wishes to exit the the shell, they can use this command.

### Exiting commands and the shell

To exit a commmand or the process, a user can use `ctrl c`. `ctrl c` stops a process
and causes it to abort. You can also use `ctrl D`, which will just exit and give an
exit status of ***0***.

In our shell  program, to exit the process, we use `exit` command, which will
abort the process.

## Compilation

All files will be compiled with gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

## Files

- `README.md` - contains the explanation of the Simple Shell functionality.
- `cmd_functions.c` - contains all the functions (majorly built-in) that execute
commands for simple shell
- `command_handling.c` - it processes the execution of the commands
- `env_handling.c` - contains functions that handle environment variables
- `free.c` - contains functions involved in freeing allocated memory
- `generate_argv.c` - generates an array of strings of commands
- `init_REPL.c` - initializes a read eveluate print loop
- `man_1_simple_shell` - the program's manpage/manual
- `path.c` - functions that handle the program's path
- `shell.c` - initializes the `simple shell`. It is the program's entry point
- `shell.h` - header file. Contains all the prototypes for functions used and libraries
- `string_funcs.c` -  contains string functions
- `string_funcs2.c` - contains string functions

## Authors

- Alex Steve - https://github.com/candiepih
- Joan Mbarire - https://github.com/Joan61

