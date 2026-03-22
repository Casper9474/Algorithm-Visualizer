#include <wx/wx.h>

#include "mainFrame.hpp"

#include <chrono>
#include <random>

#include "bubbleSort.h"
#include "VisualizerCanvas.hpp"
#include "controlsCanvas.hpp"
#include "random.h"
#include "sorter.h"

auto data{ std::make_shared<std::vector<int>>(499) };

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "wxWidgets Hello World", wxDefaultPosition, wxDefaultSize) {
    this->wxTopLevelWindowMSW::Maximize();
    auto* panel {new wxPanel(this)};
    
    m_controlsCanvas = new ControlsCanvas(panel);
    m_visualizerCanvas = new VisualizerCanvas(panel, data);

    auto* mainSizer {new wxBoxSizer(wxHORIZONTAL)};

    mainSizer->Add(m_controlsCanvas, 0, wxALL | wxEXPAND, 10);
    mainSizer->Add(m_visualizerCanvas, 1, wxALL | wxEXPAND, 10);
    panel->SetSizer(mainSizer);
};


auto MainFrame::onButton1Clicked(wxCommandEvent &event) -> void {

    for (int i = 0; i < data->size(); i++) {
        (*data)[i] = Random::get(0,std::numeric_limits<int>::max());
    }

    updateData();
};

auto sorter {std::make_unique<BubbleSort>()};

auto MainFrame::onButton2Clicked(wxCommandEvent &event) -> void {
    sorter->sort(data, [this]{updateData();});
};

auto MainFrame::onDropdownSelected(wxCommandEvent &event) -> void {
    wxLogMessage("Selected algorithm: %s", event.GetString());
}

auto MainFrame::updateData() -> void {
    m_visualizerCanvas->updateData();
}

auto MainFrame::onExit(wxCommandEvent &event) -> void {
    Close(true);
};
