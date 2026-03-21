#include <wx/wx.h>

#include "main.hpp"
#include "mainFrame.hpp"

bool Viewer::OnInit()
{
    auto* frame { new MainFrame() };
    frame->Show(true);

    return true;
}