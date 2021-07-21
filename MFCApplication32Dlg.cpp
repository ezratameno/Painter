
// MFCApplication32Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication32.h"
#include "MFCApplication32Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication32Dlg dialog



CMFCApplication32Dlg::CMFCApplication32Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION32_DIALOG, pParent)
	, size_pen(3)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication32Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, size_pen);
}

BEGIN_MESSAGE_MAP(CMFCApplication32Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication32Dlg::OnBnClickedRadio2)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication32Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication32Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCApplication32Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCApplication32Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCApplication32Dlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCApplication32Dlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CMFCApplication32Dlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CMFCApplication32Dlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO9, &CMFCApplication32Dlg::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO10, &CMFCApplication32Dlg::OnBnClickedRadio10)
	ON_BN_CLICKED(IDC_RADIO11, &CMFCApplication32Dlg::OnBnClickedRadio11)
	ON_BN_CLICKED(IDC_RADIO12, &CMFCApplication32Dlg::OnBnClickedRadio12)
	ON_BN_CLICKED(IDC_RADIO13, &CMFCApplication32Dlg::OnBnClickedRadio13)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication32Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication32Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication32Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication32Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication32Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication32Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCApplication32Dlg message handlers

BOOL CMFCApplication32Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication32Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication32Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		for (int i = 0; i < figs.GetSize(); i++)
		{
			figs[i]->draw(&dc);
		}
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication32Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication32Dlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	futureFigure = 2;

}


void CMFCApplication32Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	UpdateData(true);
}


void CMFCApplication32Dlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	futureFigure = 1;
}


void CMFCApplication32Dlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	futureFigure = 3;

}


void CMFCApplication32Dlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	futureFigure = 4;

}


void CMFCApplication32Dlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	futureFigure = 5;

}


void CMFCApplication32Dlg::OnBnClickedRadio6()
{
	// TODO: Add your control notification handler code here
	futureFigure = 6;

}


void CMFCApplication32Dlg::OnBnClickedRadio7()
{
	// TODO: Add your control notification handler code here
	futureFigure = 7;

}


void CMFCApplication32Dlg::OnBnClickedRadio8()
{
	// TODO: Add your control notification handler code here
	futureFigure = 8;

}


void CMFCApplication32Dlg::OnBnClickedRadio9()
{
	// TODO: Add your control notification handler code here
	futureFigure = 9;

}


void CMFCApplication32Dlg::OnBnClickedRadio10()
{
	// TODO: Add your control notification handler code here
	mode = 1;
}


void CMFCApplication32Dlg::OnBnClickedRadio11()
{
	// TODO: Add your control notification handler code here
	mode = 2;

}


void CMFCApplication32Dlg::OnBnClickedRadio12()
{
	// TODO: Add your control notification handler code here
	mode = 3;

}


void CMFCApplication32Dlg::OnBnClickedRadio13()
{
	// TODO: Add your control notification handler code here
	mode = 4;

}


