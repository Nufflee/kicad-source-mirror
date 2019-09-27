///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 10 2019)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "panel_eeschema_annotation_options_base.h"

///////////////////////////////////////////////////////////////////////////

PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE::PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bmainSizer;
	bmainSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bupperSizer;
	bupperSizer = new wxBoxSizer( wxVERTICAL );

	m_cbEnabled = new wxCheckBox( this, wxID_ANY, _("Annotate components on placement"), wxDefaultPosition, wxDefaultSize, 0 );
	bupperSizer->Add( m_cbEnabled, 0, wxALL, 5 );

	m_separator = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bupperSizer->Add( m_separator, 0, wxEXPAND | wxALL, 5 );

	m_contentSizer = new wxFlexGridSizer( 1, 2, 0, 0 );
	m_contentSizer->AddGrowableCol( 0 );
	m_contentSizer->AddGrowableCol( 1 );
	m_contentSizer->SetFlexibleDirection( wxBOTH );
	m_contentSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxString m_rbScopeChoices[] = { _("Use the current page only"), _("Use the entire schematic") };
	int m_rbScopeNChoices = sizeof( m_rbScopeChoices ) / sizeof( wxString );
	m_rbScope = new wxRadioBox( this, wxID_ANY, _("Scope:"), wxDefaultPosition, wxDefaultSize, m_rbScopeNChoices, m_rbScopeChoices, 1, wxRA_SPECIFY_COLS );
	m_rbScope->SetSelection( 0 );
	m_contentSizer->Add( m_rbScope, 0, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Numbering:") ), wxVERTICAL );

	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 0, 0 );
	gbSizer1->SetFlexibleDirection( wxBOTH );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_rbFirstFree = new wxRadioButton( sbSizer2->GetStaticBox(), wxID_FIRST_FREE, _("Use first free number after:"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	gbSizer1->Add( m_rbFirstFree, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxTOP, 2 );

	m_textNumberAfter = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	gbSizer1->Add( m_textNumberAfter, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxLEFT, 2 );

	m_rbSheetX100 = new wxRadioButton( sbSizer2->GetStaticBox(), wxID_SHEET_X_100, _("First free after sheet number X 100"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer1->Add( m_rbSheetX100, wxGBPosition( 1, 0 ), wxGBSpan( 1, 2 ), wxBOTTOM|wxTOP, 4 );

	m_rbSheetX1000 = new wxRadioButton( sbSizer2->GetStaticBox(), wxID_SHEET_X_1000, _("First free after sheet number X 1000"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer1->Add( m_rbSheetX1000, wxGBPosition( 2, 0 ), wxGBSpan( 1, 2 ), wxBOTTOM|wxTOP, 2 );


	sbSizer2->Add( gbSizer1, 1, wxEXPAND, 5 );


	m_contentSizer->Add( sbSizer2, 1, wxALL|wxEXPAND, 5 );


	bupperSizer->Add( m_contentSizer, 0, wxBOTTOM|wxEXPAND, 5 );


	bmainSizer->Add( bupperSizer, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 6 );


	this->SetSizer( bmainSizer );
	this->Layout();

	// Connect Events
	m_cbEnabled->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE::OnEnableClick ), NULL, this );
}

PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE::~PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE()
{
	// Disconnect Events
	m_cbEnabled->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PANEL_EESCHEMA_ANNOTATION_OPTIONS_BASE::OnEnableClick ), NULL, this );

}
