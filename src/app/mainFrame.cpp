#include <wx/wx.h>

#include "mainFrame.hpp"
#include "VisualizerCanvas.hpp"
#include "controlsCanvas.hpp"

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "wxWidgets Hello World", wxDefaultPosition, wxDefaultSize) {
    this->wxTopLevelWindowMSW::Maximize();
    auto* panel {new wxPanel(this)};
    
    auto* controlsCanvas {new ControlsCanvas(panel)};
    auto* graphCanvas {new VisualizerCanvas(panel)};

    auto* mainSizer {new wxBoxSizer(wxHORIZONTAL)};

    mainSizer->Add(controlsCanvas, 0, wxALL | wxEXPAND, 10);
    mainSizer->Add(graphCanvas, 1, wxALL | wxEXPAND, 10);
    panel->SetSizer(mainSizer);
};

void MainFrame::onButton1Clicked(wxCommandEvent& event) {
    wxLogMessage("Button 1 was clicked!");
};

void MainFrame::onButton2Clicked(wxCommandEvent& event) {
    wxLogMessage("Button 2 was clicked!");
};

void MainFrame::onDropdownSelected(wxCommandEvent& event) {
    wxLogMessage("Selected algorithm: %s", event.GetString());
};