#include <wx/wx.h>

#include "mainFrame.hpp"

#include <chrono>
#include <random>

#include "bubbleSort.h"
#include "quickSort.h"
#include "VisualizerCanvas.hpp"
#include "controlsCanvas.hpp"
#include "random.h"
#include "sorter.h"

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Algorithm Visualizer", wxDefaultPosition, wxSize(800, 600)) {
    auto *panel{new wxPanel(this)};
    panel->SetBackgroundColour(wxColour(30, 30, 30));

    Center();

    m_algorithms.emplace_back(std::make_shared<BubbleSort>("Bubble Sort"));
    m_algorithms.emplace_back(std::make_shared<QuickSort>("Quick Sort"));

    std::vector<std::string> algorithms;
    for (const auto &algo: m_algorithms) {
        algorithms.emplace_back(algo->getName());
    }

    if (!m_algorithms.empty()) {
        m_sorter = m_algorithms[0];
    }

    m_data = std::make_shared<std::vector<int> >(100);
    m_controlsCanvas = new ControlsCanvas(panel, algorithms);
    m_visualizerCanvas = new VisualizerCanvas(panel, m_data);

    auto *mainSizer{new wxBoxSizer(wxHORIZONTAL)};

    mainSizer->Add(m_controlsCanvas, 0, wxLEFT | wxTOP | wxBOTTOM | wxEXPAND, 10);
    mainSizer->Add(m_visualizerCanvas, 1, wxALL | wxEXPAND, 10);
    panel->SetSizer(mainSizer);
};

MainFrame::~MainFrame() {
    m_stopRequested = true;

    if (m_sortingThread.joinable()) {
        m_sortingThread.join();
    }
}

auto MainFrame::onButton1Clicked(wxCommandEvent &event) -> void {
    if (m_isSorting) return;
    for (int i = 0; i < m_data->size(); i++) {
        (*m_data)[i] = Random::get(0, 1000);
    }

    updateData();
};

auto MainFrame::onButton2Clicked(wxCommandEvent &event) -> void {
    if (m_isSorting) return;
    m_stopRequested = false;
    m_isSorting = true;

    if (m_sortingThread.joinable()) {
        m_sortingThread.join();
    }
    m_sortingThread = std::thread(&MainFrame::runSortingWorker, this);
};

auto MainFrame::onDropdownSelected(wxCommandEvent &event) -> void {
    if (m_isSorting) return;
    for (const auto &algo: m_algorithms) {
        if (event.GetString().ToStdString() == algo->getName()) {
            m_sorter = algo;
        }
    }
}

auto MainFrame::updateData() -> void {
    m_visualizerCanvas->updateData();
}

auto MainFrame::onUpdateUiControls(wxUpdateUIEvent &event) -> void {
    event.Enable(!m_isSorting);
}

auto MainFrame::onExit(wxCommandEvent &event) -> void {
    Close(true);
};

auto MainFrame::runSortingWorker() -> void {
    if (m_sorter && m_data) {
        auto updateCallback{
            [this] {
                CallAfter([this] {
                    updateData();
                });
            }
        };

        m_sorter->sort(m_data, updateCallback, m_stopRequested, m_delay);
    }
    m_isSorting = false;
}
