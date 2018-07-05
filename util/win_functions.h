#ifndef UTIL_WIN_FUNCTIONS_H_
#define UTIL_WIN_FUNCTIONS_H_
// TODO(samcliu): Fix these. They don't seem to work. They were implemented by
// the DynamixelSDK.
//
// Cross-platform utility methods generally available only on Windows.
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

namespace util {
namespace win_functions {
// Visual C++ function on Windows that gets a character from the console without
// echo'ing the character. Can't read CTRL+C. When reading function or arrow
// keys, must be called twice (first call will return 0 or 0xE0), then second
// will contain actual key code.
int getch() {
#ifdef __linux__
  struct termios oldt, newt;
  int ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
#elif defined(_WIN32) || defined(_WIN64)
  return _getch();
#endif
}

// Visual C++ function on Windows that returns nonzero value if a key has been
// pressed, otherwise returns 0. If key has been pressed, you can collect the
// keystoke via `getch()`.
int kbhit(void) {
#ifdef __linux__
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
#elif defined(_WIN32) || defined(_WIN64)
  return _kbhit();
#endif
}
} // namespace win_utils
} // namespace util
#endif // UTIL_WIN_FUNCTIONS_H_
