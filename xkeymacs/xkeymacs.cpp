// xkeymacs.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "xkeymacs.h"
#include "Profile.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXkeymacsApp

BEGIN_MESSAGE_MAP(CXkeymacsApp, CWinApp)
	//{{AFX_MSG_MAP(CXkeymacsApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXkeymacsApp construction

CXkeymacsApp::CXkeymacsApp()
{
	m_hMutex = NULL;
	m_bIsWow64 = FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CXkeymacsApp object

CXkeymacsApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CXkeymacsApp initialization

BOOL CXkeymacsApp::InitInstance()
{
//	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	m_hMutex = CreateMutex(FALSE, 0, CString(MAKEINTRESOURCE(AFX_IDS_APP_TITLE)));
	if (GetLastError() == ERROR_ALREADY_EXISTS) {
		CloseHandle(m_hMutex);
		m_hMutex = NULL;
		return FALSE;
	}

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	SetRegistryKey(IDS_REGISTRY_KEY);
//
//	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Parse command line for standard shell commands, DDE, file open
//	CCommandLineInfo cmdInfo;
//	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
//	if (!ProcessShellCommand(cmdInfo))
//		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(SW_HIDE);
	m_pMainWnd->UpdateWindow();
	SetClassLongPtr(m_pMainWnd->m_hWnd, GCLP_HICON, (LONG_PTR)LoadIcon(IDR_MAINFRAME));

	// set registry key
	CUtils::InitCUtils();
	if (!Create64bitProcess())
		return FALSE;
	CProfile::InitDllData();

	return TRUE;
}

BOOL CXkeymacsApp::IsWow64()
{
	return m_bIsWow64;
}

BOOL CXkeymacsApp::Create64bitProcess()
{
	typedef BOOL (WINAPI *PFIsWow64Process)(HANDLE, PBOOL);
	PFIsWow64Process func = (PFIsWow64Process)GetProcAddress(GetModuleHandle(_T("kernel32")), _T("IsWow64Process"));
	if (!func)
		return TRUE; // IsWow64Process not exists
	if (!func(GetCurrentProcess(), &m_bIsWow64))
		return FALSE; // error
	if (!m_bIsWow64)
		return TRUE; // do nothing
	
	TCHAR szFileName[MAX_PATH];
	if (!GetModuleFileName(NULL, szFileName, sizeof(szFileName)))
		return FALSE;
	TCHAR szDrive[_MAX_DRIVE], szDir[_MAX_DIR], szFile[_MAX_FNAME], szExt[_MAX_EXT];
	if (_tsplitpath_s(szFileName, szDrive, szDir, szFile, szExt) ||
			_tcscat_s(szFile, _T("64")) ||
			_tmakepath_s(szFileName, szDrive, szDir, szFile, szExt))
		return FALSE;

	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));
	if (!CreateProcess(szFileName, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		return FALSE;
	// close unused handles
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return TRUE;
}

BOOL CXkeymacsApp::SendIPCMessage(DWORD msg)
{
	if (!m_bIsWow64)
		return TRUE;
	DWORD ack, read;
	return CallNamedPipe(IPC_PIPE, &msg, sizeof(msg), &ack, sizeof(DWORD), &read, 10000);
}

int CXkeymacsApp::ExitInstance() 
{
	if (m_hMutex) {
		ReleaseMutex(m_hMutex);
		CloseHandle(m_hMutex);

		m_pMainWnd->DestroyWindow();
		delete m_pMainWnd;
		m_pMainWnd = NULL;
	}

	return CWinApp::ExitInstance();
}
