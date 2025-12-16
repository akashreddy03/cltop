#include <cltop/ui/Window.h>
#include <ncurses.h>

class Footer : public Window {
  public:
    Footer(int x, int y, int w, int h);
    void render();
};
