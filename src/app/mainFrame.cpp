#include <wx/wx.h>

#include "mainFrame.hpp"
#include "graphCanvas.hpp"
#include "controlsCanvas.hpp"

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "wxWidgets Hello World", wxDefaultPosition, wxDefaultSize) {
    this->Maximize();
    auto* panel {new wxPanel(this)};
    
    auto* controlsCanvas {new ControlsCanvas(panel)};
    auto* graphCanvas {new GraphCanvas(panel)};

    auto* mainSizer {new wxBoxSizer(wxHORIZONTAL)};

    mainSizer->Add(controlsCanvas, 0, wxALL | wxEXPAND, 10);
    mainSizer->Add(graphCanvas, 1, wxALL | wxEXPAND, 10);
    panel->SetSizer(mainSizer);
};

void MainFrame::onButtonClicked(wxCommandEvent& event) {
    wxLogMessage("Button was clicked!");
};