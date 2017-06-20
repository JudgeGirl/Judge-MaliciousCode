#include <stdio.h>

#include "part.h"

int __libc_start_main(int (*main) (int, char * *, char * *), 
    int argc, char * * argv, void (*init) (void), 
    void (*fini) (void), void (*rtld_fini) (void), 
    void (* stack_end))
{
  char **envp = argv+argc+1;
  

  (*init)();
  int ret = main(argc, argv, envp);

  exit(ret);
}

int main() {
	puts("GO");
	foo();
	return 0;
}
