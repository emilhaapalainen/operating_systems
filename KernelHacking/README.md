# Intro to Kernel Hacking

## Author: Emil Haapalainen
## getreadcount system call

Project goal was to add your own system call, **getreadcount()**, which simply returns how many times the **read()** system call has been called by user processes since the time that the kernel was booted.

The system call returns the value of the **readcount** counter, which is incremented each time a process calls the **read()** system call.

# COMMON ERRORS
**Permission denied **
At sign.pl --> 
´´´
chmod +x sign.pl
´´´
At vectors.pl 
´´´
chmod +x vectors.pl
´´´
**Other**
´´´
make clean
make qemu-nox
´´´

## Additional help used for project

https://medium.com/@mahi12/adding-system-call-in-xv6-a5468ce1b463

https://www.geeksforgeeks.org/xv6-operating-system-adding-a-new-system-call/

https://www.youtube.com/watch?v=21SVYiKhcwM

https://www.youtube.com/watch?v=vR6z2QGcoo8
