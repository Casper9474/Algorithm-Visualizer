#include <wx/wx.h>

#include "mainFrame.hpp"

#include <chrono>
#include <random>

#include "VisualizerCanvas.hpp"
#include "controlsCanvas.hpp"

std::random_device rd;
std::mt19937 gen(static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()));
std::uniform_int_distribution<> distribution(0, std::numeric_limits<int>::max());
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
        (*data)[i] = distribution(gen);
    }

    updateData();
};

auto MainFrame::bubbleSort() -> void {
    auto n {data->size()};
    bool swapped {true};
    while (swapped) {
        swapped = false;
        for (auto i {1}; i < n; i++) {
            if ((*data)[i-1] > (*data)[i]) {
                std::swap((*data)[i-1], (*data)[i]);
                updateData();
                swapped = true;
            }
        }
    }
}

auto MainFrame::onButton2Clicked(wxCommandEvent &event) -> void {
    bubbleSort();
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
