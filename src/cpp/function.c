// Copyright 2012 The Emscripten Authors.  All rights reserved.
// Emscripten is available under two separate licenses, the MIT license and the
// University of Illinois/NCSA Open Source License.  Both these licenses can be
// found in the LICENSE file.

#include <math.h>
#include <emscripten.h>

// If this is an Emscripten (WebAssembly) build then...
#ifdef __EMSCRIPTEN__
  #include <emscripten.h>
#endif

#ifdef __cplusplus
extern "C" { // So that the C++ compiler does not rename our function names
#endif

EMSCRIPTEN_KEEPALIVE
extern int int_sqrt(int x) {
  return sqrt(x);
}

EMSCRIPTEN_KEEPALIVE
extern double my_log (double x) {
  return log(x);
}

#ifdef __cplusplus
}
#endif
