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

#### 為了解決上述的問題 ####

以下解法由 @xnum 提供

透過加入前綴的方式，使得上傳者的函數都附加前綴修飾，如 [stackoverflow: How can I get gcc to add a prefix to all symbol names](https://stackoverflow.com/questions/10157680/how-can-i-get-gcc-to-add-a-prefix-to-all-symbol-names) 所描述的，透過 `objcopy --prefix-symbols=student_ part.o` 之類的方式運行。這麼做會有以下幾項缺點

* 主程式在呼叫函數時需要加入前綴
* 主程式引入標頭檔時，必須使用前處理 (`#define run student_run`) 覆蓋原先的命名方式，這做法相當不直觀
* 若學生使用外部的函數庫，編譯時將會出錯，導致無法與一般編譯情況相當。例如使用 `printf(...)`，自動加入前綴後產生 `student_printf(...)`，導致找不到相關函數而編譯錯誤，需要特別加入判斷名單。

為長久的計畫去規劃，我們需要避開一些經常變動的操作，那麼透過 Linker 優先權操作可以使得學生撰寫的程序，函數名稱相同時無效化。這一點可以由 `objcopy --weaken part.o` 將所有 object file 下的 symbol 屬性都改為 weak。常見的有以下幾種 LOCAL, GLOBAL, WEAK ... 等。缺點如下：

* 必須列出可能會有危害的函數清單於主程式中
* 編譯時導致某些函數不生效時，造成 debug 上的痛苦 (不如預期的結果)




