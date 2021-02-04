// Automatically enabled GLCD support. Can be disabled by adding the `GEM_DONT_USE_GLCD` define to your project level. 
#ifndef GEM_DONT_USE_GLCD
    #include "config/enable-glcd.h"         // Enable AltSerialGraphicLCD version of GEM
#endif

// Automatically enabled U8G2 support. Can be disabled by adding the `GEM_DONT_USE_U8G2` define to your project level. 
#ifndef GEM_DONT_USE_U8G2
    #include "config/enable-u8g2.h"         // Enable U8g2 version of GEM
#endif

#include "config/support-float-edit.h"  // Support for editable float and double variables (option selects support them regardless of this setting)
