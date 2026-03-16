#pragma once

#include <wx/wx.h>

class Viewer: public wxApp
{
    bool OnInit();
    
    wxFrame *m_frame;
};


IMPLEMENT_APP(Viewer)