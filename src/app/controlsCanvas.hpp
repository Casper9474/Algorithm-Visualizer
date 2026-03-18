#include <wx/wx.h>

class ControlsCanvas : public wxPanel {
public:
    ControlsCanvas(wxWindow* parent);
private:
    void onButton1Clicked(wxCommandEvent& event);
    void onButton2Clicked(wxCommandEvent& event);
    void onDropdownSelected(wxCommandEvent& event);
};