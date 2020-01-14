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
		LPCTSTR lpFileName,    // 指向文件名的指针 
		DWORD dwDesiredAccess,    // 访问模式（写 / 读） 
		DWORD dwShareMode,    // 共享模式 
		LPSECURITY_ATTRIBUTES lpSecurityAttributes, // 指向安全属性的指针 
		DWORD dwCreationDisposition,   // 如何创建 
		DWORD dwFlagsAndAttributes,   // 文件属性 
		HANDLE hTemplateFile    // 用于复制文件句柄 
	);



	return 0;
}