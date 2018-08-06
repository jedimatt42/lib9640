
#include "key_mdos.h"

unsigned char key_getkey() {
  unsigned char code = 0xff;
  int status = 1;
  while(code == 0xff || !(status & 0x2000)) {
    code = key_scan(KEY_MODE_BASIC, &status);
  }
  return code;
}

