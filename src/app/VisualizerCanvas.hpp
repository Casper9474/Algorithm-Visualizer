#pragma once
#include <wx/wx.h>

const auto g_graphPen{*wxTRANSPARENT_PEN};
const auto g_graphBrush{*wxWHITE_BRUSH};


class VisualizerCanvas : public wxPanel {
public:
    explicit VisualizerCanvas(wxWindow *parent, std::shared_ptr<std::vector<int> > data);

    auto updateData() -> void;

    auto setMaxValue(int maxValue) -> void { m_maxValue = maxValue; }

private:
    auto onPaint(wxPaintEvent &event) -> void;

    std::shared_ptr<std::vector<int> > m_data;
    int m_maxValue{0};
};
