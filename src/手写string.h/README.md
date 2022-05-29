#### 进一步理解 strcmp

```c
char str1[] = "asd";
char str2[] = "Asd";

printf("%d", strcmp(str1, str2)); // 32
printf("%d", 'a' - 'A');          // 32
```

#### strncmp

```c
// 函数原型
int strncmp(const char * s1, const char * s2, size_t n);

// 支持限制比较字符的个数，比如我们只想比较前 3 个字符，只需给 n 赋值 3
```

#### 字符串中找字符第一次出现的位置（返回 NULL 则表示没找到）

```c
// 函数原型
char * strchr(const char * s, int c);   // 从左向右找
char * strrchr(const char * s, int c);  // 从右向左找

// 举个例子
char str[] = "hello";
char * ptr = strchr(str, 'l');
printf("%s\n", ptr); // llo

char * ptr2 = strchr(ptr + 1, 'l');
printf("%s\n", ptr2); // lo
```

#### 截取字符串

```c
#include <stdlib.h>

char str[] = "hello"; // 尝试截取 "he"

// 申请空间
char * str2 = (char *)malloc(strlen(str) + 1);

// 把从左到右的第一个 l 缓存住
char * ptr = strchr(str, 'l'); char _t = *ptr;

// 截取
*ptr = '\0';
strcpy(str2, str);
*ptr = _t;
```

#### 字符串中找字符串

```c
// 函数原型
strstr(const char * s1, const char * s2);
strcasestr(const char * s1, const char * s2);

// case means: 忽略大小写
```
