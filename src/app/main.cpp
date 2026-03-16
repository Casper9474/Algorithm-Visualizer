#include <wx/wx.h>

#include "main.hpp"
#include "mainWindow.hpp"

bool Viewer::OnInit()
{
    m_frame = new mainWindow();
    m_frame->Show();

    return true;
}