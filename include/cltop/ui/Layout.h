#include <cltop/data/SystemStats.h>
#include <cltop/ui/Footer.h>
#include <cltop/ui/ProcessTableView.h>
#include <cltop/ui/StatsView.h>

class Layout {
  public:
    Layout(int sv_h, int footer_h);
    ~Layout();
    void render(SystemStats SystemStats);
    void refresh();
    void erase();

  private:
    ProcessTableView ptv;
    StatsView sv;
    Footer footer;
};
