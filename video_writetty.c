#include "video_mdos.h"

void video_writetty(unsigned const char* msg) {
  __asm__("li r0, >0027\n\t"
          "mov %0, r1\n\t"
	  "clr r2\n\t"
	  "xop %1, 0\n\t"
	  :
	  : "r" (msg), "m" (XOP_VIDEO)
	  : "r0", "r1", "r2");
}