void CMFCApplication32Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	is_pressed = true;
	start = point;
	mouse = point;
	if (mode == 1 && futureFigure)//ציור
	{
		switch (futureFigure)
		{
		case 1: figs.Add(new Rectangle_my(start, start));
			break;
		case 2: figs.Add(new Elipsa(start, start));
			break;
		case 3:
			figs.Add(new Triangle(start, start));
			break;
		case 4:
			figs.Add(new Squre(start, start));
			break;
		case 5:
			figs.Add(new star_of_david(start, start));
			break;
		case 6:
			figs.Add(new Line(start, start));
			break;
		case 7:
			figs.Add(new Arrow(start, start));
			break;
		case 8:
			figs.Add(new Pentagon(start, start));
			break;
		case 9:
			figs.Add(new Star(start, start));
			break;
		}
		//בעת יצירת אובייקט צבע המברשת וצבע העט הנוכחי יקבעו
		figs[figs.GetSize() - 1]->change_brush_color(brush);
		figs[figs.GetSize() - 1]->change_pen_color_and_size(pen, size_pen);
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCApplication32Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (is_pressed&& mode == 1 && futureFigure)//מצב ציור +לחיצת עכבר יוצר צורה
	{
		end = point;
		figs[figs.GetSize() - 1]->redefine(start, end);
		Invalidate();
	}
	if (mode == 2)//מצב צביעה, גם בלי לחיצה יתן לנו סמן של יד כאשר נעמוד על צורה
	{
		end = point;
		for (int i = figs.GetSize() - 1; i >= 0; i--)
		{
			if (figs[i]->isInside(end))
			{
				SetCursor(LoadCursor(NULL, IDC_HAND));
				break;
			}
		}
	}
	if (mode == 3)//מצב מחיקה, גם בלי לחיצה כאשר נעמוד על צורה יתן לנו סמן
	{
		end = point;
		for (int i = figs.GetSize() - 1; i >= 0; i--)
		{
			if (figs[i]->isInside(end))
			{
				SetCursor(LoadCursor(NULL, IDC_NO));
				break;
			}
		}
	}
	if (mode == 4)//מצב גרירה, גם בלי לחיצה כאשר נעמוד על צורה יתן לנו סמן
	{
		end = point;
		for (int i = figs.GetSize() - 1; i >= 0; i--)
		{
			if (figs[i]->isInside(end))
			{
				SetCursor(LoadCursor(NULL, IDC_SIZEALL));
				break;
			}
		}
	}
	if (is_pressed&& mode == 4)//הוזזה
	{
		end = point;
		for (int i = figs.GetSize() - 1; i >= 0; i--)
		{
			if (figs[i]->isInside(end))
			{
				int x = end.x - mouse.x;//חדש פחות ישן
				int y = end.y - mouse.y;
				figs[i]->Shift(x, y);
				mouse = point;
				SetCursor(LoadCursor(NULL, IDC_SIZEALL));
				Invalidate();
				break;
			}
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCApplication32Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (is_pressed&& mode == 1 && futureFigure)//ציור
	{
		end = point;
		figs[figs.GetSize() - 1]->redefine(start, end);
		Invalidate();
	}
	if (mode == 2 && is_pressed)//מילוי צורה
	{
		for (int i = figs.GetSize() - 1; i >= 0; i--)
		{
			if (figs[i]->isInside(start))
			{
				figs[i]->change_brush_color(filling_color);
				Invalidate();
				is_pressed = false;
				break;
			}
		}
	}
	if (mode == 2)//, סמן אחר צביעה
	{
		end = point;
		for (int i = figs.GetSize() - 1; i >= 0; i--)
		{
			if (figs[i]->isInside(end))
			{
				SetCursor(LoadCursor(NULL, IDC_HAND));

			}
		}
	}
	if (mode == 3)//אם אני מעל צורה במצב מחיקה החלף סמן
	{
		end = point;
		for (int i = figs.GetSize() - 1; i >= 0; i--)
		{
			if (figs[i]->isInside(end))
			{
				SetCursor(LoadCursor(NULL, IDC_NO));
				break;
			}
		}
	}
	if (mode == 3 && is_pressed)//מחיקה
	{
		for (int i = figs.GetSize() - 1; i >= 0; i--)
		{
			if (figs[i]->isInside(start))
			{
				figs.RemoveAt(i);
				Invalidate();
				is_pressed = false;
				break;
			}
		}
	}
	if (is_pressed&& mode == 4)//הוזזה
	{
		end = point;
		for (int i = figs.GetSize() - 1; i >= 0; i--)
		{
			if (figs[i]->isInside(end))
			{
				int x = end.x - mouse.x;
				int y = end.y - mouse.y;
				figs[i]->Shift(x, y);
				mouse = point;
				Invalidate();
				SetCursor(LoadCursor(NULL, IDC_SIZEALL));
				is_pressed = false;
				break;
			}
		}
	}

	is_pressed = false;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCApplication32Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CColorDialog cd;
	CPaintDC dc(this);
	if (cd.DoModal() == IDOK)
	{
		filling_color = cd.GetColor();
	}
}


void CMFCApplication32Dlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}


void CMFCApplication32Dlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		MessageBox(_T("The file has been saved!"), _T("Success"));
	}
}


void CMFCApplication32Dlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	int a = MessageBox(_T("Are you sure you want to restart the applicaion?\nAll data will be permanently deleted"), _T("WARNING"), MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
	if (!figs.IsEmpty() && a == IDYES)
	{
		figs.RemoveAll();
		Invalidate();
	}
}


void CMFCApplication32Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CColorDialog cd;
	CPaintDC dc(this);
	figs.Add(new Figure);
	if (cd.DoModal() == IDOK)//פתיחת חלון הצבעים ובדיקה האם לחצו אישור או לא
	{
		brush = cd.GetColor();
	}
}


void CMFCApplication32Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CColorDialog cd;
	CPaintDC dc(this);
	figs.Add(new Figure);
	if (cd.DoModal() == IDOK)
	{
		pen = cd.GetColor();
	}
}
