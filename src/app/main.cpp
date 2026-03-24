#include <wx/wx.h>

#include "mainFrame.hpp"

class Viewer : public wxApp {
  bool OnInit() {
    auto *frame{new MainFrame()};
    frame->Show(true);

    return true;
  }
};

IMPLEMENT_APP(Viewer)
