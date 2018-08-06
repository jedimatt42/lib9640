
#include "video_mdos.h"
#include "key_mdos.h"

int main() {

  unsigned char code[2];
  code[0] = 0xff;
  code[1] = 0;
  int status = 0;
  while(code[0] != 13 && code[0] != 'q') {
    code[0] = key_scan(KEY_MODE_STANDARD, &status);
    if (code[0] != 0xff && (status & 0x2000)) {
      video_writetty(code);
    }
  }
  video_writetty("\r\n");

  video_writetty("Bye!\r\n");
  // ignored right now.
  return 0;
}
