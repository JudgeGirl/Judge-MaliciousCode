
int __libc_start_main(int (*main) (int, char * *, char * *), 
    int argc, char * * argv, void (*init) (void), 
    void (*fini) (void), void (*rtld_fini) (void), 
    void (* stack_end))
{
  char **envp = argv+argc+1;
  
  puts("I want to exit"), exit(0);
  printf("my __libc_start_main start\n");

  (*init)();
  int ret = main(argc, argv, envp);

  printf("my __libc_start_main end\n");

  exit(ret);

}

