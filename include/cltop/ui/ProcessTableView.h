#include <cltop/ui/Window.h>

enum class SortBy {
    CPU,
    memory,
    name,
};

class ProcessTableView : public Window {
  public:
    ProcessTableView(int x, int y, int w, int h);
    void render();
    void setSortBy(SortBy sb);

  private:
    SortBy sortBy;
};
