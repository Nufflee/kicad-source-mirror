#ifndef KICAD_PANEL_EESCHEMA_ANNOTATION_OPTIONS_H
#define KICAD_PANEL_EESCHEMA_ANNOTATION_OPTIONS_H

#include "panel_eeschema_annotation_options_base.h"
#include <sch_edit_frame.h>

class PANEL_EESCHEMA_ANNOTATION_OPTIONS : public PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE
{
private:
    SCH_EDIT_FRAME* m_frame;

public:
    PANEL_EESCHEMA_ANNOTATION_OPTIONS( SCH_EDIT_FRAME* aFrame, wxWindow* aWindow );

    void OnEnableClick( wxCommandEvent& event ) override;

private:
    bool TransferDataFromWindow() override;
    bool TransferDataToWindow() override;

    void SetContentEnabled(bool enabled = true);
};

#endif //KICAD_PANEL_EESCHEMA_ANNOTATION_OPTIONS_H
