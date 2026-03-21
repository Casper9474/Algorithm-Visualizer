#pragma once

#include <wx/wx.h>

class MainFrame: public wxFrame
{
public:
    MainFrame();
    void onButton1Clicked(wxCommandEvent& event);
    void onButton2Clicked(wxCommandEvent& event);

    void onDropdownSelected(wxCommandEvent& event);
};