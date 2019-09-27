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

#include <panel_eeschema_annotation_options.h>
#include <sch_component.h>

PANEL_EESCHEMA_ANNOTATION_OPTIONS::PANEL_EESCHEMA_ANNOTATION_OPTIONS( SCH_EDIT_FRAME* aFrame, wxWindow* aWindow )
    : PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE( aWindow ),
      m_frame( aFrame )
{
}

bool PANEL_EESCHEMA_ANNOTATION_OPTIONS::TransferDataToWindow()
{
    bool enabled = m_frame->IsAutoAnnotationEnabled();

    m_cbEnabled->SetValue( enabled );

    SetContentEnabled(enabled);

    m_rbScope->SetSelection( SCH_COMPONENT::GetAutoAnnotationScopeOption() );
    
    switch ( SCH_COMPONENT::GetAutoAnnotationAlgoOption() )
    {
        case INCREMENTAL_BY_REF:  m_rbFirstFree->SetValue( true );  break;
        case SHEET_NUMBER_X_100:  m_rbSheetX100->SetValue( true );  break;
        case SHEET_NUMBER_X_1000: m_rbSheetX1000->SetValue( true ); break;
    }

    m_textNumberAfter->SetValue( wxString::Format( "%d", m_frame->GetAutoAnnotationFirstFreeNumOption() ) );

    return true;
}

bool PANEL_EESCHEMA_ANNOTATION_OPTIONS::TransferDataFromWindow()
{
    m_frame->SetIsAutoAnnotationEnabled( m_cbEnabled->GetValue() );

    m_frame->SetAutoAnnotationScopeOption( m_rbScope->GetSelection() );

    if ( m_rbFirstFree->GetValue() )
    {
        SCH_COMPONENT::SetAutoAnnotationAlgoOption( 0 );
    }
    else if ( m_rbSheetX100->GetValue() )
    {
        SCH_COMPONENT::SetAutoAnnotationAlgoOption( 1 );
    }
    else if ( m_rbSheetX1000->GetValue() )
    {
        SCH_COMPONENT::SetAutoAnnotationAlgoOption( 2 );
    }

    long numberAfter;

    if ( m_textNumberAfter->GetValue().ToLong( &numberAfter ) )
    {
        m_frame->SetAutoAnnotationFirstFreeNumOption( numberAfter );
    }

    m_frame->SaveProjectSettings( false );

    return true;
}

void PANEL_EESCHEMA_ANNOTATION_OPTIONS::OnEnableClick( wxCommandEvent& event )
{
    SetContentEnabled( m_cbEnabled->IsChecked() );
}

void PANEL_EESCHEMA_ANNOTATION_OPTIONS::SetContentEnabled(bool enabled)
{
    m_rbScope->Enable( enabled );
    m_rbFirstFree->Enable( enabled );
    m_rbSheetX100->Enable( enabled );
    m_rbSheetX1000->Enable( enabled );
    m_textNumberAfter->Enable( enabled );
}
