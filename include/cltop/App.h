#include <cltop/data/SystemMonitor.h>
#include <cltop/ui/Layout.h>
#include <memory>

class App {
  public:
    App();
    ~App();

    void run();

  private:
    SystemMonitor monitor;
    std::unique_ptr<Layout> layout;
    void initCurses();
    void shutdownCurses();
};
