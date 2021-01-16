#pragma once



// CMotionThread

class CMotionThread : public CWinThread
{
	DECLARE_DYNCREATE(CMotionThread)

protected:
	CMotionThread();           // protected constructor used by dynamic creation
	virtual ~CMotionThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	static UINT RunThreadFunction(LPVOID param);

protected:
	DECLARE_MESSAGE_MAP()
};