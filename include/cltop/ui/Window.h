#pragma once
#include <ncurses.h>

class Window {
  protected:
    WINDOW *win;
    int x, y, w, h;

  public:
    Window(int x, int y, int w, int h);
    virtual ~Window();
    void refresh();
    void drawBorder();
    void erase();
};
