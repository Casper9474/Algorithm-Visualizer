#include <wx/wx.h>

#include "controlsCanvas.hpp"
#include "mainFrame.hpp"

ControlsCanvas::ControlsCanvas(wxWindow* parent) : wxPanel(parent) {
    wxWindowBase::SetMinSize(wxSize(200, 200));
    wxWindowBase::SetBackgroundColour(*wxCYAN);
    auto* sizer{new wxBoxSizer(wxVERTICAL)};


    auto* button1{new wxButton(this, wxID_ANY, "Run")};
    auto* button2{new wxButton(this, wxID_ANY, "Reset")};

    const std::vector<std::string> algorithms {"Algorithm 1", "Algorithm 2", "Algorithm 3"};
    auto* dropdown{new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, algorithms)};

    sizer->AddStretchSpacer(1);
    sizer->Add(button1, 0, wxALL | wxEXPAND, 10);
    sizer->Add(button2, 0, wxALL | wxEXPAND, 10);
    sizer->Add(dropdown, 0, wxALL | wxEXPAND, 10);
    sizer->AddStretchSpacer(1);
    SetSizer(sizer);

    auto* frame {static_cast<MainFrame*>(GetParent()->GetParent())};
    button1->Bind(wxEVT_BUTTON, &MainFrame::onButton1Clicked, frame);
    button2->Bind(wxEVT_BUTTON, &MainFrame::onButton2Clicked, frame);

    dropdown->Bind(wxEVT_CHOICE, &MainFrame::onDropdownSelected, frame);
};