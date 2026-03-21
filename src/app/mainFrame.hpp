#pragma once

#include <wx/wx.h>

class MainFrame: public wxFrame
{
public:
    MainFrame();
    static void onButton1Clicked(wxCommandEvent& event);
    static void onButton2Clicked(wxCommandEvent& event);

    static void onDropdownSelected(wxCommandEvent& event);
};