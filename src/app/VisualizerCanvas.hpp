#pragma once
#include <wx/wx.h>

class GraphCanvas : public wxPanel {
public:
    explicit VisualizerCanvas(wxWindow* parent);
private:
    void onPaint(wxPaintEvent& event);
};