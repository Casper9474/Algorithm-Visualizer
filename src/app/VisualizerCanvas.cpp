#include <wx/wx.h>
#include <wx/graphics.h>

#include "VisualizerCanvas.hpp"

VisualizerCanvas::VisualizerCanvas(wxWindow* parent) : wxPanel(parent) {
    SetMinSize(wxSize(200, 200));
    SetBackgroundColour(*wxYELLOW);
    Bind(wxEVT_PAINT, &VisualizerCanvas::onPaint, this);
};

void VisualizerCanvas::onPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);

    std::unique_ptr<wxGraphicsContext> gc(wxGraphicsContext::Create(dc));

    if (gc) {
        gc->SetPen(*wxRED_PEN);
        gc->SetBrush(*wxTRANSPARENT_BRUSH);

        wxGraphicsPath path {gc->CreatePath()};
        path.AddCircle(100, 100, 50); 
        path.CloseSubpath();

        gc->StrokePath(path);
    }
};