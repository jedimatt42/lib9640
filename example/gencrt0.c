/* Entry point for C runtime initilization code
*
* This will set initial values for data memory and otherwise create
* the conditions needed for the C environment */
extern int main(void);

#ifdef __cplusplus
extern "C"
#endif

void _start2(void)
{
  /* Fill .data section with initial values */
  {
    extern int __VAL_START;
    extern int __DATA_START;
    extern int __DATA_END;
    char *src = (char*)&__VAL_START;
    char *dst = (char*)&__DATA_START;
    while(dst < (char*)&__DATA_END)
    {
      *dst++ = *src++;
    }
  } 

  /* Erase .bss section */
  {
    extern int __BSS_START;
    extern int __BSS_END;
    char *dst = (char*)&__BSS_START;
    while(dst < (char*)&__BSS_END)
    {
      *dst++ = 0;
    }
  }

#ifdef __cplusplus
  /* Call all initial constructors.
  * The .ctors section is filled with function pointers to constructors. 
  * Iterate through them and call each function. */
  {
    extern int __CTOR_START;
    extern int __CTOR_END;
    typedef void(*funcptr)(void);
    funcptr *ctor = (funcptr*)&__CTOR_START;
    while(ctor < (funcptr*)&__CTOR_END)
    {
      (*(ctor++))();
    }
  }
#endif

  /* Start running C code */
  main();

  /* return to MDOS */
  __asm__("blwp @>0000");
}

// Todo: acquire page from MDOS instead, this will break if program 
// is within 1k of 8k boundary.
char mystack[1024];

#ifdef __cplusplus
extern "C"
#endif
void _start(void)
{
  /* Set initial workspace
  *
  * The registers will be located at the start of scratchpad memory */
  __asm__("lwpi >F000" );

  /* Create the stack before declaring any variables */
  __asm__("li sp, mystack+1024");

  /* Call the second part directly to prevent a stack for this function */
  __asm__("b @_start2");
}


