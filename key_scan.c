#include "key_mdos.h"


unsigned char key_scan(int mode, int* status) {
  int st;
  unsigned char key;
  __asm__("mov %2, r0\n\t"
	  "li r1, >FF00\n\t"
	  "xop %3, 0\n\t"
	  "stst %1\n\t"
	  "movb r1, %0\n\t"
	  : "=m" (key), "=r" (st)
	  : "r" (mode), "m" (XOP_KEY)
	  : "r0", "r1", "r2");
  *status = st;
  return key;
}

