# Rylang interpreter

C interpreter that interprets Rylang.

```bash
go build -buildmode=c-shared -o convertCode.so convertCode.go
gcc -o ry ry.c convertCode.so
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
./ry hello.ry
```

## About
This project is inspired by [lotabout/write-a-C-interpreter](https://github.com/lotabout/write-a-C-interpreter) and is largely based on it.

## Rylang

Rylang is a Chinese programming language based on C. The keywords of Rylang are totolly Chinese. But the punctuation marks of Rylang should use English version like C. That means you should use `(),;` instead of `（），；` , so it will never be a programming language used in practical. Just have fun!

## Example

| Rylang                        | C                          |
| ----------------------------- | -------------------------- |
| 主函数                        | main                       |
| 返回                          | return                     |
| 循环当 (Condition) {}         | while (Condition) {}       |
| 字符                          | char                       |
| 整型                          | int                        |
| 空值                          | void                       |
| 枚举 {}                       | enum {}                    |
| 如果 (Condition) {}           | if (Condition) {}          |
| 其他 {}                        | else {}                     |
| 占用空间 ()                    | sizeof ()                   |
| 打开 ()                       | open ()                    |
| 关闭 ()                       | close ()                   |
| 打印 ()                       | printf ()                  |
| 内存分配 ()                   | malloc ()                  |
| 内存设置 ()                   | memset ()                  |
| 内存拷贝 ()                   | memcmp ()                  |
| 退出 (0)                      | exit (0)                   |
| 整型 *爱 = 1;                 | int *i = 1;                |
| 循环当 ( 爱 < 520 ) { 爱++; } | while ( i < 520 ) { i++; } |

A example of Rylang `hello.ry` :

```
整型 斐波那契 (整型 标记) {
    如果 (标记 <= 1) {
        返回 1;
    }
    返回 斐波那契(标记 - 1) + 斐波那契 (标记 - 2);
}

整型 主函数() {
    整型 标记;
    标记 = 0;
    循环当 (标记 <= 10) {
        打印("斐波那契(%2d) = %d\n", 标记, 斐波那契(标记));
        标记 = 标记 + 1;
    }
    返回 0;
}
```

