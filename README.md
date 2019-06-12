# Rylang interpreter

C interpreter that interprets Rylang.

```bash
go build -buildmode=c-shared -o convertPinyin.so convertPinyin.go
gcc -o ry ry.c convertPinyin.so
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
./ry hello.ry
```

## About
This project is inspired by [lotabout/write-a-C-interpreter](https://github.com/lotabout/write-a-C-interpreter) and is largely based on it.
