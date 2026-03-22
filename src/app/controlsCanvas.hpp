#pragma once
#include <wx/wx.h>

class ControlsCanvas : public wxPanel {
public:
    explicit ControlsCanvas(wxWindow *parent, const std::vector<std::string> &);

private:
    const std::vector<std::string> &m_algorithms;
};
