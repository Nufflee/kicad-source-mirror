/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2019 Kicad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

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

    void SetContentEnabled( bool enabled = true );
};

#endif //KICAD_PANEL_EESCHEMA_ANNOTATION_OPTIONS_H
