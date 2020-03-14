#ifndef SIXTEENKEY_H
#define SIXTEENKEY_H

#include "quantum.h"

#define _BASE       0
#define _RGB        1
#define _MACROS     2

#define LAYOUT( \
      k00, k01, k02, k03, \
      k10, k11, k12, k13, \
      k20, k21, k22, k23, \
      k30, k31, k32, k33 \
) \
{ \
    { k00, k01, k02, k03 }, \
    { k10, k11, k12, k13 }, \
    { k20, k21, k22, k23 }, \
    { k30, k31, k32, k33 } \
}

#endif
