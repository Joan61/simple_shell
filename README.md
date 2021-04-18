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

## Compilation

All files will be compiled with gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

## Files

## Authors

- Alex Steve - https://github.com/candiepih
- Joan Mbarire - https://github.com/Joan61

