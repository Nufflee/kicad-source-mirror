///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 10 2019)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/radiobox.h>
#include <wx/radiobut.h>
#include <wx/textctrl.h>
#include <wx/gbsizer.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_FIRST_FREE 1000
#define wxID_SHEET_X_100 1001
#define wxID_SHEET_X_1000 1002

///////////////////////////////////////////////////////////////////////////////
/// Class PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE
///////////////////////////////////////////////////////////////////////////////
class PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE : public wxPanel
{
	private:

	protected:
		wxCheckBox* m_cbEnabled;
		wxStaticLine* m_separator;
		wxFlexGridSizer* m_contentSizer;
		wxRadioBox* m_rbScope;
		wxRadioButton* m_rbFirstFree;
		wxTextCtrl* m_textNumberAfter;
		wxRadioButton* m_rbSheetX100;
		wxRadioButton* m_rbSheetX1000;

		// Virtual event handlers, overide them in your derived class
		virtual void OnEnableClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,156 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
		~PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE();
};
