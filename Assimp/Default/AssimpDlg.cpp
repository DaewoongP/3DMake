
// AssimpDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Assimp.h"
#include "AssimpDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAssimpDlg 대화 상자



CAssimpDlg::CAssimpDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ASSIMP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAssimpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mListBox);
}

BEGIN_MESSAGE_MAP(CAssimpDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &CAssimpDlg::OnLbnSelchangeList1)
	ON_WM_DROPFILES()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CAssimpDlg 메시지 처리기

BOOL CAssimpDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	DragAcceptFiles();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CAssimpDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CAssimpDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CAssimpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CAssimpDlg::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

// 매개변수:
// 폴더 또는 파일이 드랍되면 hDropInfo 구조체를 통해 정보가 전달된다.
void CAssimpDlg::OnDropFiles(HDROP hDropInfo)
{
	UpdateData(TRUE);
	CDialogEx::OnDropFiles(hDropInfo);

	_tchar	filePath[MAX_PATH] = TEXT("");
	_int fileCnt = DragQueryFile(hDropInfo, 0xffffffff, nullptr, 0);

	for (_int i = 0; i < fileCnt; ++i)
	{
		DragQueryFile(hDropInfo, i, filePath, MAX_PATH);
		FindFiles(filePath, { TEXT(".fbx"), TEXT(".FBX") });
	}
	
	if (true == mFiles.empty())
		return;
#include "AIModel.h"
	for (auto& filePath : mFiles)
	{
		_char strFilePath[MAX_PATH] = "";
		WCharToChar(filePath.c_str(), strFilePath);
		ASSIMP::AIModel::Create(ASSIMP::AIModel::ModelType::ANIM, strFilePath, XMMatrixIdentity());
	}
	
	UpdateData(FALSE);
}

void CAssimpDlg::FindFiles(std::wstring _path, std::initializer_list<std::wstring> _exts)
{
	CFileFind	fileFind;
	_path += TEXT("\\*.*");
	_bool	finish = fileFind.FindFile(_path.c_str());

	while (finish)
	{
		finish = fileFind.FindNextFile();

		if (fileFind.IsDots())
			continue;

		else if (fileFind.IsDirectory())
		{
			FindFiles(std::wstring(fileFind.GetFilePath()), _exts);
		}
		else
		{
			if (fileFind.IsSystem())
				continue;

			_tchar	ext[MAX_PATH] = TEXT("");
			_wsplitpath_s(fileFind.GetFilePath().GetString(), nullptr, 0, nullptr, 0, nullptr, 0, ext, 256);

			for (auto& findExt : _exts)
			{
				if (lstrcmp(ext, findExt.c_str()))
					continue;

				mFiles.emplace_back(fileFind.GetFilePath().GetString());
				break;
			}
		}
	}
}

void CAssimpDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	
	mFiles.clear();
}
