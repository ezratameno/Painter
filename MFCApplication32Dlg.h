
// MFCApplication32Dlg.h : header file
//

#pragma once
#include"Elipsa.h"
#include"Rectangle_my.h"
#include"Figure.h"
#include"Triangle.h"
#include"Squre.h"
#include"star_of_david.h"
#include"Line.h"
#include"Star.h"
#include"Pentagon.h"
#include"Arrow.h"

// CMFCApplication32Dlg dialog
class CMFCApplication32Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication32Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION32_DIALOG };
#endif
	bool is_pressed = false;//לחיצה על העכבר
	CPoint start, end, mouse;//נקודות עזר לקביעת מיקומים של P1,P2, המשתנה מאוס יעזור בפונקצית הגרירה 
	int futureFigure = 0;//איזה צורה לעשות
	COLORREF brush = RGB(255, 255, 255), pen, filling_color = RGB(255, 255, 255);//משתני עזר על מנת להכניס לכל אובייקט
	CTypedPtrArray<CObArray, Figure*> figs;//מערך של מערכים דינאמי
	int mode = 0;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio2();
	int size_pen;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedRadio10();
	afx_msg void OnBnClickedRadio11();
	afx_msg void OnBnClickedRadio12();
	afx_msg void OnBnClickedRadio13();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
