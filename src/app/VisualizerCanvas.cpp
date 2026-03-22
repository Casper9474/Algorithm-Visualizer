#include <wx/wx.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include <algorithm>

#include "VisualizerCanvas.hpp"

VisualizerCanvas::VisualizerCanvas(wxWindow *parent, std::shared_ptr<std::vector<int>> data) : wxPanel(parent), m_data(data) {
    wxWindowBase::SetBackgroundStyle(wxBG_STYLE_PAINT);
    wxWindowBase::SetBackgroundColour(*wxBLACK);

    Bind(wxEVT_PAINT, &VisualizerCanvas::onPaint, this);
}

auto VisualizerCanvas::onPaint(wxPaintEvent &event) -> void {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    if (m_data == nullptr || m_data->empty()) return;

    const std::unique_ptr<wxGraphicsContext> gc(wxGraphicsContext::Create(dc));
    if (gc == nullptr) return;
    gc->SetAntialiasMode(wxANTIALIAS_NONE);
    gc->SetBrush(g_graphBrush);
    gc->SetPen(g_graphPen);

    const auto panelSize{GetClientSize()};
    const auto count{m_data->size()};
    const auto barWidth{static_cast<double>(panelSize.GetWidth())/count};

    const auto maxValue{std::ranges::max(*m_data)};
    if (maxValue == 0) return;
    for (auto i{0}; i < count; i++) {
        const auto normalizedHeight{(static_cast<double>((*m_data)[i]) / maxValue) * panelSize.GetHeight()};
        gc->DrawRectangle(
            i * barWidth,
            panelSize.GetHeight() - normalizedHeight,
            barWidth,
            normalizedHeight
        );
    }
}

auto VisualizerCanvas::updateData() -> void {
    Refresh();
};
