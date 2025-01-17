/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2019 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 2009-2019 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file dialog_dielectric_manager.h
 */

#include "dialog_dielectric_list_manager.h"


DIALOG_DIELECTRIC_MATERIAL::DIALOG_DIELECTRIC_MATERIAL( wxWindow* aParent,
                                                        DIELECTRIC_SUBSTRATE_LIST& aMaterialList )
        :DIALOG_DIELECTRIC_MATERIAL_BASE( aParent ),
        m_materialList( aMaterialList )
{
    initMaterialList();
}

DIALOG_DIELECTRIC_MATERIAL::~DIALOG_DIELECTRIC_MATERIAL()
{
}


bool DIALOG_DIELECTRIC_MATERIAL::TransferDataFromWindow()
{
    // Validate double values from wxTextCtrl
    double dummy;

    if( !m_tcEpsilonR->GetValue().ToDouble( &dummy ) || dummy < 0.0 )
    {
        wxMessageBox( _( " Incorrect value for Epsilon R" ) );
        return false;
    }

    if( !m_tcLossTg->GetValue().ToDouble( &dummy ) || dummy < 0.0 )
    {
        wxMessageBox( _( " Incorrect value for Loss Tangent" ) );
        return false;
    }

    return true;
}


bool DIALOG_DIELECTRIC_MATERIAL::TransferDataToWindow()
{
    // Init m_tcEpsilonR and m_tcLossTg to a dummy (default) value
    DIELECTRIC_SUBSTRATE dummy;
    dummy.m_EpsilonR = 1.0;
    dummy.m_LossTangent = 0.0;

    m_tcEpsilonR->SetValue( dummy.FormatEpsilonR() );
    m_tcLossTg->SetValue( dummy.FormatLossTangent() );

    return true;
}


DIELECTRIC_SUBSTRATE DIALOG_DIELECTRIC_MATERIAL::GetSelectedSubstrate()
{
    DIELECTRIC_SUBSTRATE substrate;

    // return the selected/created substrate. A empty substrate can be returned
    double dummy;
    substrate.m_Name = m_tcMaterial->GetValue();
    m_tcEpsilonR->GetValue().ToDouble( &dummy );
    substrate.m_EpsilonR = dummy;
    m_tcLossTg->GetValue().ToDouble( &dummy );
    substrate.m_LossTangent = dummy;

    return substrate;
}


void DIALOG_DIELECTRIC_MATERIAL::initMaterialList()
{
    m_lcMaterials->AppendColumn( _( "Material" ) );
    m_lcMaterials->AppendColumn( _( "Epsilon R" ) );
    m_lcMaterials->AppendColumn( _( "Loss Tg" ) );

    // Fills m_lcMaterials with available materials
    for( int idx = 0; idx < m_materialList.GetCount(); ++idx )
    {
        DIELECTRIC_SUBSTRATE* item = m_materialList.GetSubstrate( idx );

        if( item->m_Name == USER_DEFINED )
            break;

        long tmp = m_lcMaterials->InsertItem( idx, item->m_Name );

        m_lcMaterials->SetItemData(tmp, idx);
        m_lcMaterials->SetItem(tmp, 1, item->FormatEpsilonR() );
        m_lcMaterials->SetItem(tmp, 2, item->FormatLossTangent() );
    }
}


void DIALOG_DIELECTRIC_MATERIAL::onListItemSelected( wxListEvent& event )
{
    int idx = event.GetIndex();

    if( idx < 0 )
        return;

    m_tcMaterial->SetValue( m_materialList.GetSubstrate( idx )->m_Name );
    m_tcEpsilonR->SetValue( m_materialList.GetSubstrate( idx )->FormatEpsilonR() );
    m_tcLossTg->SetValue( m_materialList.GetSubstrate( idx )->FormatLossTangent() );
}
