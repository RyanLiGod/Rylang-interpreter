# my C interpreter

C interpreter that interprets itself.

```c
gcc -o rc rc.c
./rc hello.c
./rc -s hello.c

./rc rc.c hello.c
./rc rc.c xc.c hello.c
```
