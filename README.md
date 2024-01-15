# Operating Systems and System Programming Project Repository
## Author: Emil Haapalainen

# Reverse

Simple program to reverse the contents of input stream or file with the ability to write the changes to an output file or print them to the terminal.
**Usage**

       prompt> ./reverse       (CTRL+D to stop inputting new lines)
       prompt> ./reverse input.txt
       prompt> ./reverse input.txt output.txt

# Unix Utilities
## My-cat

Simple alternative to UNIX cat command. Prints the contents of file(s) to stdout.
Fiels are given as arguments, multiple allowed.

**Usage**
```
prompt> ./my-cat {file1} {file2} ...
```

## My-grep

Simple alternative to UNIX grep command.
Looks for user-specified search term in file(s) and prints the line if found.
Search is case sensitive, thus "dog" and "Dog" will not match.
If nothing is found, program simply exits.
Multiple files are allowed.

**Usage**
```
prompt> ./my-grep {search} {file1} {file2} ...

Example: ./my-grep "spaniel" "dogBreeds.txt"
```

## My-zip & My-unzip

Utility to compress files using run-length encoding (RLE)
n characters of same type in a row converts to number n and single character

aaaaaaaaaabbbb => 10a4b (4-byte integer, 1 element, 5-byte entry)
**Usage**
```
prompt> ./my-zip file1.txt file2.txt ... > file.z
prompt> ./my-unzip file.z
```

# Kernel Hacking

Project goal was to add your own system call, getreadcount(), which simply returns how many times the read() system call has been called by user processes since the time that the kernel was booted.

The system call returns the value of the readcount counter, which is incremented each time a process calls the read() system call.

*Modified files to make getreadcount():*

```
syscall.c
syscall.h
sysproc.c
user.h
usys.S
```
*User-mode*
```
getreadcount.c/
```
