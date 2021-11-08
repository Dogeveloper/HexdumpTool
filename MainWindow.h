#pragma once

#include "wx/wx.h"
#include "Hexdump.h"

#define SIZE_X 400
#define SIZE_Y 500

class HexdumpTool : public wxApp {
public:

	virtual bool OnInit();
};

class MainFrame : public wxFrame {
public:
	MainFrame();
	~MainFrame();

	void OnSubmitClicked(wxCommandEvent &event);
private:

	void MenuSetup();

	wxSize SizeAsPercent(int percentX, int percentY);

	wxPoint PositionAsPercent(int percentX, int percentY);

	wxStaticText* helpTextLabel = nullptr;
	wxStaticText* helpOutputLabel = nullptr;
	wxTextCtrl* inputTextBox = nullptr;
	wxTextCtrl* outputArea = nullptr;
	wxButton* inputButton = nullptr;

	enum {
		ID_BUTTON = 101,
		ID_MENU_OPEN_FILE = 102,
		ID_MENU_QUIT = 103
	};
};