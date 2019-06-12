#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int token;            // current token
char *src, *old_src;  // pointer to source code string;
int poolsize;         // default size of text/data/stack
int line;             // line number

/*
代码段（text）用于存放代码（指令）
数据段（data）用于存放初始化了的数据，如int i = 10;，就需要存放到数据段中
未初始化数据段（bss）用于存放未初始化的数据，如 int i[1000];，因为不关心 其中的真正数值，所以单独存放可以节省空间，减少程序的体积
栈（stack）用于处理函数调用相关的数据，如调用帧（calling frame）或是函数的 局部变量等
堆（heap）用于为程序动态分配内存
+------------------+
|    stack   |     |      high address
|    ...     v     |
|                  |
|                  |
|                  |
|                  |
|    ...     ^     |
|    heap    |     |
+------------------+
| bss  segment     |
+------------------+
| data segment     |
+------------------+
| text segment     |      low address
+------------------+
*/
int *text,            // text segment
    *old_text,        // for dump text segment
    *stack;           // stack
char *data;           // data segment

/*
PC 程序计数器，它存放的是一个内存地址，该地址中存放着 下一条 要执行的 计算机指令
BP 基址指针。也是用于指向栈的某些位置，在调用函数时会使用到它
SP 指针寄存器，永远指向当前的栈顶。注意的是由于栈是位于高地址并向低地址 增长的，所以入栈时 SP 的值减小
AX 通用寄存器，我们的虚拟机中，它用于存放一条指令执行后的结果
*/
int *pc, *bp, *sp, ax, cycle; // virtual machine registers


// 用于词法分析，获取下一个标记，它将自动忽略空白字符
void next() {
    token = *src++;
    return;
}

// 用于解析一个表达式
void expression(int level) {
    // do nothing
}

// 语法分析的入口，分析整个C语言程序
void program() {
    next();  // get next token
    while (token > 0) {
        printf("token is: %c\n", token);
        next();
    }
}

// 虚拟机的入口，用于解释目标代码
int eval() {  // do nothing yet
    return 0;
}

int main(int argc, char **argv) {
    int i, fd;

    argc--;
    argv++;

    poolsize = 256 * 1024;  // arbitrary size
    line = 1;

    if ((fd = open(*argv, 0)) < 0) {
        printf("could not open(%s)\n", *argv);
        return -1;
    }

    if (!(src = old_src = malloc(poolsize))) {
        printf("could not malloc(%d) for source area\n", poolsize);
        return -1;
    }

    // read the source file
    if ((i = read(fd, src, poolsize - 1)) <= 0) {
        printf("read() returned %d\n", i);
        return -1;
    }
    src[i] = 0;  // add EOF character
    close(fd);

    // allocate memory for virtual machine
    if (!(text = old_text = malloc(poolsize))) {
        printf("could not malloc(%d) for text area\n", poolsize);
        return -1;
    }
    if (!(data = malloc(poolsize))) {
        printf("could not malloc(%d) for data area\n", poolsize);
        return -1;
    }
    if (!(stack = malloc(poolsize))) {
        printf("could not malloc(%d) for stack area\n", poolsize);
        return -1;
    }

    memset(text, 0, poolsize);
    memset(data, 0, poolsize);
    memset(stack, 0, poolsize);

    program();
    return eval();
}