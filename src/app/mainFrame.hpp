#pragma once

#include <thread>
#include <wx/wx.h>

#include "controlsCanvas.hpp"
#include "sorter.h"
#include "VisualizerCanvas.hpp"

class MainFrame : public wxFrame {
public:
    MainFrame();

    ~MainFrame();

    auto onButton1Clicked(wxCommandEvent &event) -> void;

    auto onButton2Clicked(wxCommandEvent &event) -> void;

    auto onDropdownSelected(wxCommandEvent &event) -> void;

    auto updateData() -> void;

    auto onUpdateUiControls(wxUpdateUIEvent &) -> void;

private:
    auto onExit(wxCommandEvent &event) -> void;

    ControlsCanvas *m_controlsCanvas;
    VisualizerCanvas *m_visualizerCanvas;
    std::thread m_sortingThread;
    std::atomic<bool> m_isSorting{false};
    std::atomic<bool> m_stopRequested{false};
    int m_delay{1};

    auto runSortingWorker() -> void;

    std::shared_ptr<Sorter> m_sorter;
    std::shared_ptr<std::vector<int> > m_data;
    std::vector<std::shared_ptr<Sorter> > m_algorithms;
};
