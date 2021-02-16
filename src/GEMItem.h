/*
  GEMItem - menu item for GEM library.

  GEM (a.k.a. Good Enough Menu) - Arduino library for creation of graphic multi-level menu with
  editable menu items, such as variables (supports int, byte, float, double, bool, char[17] data types)
  and option selects. User-defined callback function can be specified to invoke when menu item is saved.
  
  Supports buttons that can invoke user-defined actions and create action-specific
  context, which can have its own enter (setup) and exit callbacks as well as loop function.

  Supports AltSerialGraphicLCD library by Jon Green (http://www.jasspa.com/serialGLCD.html)
  and U8g2 library by olikraus (https://github.com/olikraus/U8g2_Arduino).

  For documentation visit:
  https://github.com/Spirik/GEM

  Copyright (c) 2018-2020 Alexander 'Spirik' Spiridonov

  This file is part of GEM library.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.
  
  You should have received a copy of the GNU Lesser General Public License
  along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <WString.h>     // for __FlashStringHelper (F("asd"))

#include "GEMPage.h"
#include "constants.h"

#ifndef HEADER_GEMITEM
#define HEADER_GEMITEM

// Macro constants (aliases) for menu item types
#define GEM_ITEM_VAL 0        // Menu item represents associated variable
#define GEM_ITEM_LINK 1       // Menu item represents link to another menu page
#define GEM_ITEM_BACK 2       // Menu item represents Back button (that links to parent level menu page)
#define GEM_ITEM_BUTTON 3     // Menu item represents button (that leads to execution of user-defined routine in its own context)
#define GEM_ITEM_LINKED_VAL 4 // Menu item represents a value that is linked to another menu page
#define GEM_ITEM_TEXT 5       // Menu item represents a static text entry

// Macro constant (alias) for readonly modifier of associated with menu item variable
#define GEM_READONLY true

// Macro constant (alias) for hidden state of the menu item
#define GEM_HIDDEN true

// Forward declaration of necessary classes
class GEMPage;
class GEMSelect;

// Declaration of GEMItem class
class GEMItem {
  friend class GEM;
  friend class GEM_u8g2;
  friend class GEMPage;
  public:
    /* 
      Constructors for menu item that represents option select, w/ callback
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*, float, or double)
      @param 'select_' - reference to GEMSelect option select
      @param 'saveAction_' - pointer to callback function executed when associated variable is successfully saved
    */
    GEMItem(const char* const title_, byte& linkedVariable_, GEMSelect& select_, void (*saveAction_)());
    GEMItem(const char* const title_, int& linkedVariable_, GEMSelect& select_, void (*saveAction_)());
    GEMItem(const char* const title_, char* linkedVariable_, GEMSelect& select_, void (*saveAction_)());
    GEMItem(const char* const title_, float& linkedVariable_, GEMSelect& select_, void (*saveAction_)());
    GEMItem(const char* const title_, double& linkedVariable_, GEMSelect& select_, void (*saveAction_)());
    /* 
      Constructors for menu item that represents option select, w/o callback
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*, float, or double)
      @param 'select_' - reference to GEMSelect option select
      @param 'readonly_' (optional) - set readonly mode for variable that option select is associated with
      values GEM_READONLY (alias for true)
      default false
    */
    GEMItem(const char* const title_, byte& linkedVariable_, GEMSelect& select_, bool readonly_ = false);
    GEMItem(const char* const title_, int& linkedVariable_, GEMSelect& select_, bool readonly_ = false);
    GEMItem(const char* const title_, char* linkedVariable_, GEMSelect& select_, bool readonly_ = false);
    GEMItem(const char* const title_, float& linkedVariable_, GEMSelect& select_, bool readonly_ = false);
    GEMItem(const char* const title_, double& linkedVariable_, GEMSelect& select_, bool readonly_ = false);
    /* 
      Constructors for menu item that represents variable, w/ callback
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*, bool, float, or double)
      @param 'saveAction_' - pointer to callback function executed when associated variable is successfully saved
    */
    GEMItem(const char* const title_, byte& linkedVariable_, void (*saveAction_)());
    GEMItem(const char* const title_, int& linkedVariable_, void (*saveAction_)());
    GEMItem(const char* const title_, char* linkedVariable_, void (*saveAction_)());
    GEMItem(const char* const title_, bool& linkedVariable_, void (*saveAction_)());
    GEMItem(const char* const title_, float& linkedVariable_, void (*saveAction_)());
    GEMItem(const char* const title_, double& linkedVariable_, void (*saveAction_)());
    /* 
      Constructors for menu item that represents variable, w/o callback
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*, bool, float, or double)
      @param 'readonly_' (optional) - set readonly mode for variable that menu item is associated with
      values GEM_READONLY (alias for true)
      default false
    */
    GEMItem(const char* const title_, byte& linkedVariable_, bool readonly_ = false);
    GEMItem(const char* const title_, int& linkedVariable_, bool readonly_ = false);
    GEMItem(const char* const title_, char* linkedVariable_, bool readonly_ = false);
    GEMItem(const char* const title_, bool& linkedVariable_, bool readonly_ = false);
    GEMItem(const char* const title_, float& linkedVariable_, bool readonly_ = false);
    GEMItem(const char* const title_, double& linkedVariable_, bool readonly_ = false);
    /* 
      Constructors for menu item that represents variable, w/o callback and without title (so they can be displayed over the whole width of the screen)
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*, bool, float, or double)
      @param 'readonly_' (optional) - set readonly mode for variable that menu item is associated with
      values GEM_READONLY (alias for true)
      default false
    */
    GEMItem(byte& linkedVariable_, bool readonly_ = false);
    GEMItem(int& linkedVariable_, bool readonly_ = false);
    GEMItem(char* linkedVariable_, bool readonly_ = false);
    GEMItem(bool& linkedVariable_, bool readonly_ = false);
    GEMItem(float& linkedVariable_, bool readonly_ = false);
    GEMItem(double& linkedVariable_, bool readonly_ = false);
    /* 
      Constructors for menu item that represents variable, that are linked to another screen
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedVariable_' - reference to variable that menu item is associated with (either byte, int, char*, bool, float, or double)
      @param 'linkedPage_' - reference to GEMPage menu page that menu item is associated with
      */
    GEMItem(const char* const title_, byte& linkedVariable_, GEMPage* linkedPage_);
    GEMItem(const char* const title_, byte& linkedVariable_, GEMPage& linkedPage_);
    GEMItem(const char* const title_, int& linkedVariable_, GEMPage* linkedPage_);
    GEMItem(const char* const title_, int& linkedVariable_, GEMPage& linkedPage_);
    GEMItem(const char* const title_, char* linkedVariable_, GEMPage* linkedPage_);
    GEMItem(const char* const title_, char* linkedVariable_, GEMPage& linkedPage_);
    GEMItem(const char* const title_, bool& linkedVariable_, GEMPage* linkedPage_);
    GEMItem(const char* const title_, bool& linkedVariable_, GEMPage& linkedPage_);
    GEMItem(const char* const title_, float& linkedVariable_, GEMPage* linkedPage_);
    GEMItem(const char* const title_, float& linkedVariable_, GEMPage& linkedPage_);
    GEMItem(const char* const title_, double& linkedVariable_, GEMPage* linkedPage_);
    GEMItem(const char* const title_, double& linkedVariable_, GEMPage& linkedPage_);
    /* 
      Constructor for menu item that represents link to another menu page (via reference)
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedPage_' - reference to GEMPage menu page that menu item is associated with
      @param 'readonly_' (optional) - set readonly mode for the link (user won't be able to navigate to linked page)
      values GEM_READONLY (alias for true)
    */
    GEMItem(const char* const title_, GEMPage& linkedPage_, bool readonly_ = false);
    /* 
      Constructor for menu item that represents link to another menu page (via pointer)
      @param 'title_' - title of the menu item displayed on the screen
      @param 'linkedPage_' - pointer to GEMPage menu page that menu item is associated with
      @param 'readonly_' (optional) - set readonly mode for the link (user won't be able to navigate to linked page)
      values GEM_READONLY (alias for true)
    */
    GEMItem(const char* const title_, GEMPage* linkedPage_, bool readonly_ = false);
    /* 
      Constructor for menu item that represents button
      @param 'title_' - title of the menu item displayed on the screen
      @param 'buttonAction_' - pointer to function that will be executed when menu item is activated
      @param 'readonly_' (optional) - set readonly mode for the button (user won't be able to call action associated with it)
      values GEM_READONLY (alias for true)
    */
    GEMItem(const char* const title_, void (*buttonAction_)(), bool readonly_ = false);
    /* 
      Constructor for menu item that represents a string as value, that is generated by a function call,
      @param 'title_' - title of the menu item displayed on the screen
      @param 'getValueStr' - pointer to function that will return a char* and is executed when the item is updated
    */
    GEMItem(const char* const title_, const char* const (*getValueStr)(void));
    GEMItem(const char* const (*getValueStr)(void));
    /* 
      Constructor for menu item that represents a single static string as text entry,
      @param 'title_' - title of the menu item displayed on the screen
    */
    GEMItem(const char* const title_);

    
    // /*
    //   Provide any GEMItem constructor with __FlashStringHelper (for F("asd") macro) instead of char* title.
    // */
    // template<typename... Args> GEMItem(const __FlashStringHelper* title_, Args... args);

    void setTitle(const char* const title_);            // Set title of the menu item
    const char* getTitle();                       // Get title of the menu item
    void setPrecision(byte prec);           // Explicitly set precision for float or double variables as required by dtostrf() conversion,
                                            // i.e. the number of digits after the decimal sign
    void setReadonly(bool mode = true);  // Explicitly set or unset readonly mode for variable that menu item is associated with
                                            // (relevant for GEM_VAL_INTEGER, GEM_VAL_BYTE, GEM_VAL_FLOAT, GEM_VAL_DOUBLE, GEM_VAL_CHAR,
                                            // GEM_VAL_BOOL variable menu items and GEM_VAL_SELECT option select), or menu button GEM_ITEM_BUTTON
                                            // and menu link GEM_ITEM_LINK, pressing of which won't result in any action, associated with them
    bool getReadonly();                  // Get readonly state of the variable that menu item is associated with (as well as menu link or button)
    void hide(bool hide = true);         // Explicitly hide or show menu item
    void show();                            // Explicitly show menu item
    bool getHidden();                    // Get hidden state of the menu item
  private:
    const char* title;
    byte type;
    void* linkedVariable;
    byte linkedType;
    byte precision = GEM_FLOAT_PREC;
    bool readonly = false;
    bool hidden = false;
    GEMSelect* select;
    GEMPage* parentPage = nullptr;
    GEMPage* linkedPage;
    GEMItem* menuItemNext;
    GEMItem* getMenuItemNext();             // Get next menu item, excluding hidden ones
    void (*buttonAction)();
    void (*saveAction)();
    const char* const (*getValue)(void) = nullptr;
};
  
#endif
