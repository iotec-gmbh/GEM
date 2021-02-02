// only include GLCD support, if the "dont use" define was not defined (can be defined ad project level).
#ifndef GEM_DONT_USE_GLCD
    #include "config/enable-glcd.h"         // Enable AltSerialGraphicLCD version of GEM
#endif

// only include U8G2 support, if the "dont use" define was not defined (can be defined ad project level).
#ifndef GEM_DONT_USE_U8G2
    #include "config/enable-u8g2.h"         // Enable U8g2 version of GEM
#endif

#include "config/support-float-edit.h"  // Support for editable float and double variables (option selects support them regardless of this setting)