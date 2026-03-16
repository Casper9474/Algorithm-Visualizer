#pragma once

#include <wx/wx.h>

class mainWindow: public wxFrame
{
public:
    mainWindow();
private:
    void onExit(wxCommandEvent& event);
};