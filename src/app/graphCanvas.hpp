#pragma once
#include <wx/wx.h>

class GraphCanvas : public wxPanel {
public:
    GraphCanvas(wxWindow* parent);
private:
    void onPaint(wxPaintEvent& event);
};