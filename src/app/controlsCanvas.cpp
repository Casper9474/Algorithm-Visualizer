#include <wx/wx.h>

#include "controlsCanvas.hpp"

ControlsCanvas::ControlsCanvas(wxWindow* parent) : wxPanel(parent) {
    SetMinSize(wxSize(200, 200));
    SetBackgroundColour(*wxCYAN);
    auto* sizer{new wxBoxSizer(wxVERTICAL)};


    auto* button1{new wxButton(this, wxID_ANY, "Button 1")};
    auto* button2{new wxButton(this, wxID_ANY, "Button 2")};

    std::vector<std::string> algorithms {"Algorithm 1", "Algorithm 2", "Algorithm 3"};
    auto* dropdown{new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, algorithms)};

    sizer->AddStretchSpacer(1);
    sizer->Add(button1, 0, wxALL | wxEXPAND, 10);
    sizer->Add(button2, 0, wxALL | wxEXPAND, 10);
    sizer->Add(dropdown, 0, wxALL | wxEXPAND, 10);
    sizer->AddStretchSpacer(1);
    SetSizer(sizer);


    button1->Bind(wxEVT_BUTTON, &ControlsCanvas::onButton1Clicked, this);
    button2->Bind(wxEVT_BUTTON, &ControlsCanvas::onButton2Clicked, this);

    dropdown->Bind(wxEVT_CHOICE, &ControlsCanvas::onDropdownSelected, this);
};

void ControlsCanvas::onButton1Clicked(wxCommandEvent& event) {
    wxLogMessage("Button 1 was clicked!");
};

void ControlsCanvas::onButton2Clicked(wxCommandEvent& event) {
    wxLogMessage("Button 2 was clicked!");
};

void ControlsCanvas::onDropdownSelected(wxCommandEvent& event) {
    wxLogMessage("Selected algorithm: %s", event.GetString());
};