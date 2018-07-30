#include "key_mdos.h"


int key_scan(int mode, unsigned char* code, unsigned char* joyx, unsigned char* joyy) {
  int res = 0;
  __asm__("mov %3, r0\n\t"
	  "li r1, >FF00\n\t"
	  "xop %4, 0\n\t"
	  "movb r1, %0\n\t"
	  "movb r2, %1\n\t"
	  "swpb r2\n\t"
	  "movb r2, %2\n\t"
	  : "=m" (code), "=m" (joyx), "=m" (joyy)
	  : "r" (mode), "m" (XOP_KEY)
	  : "r0", "r1", "r2");
  return res;
}

