/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2019 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 2009-2019 KiCad Developers, see AUTHORS.txt for contributors.
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

/**
 * @file dielectric_material.h
 */

#ifndef DIELECTRIC_MATERIAL_H
#define DIELECTRIC_MATERIAL_H


#include <wx/string.h>


// A class to handle substrates prms in gerber job file and dialog
struct DIELECTRIC_SUBSTRATE
{
    wxString m_Name;            // the name (in job file) of material
    double m_EpsilonR;          // the epsilon r of this material
    double m_LossTangent;       // the loss tangent (tanD) of this material
    wxString FormatEpsilonR();  // return a wxString to print/display Epsilon R
    wxString FormatLossTangent();// return a wxString to print/display Loss Tangent
};


// A struct to handle a list of substrates prms in gerber job file and dialogs
class DIELECTRIC_SUBSTRATE_LIST
{
    ///> The list of available substrates. It contians at least predefined substrates
    std::vector<DIELECTRIC_SUBSTRATE> m_substrateList;

public:
    DIELECTRIC_SUBSTRATE_LIST();

    /**
     * @return the number of substrates in list
     */
    int GetCount() { return (int)m_substrateList.size(); }

    /**
     * @return the substrate in list of index aIdx
     *  if incorrect return nullptr
     * @param aIdx is the index in substrate list.
     */
    DIELECTRIC_SUBSTRATE* GetSubstrate( int aIdx );

    /**
     * @return the substrate in list of name aName
     *  if not found return nullptr
     * @param aName is the name of the substrate in substrate list.
     * the comparison is case insensitve
     */
    DIELECTRIC_SUBSTRATE* GetSubstrate( const wxString& aName );

    /** Find a item in list similar to aItem
     * @param aItem is the item to match
     * @return the index of similar item in list or -1 if not found
     * the comparison is for the name case insensitive, and EpsilonR and LossTg must match
     */
    int FindSubstrate( DIELECTRIC_SUBSTRATE* aItem );

    /** Find a item in list having the sapme parameters
     * @param aName is the name to match (case insensitive)
     * @param aEpsilonR is the Repaltive Permeatbility to match
     * @param aLossTg is the loss tangent to match
     * @return the index of similar item in list or -1 if not found
     */
    int FindSubstrate( const wxString& aName, double aEpsilonR, double aLossTg );

    /** Append a item in list similar to aItem
     * @param aItem is the item to append
     * @return the index of the new item in list
     */
    int AppendSubstrate( DIELECTRIC_SUBSTRATE& aItem )
    {
        m_substrateList.emplace_back( aItem );
        return GetCount()-1;
    }
};

#endif      // #ifndef DIELECTRIC_MATERIAL_H
