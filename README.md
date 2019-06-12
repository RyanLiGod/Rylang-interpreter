# RyLang interpreter

C++ interpreter that interprets RyLang.

```bash
gcc -o ry ry.c
./ry hello.ry
./ry -s hello.ry

./ry ry.c hello.ry
./ry ry.c ry.c hello.ry
```

## About
This project is inspired by [lotabout/write-a-C-interpreter](https://github.com/lotabout/write-a-C-interpreter) and is largely based on it.