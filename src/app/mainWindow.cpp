#include <wx/wx.h>

#include "mainWindow.hpp"

mainWindow::mainWindow() : wxFrame(nullptr, wxID_ANY, "Algorithm Visualizer") {

}

void mainWindow::onExit(wxCommandEvent& event) {
    Close(true);
}