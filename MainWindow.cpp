#include "MainWindow.h"

wxIMPLEMENT_APP(HexdumpTool);

bool HexdumpTool::OnInit() {
	MainFrame* frame = new MainFrame();
	
	frame->Show(true);
	return true;
}



wxSize MainFrame::SizeAsPercent(int percentX, int percentY) {
	float multiplierX = ((float) percentX / (float) 100);
	float multiplierY = ((float) percentY / (float) 100);
	float x = multiplierX * (float) SIZE_X;
	float y = multiplierY * (float) SIZE_Y;

	return wxSize((int) x, (int) y);
}

wxPoint MainFrame::PositionAsPercent(int percentX, int percentY) {
	float multiplierX = ((float)percentX / (float)100);
	float multiplierY = ((float)percentY / (float)100);
	float x = multiplierX * (float) this->GetSize().GetX();
	float y = multiplierY * (float) this->GetSize().GetY();

	return wxPoint((int)x, (int)y);
}

void MainFrame::MenuSetup() {
	wxMenuBar* mb = new wxMenuBar();

	wxMenu* file_menu = new wxMenu();

	file_menu->Append(ID_MENU_OPEN_FILE, _T("&Open File"));
	file_menu->Append(ID_MENU_QUIT, _T("&Exit"));

	mb->Append(file_menu, _T("&File"));

	SetMenuBar(mb);
}

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "Hexdump Tool", wxPoint(0, 0), wxSize(SIZE_X, SIZE_Y)) {

	this->Bind(wxEVT_BUTTON, &MainFrame::OnSubmitClicked, this, ID_BUTTON);

	this->SetBackgroundColour(wxColor(*wxWHITE));

	this->SetMaxClientSize(wxSize(SIZE_X, SIZE_Y));
	this->SetMinClientSize(wxSize(SIZE_X, SIZE_Y));
	inputTextBox = new wxTextCtrl(this, wxID_ANY, "", PositionAsPercent(5, 10), SizeAsPercent(90, 20), wxTE_MULTILINE | wxVSCROLL);
	inputButton = new wxButton(this, ID_BUTTON, "Convert to Single String", PositionAsPercent(5, 32), SizeAsPercent(90, 5));
	helpTextLabel = new wxStaticText(this, wxID_ANY, "Enter your hex dump into the text box below: ", PositionAsPercent(5, 5), SizeAsPercent(90, 5));
	outputArea = new wxTextCtrl(this, wxID_ANY, "", PositionAsPercent(5, 50), SizeAsPercent(90, 20), wxTE_READONLY | wxTE_MULTILINE | wxVSCROLL);
	helpOutputLabel = new wxStaticText(this, wxID_ANY, "Output area: ", PositionAsPercent(5, 45), SizeAsPercent(90, 5));

	this->MenuSetup();
}

void MainFrame::OnSubmitClicked(wxCommandEvent& event) {
	outputArea->SetValue(Hexdump::HexToSingleString(inputTextBox->GetValue().ToStdString()));
	event.Skip();
}

MainFrame::~MainFrame() {

}