#include <wx/wx.h>

#include "controlsCanvas.hpp"
#include "mainFrame.hpp"

ControlsCanvas::ControlsCanvas(wxWindow *parent, const std::vector<std::string> &algorithms) : wxPanel(parent),
    m_algorithms(algorithms) {
    wxWindowBase::SetMinSize(wxSize(200, 200));
    wxWindowBase::SetBackgroundColour(wxColour(45, 45, 45));
    auto *sizer{new wxBoxSizer(wxVERTICAL)};


    auto *button1{new wxButton(this, wxID_ANY, "Generate")};
    auto *button2{new wxButton(this, wxID_ANY, "Run")};

    auto *dropdown{new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_algorithms)};
    dropdown->SetSelection(0);

    sizer->AddStretchSpacer(1);
    sizer->Add(button1, 0, wxALL | wxEXPAND, 10);
    sizer->Add(button2, 0, wxALL | wxEXPAND, 10);
    sizer->Add(dropdown, 0, wxALL | wxEXPAND, 10);
    sizer->AddStretchSpacer(1);
    SetSizer(sizer);

    auto *frame{static_cast<MainFrame *>(GetParent()->GetParent())};

    button1->Bind(wxEVT_BUTTON, &MainFrame::onButton1Clicked, frame);
    button1->Bind(wxEVT_UPDATE_UI, &MainFrame::onUpdateUiControls, frame);
    button2->Bind(wxEVT_BUTTON, &MainFrame::onButton2Clicked, frame);
    button2->Bind(wxEVT_UPDATE_UI, &MainFrame::onUpdateUiControls, frame);

    dropdown->Bind(wxEVT_CHOICE, &MainFrame::onDropdownSelected, frame);
    dropdown->Bind(wxEVT_UPDATE_UI, &MainFrame::onUpdateUiControls, frame);
};
