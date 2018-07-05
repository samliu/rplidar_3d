// Google-style command line flags.
#include "gflags/gflags.h"

#ifndef UTIL_COMMANDLINEFLAGS_H_
#define UTIL_COMMANDLINEFLAGS_H_

namespace base {

template <class T> inline void SetFlag(T *flag, const T &value) {
  *flag = value;
}

template <class T, class V> inline void SetFlag(T *flag, const V &value) {
  *flag = value;
}

template <class T> inline const T &GetFlag(T *flag) { return *flag; }

} // namespace base

#endif // UTIL_COMMANDLINEFLAGS_H_
