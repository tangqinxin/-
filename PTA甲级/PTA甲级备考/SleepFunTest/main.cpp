#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<atlstr.h>
#pragma warning(disable:4996)
int main()
{
	CString s = "a.bmp";
	LPTSTR lps = s.GetBuffer(0);
	HANDLE CreateFile(
		LPCTSTR lpFileName,    // ָ���ļ�����ָ�� 
		DWORD dwDesiredAccess,    // ����ģʽ��д / ���� 
		DWORD dwShareMode,    // ����ģʽ 
		LPSECURITY_ATTRIBUTES lpSecurityAttributes, // ָ��ȫ���Ե�ָ�� 
		DWORD dwCreationDisposition,   // ��δ��� 
		DWORD dwFlagsAndAttributes,   // �ļ����� 
		HANDLE hTemplateFile    // ���ڸ����ļ���� 
	);



	return 0;
}