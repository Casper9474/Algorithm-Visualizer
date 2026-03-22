#pragma once

#include <wx/wx.h>

#include "controlsCanvas.hpp"
#include "VisualizerCanvas.hpp"

class MainFrame: public wxFrame
{
public:
    MainFrame();
    auto onButton1Clicked(wxCommandEvent &event) -> void;

    auto onButton2Clicked(wxCommandEvent &event) -> void;
    auto onDropdownSelected(wxCommandEvent &event) -> void;
    auto updateData() -> void;

private:
    auto onExit(wxCommandEvent &event) -> void;
    ControlsCanvas* m_controlsCanvas;
    VisualizerCanvas* m_visualizerCanvas;
};
