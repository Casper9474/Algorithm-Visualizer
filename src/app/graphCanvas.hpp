#pragma once
#include <wx/wx.h>

class GraphCanvas : public wxPanel {
public:
    explicit GraphCanvas(wxWindow* parent);
private:
    void onPaint(wxPaintEvent& event);
};