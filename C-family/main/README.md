## README ##

在教學時，我們會要求同學撰寫多個檔案，主程式由助教提供，
那麼可能會有幾個 C 上的問題。

首先，一般會有三個檔案 main.c, tool.h, tool.c，
讓同學們練習多檔案的程式撰寫。

* main.c : 由助教方提供，不得更改
* tool.h, tool.c : 由學生上傳的部分

### 安全問題 ###

被竄改的 `main.c`，可以藉由在 tool.h，使用 `#define main foo`，
在 main.c 的 `main()` 就會失效。這是一件很危險的事情，造成學生
可以不上傳正確程序來完成提交。

如果硬要同學上傳 tool.h，我們可以透過在 main.c 裡頭這麼寫

```c
#include "tool.h"
#undef main
```

然而，這種防得了第一步，卻防不了接下來對於 gcc 深入了解的同學。
透過 `__libc_start_main(...)` ... 等函數，就可以在 main 函數之前運行。

