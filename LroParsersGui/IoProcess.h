// LR(0) Parsers build in 2021.12.14
// file name: IoProcess.h
// Edit by @Michael Zhou

#pragma once
#include "header.h"
#include "utils.h"
class IoProcess
{
	CStdioFile file;

	std::vector<wchar_t*> buffer_list;
	std::vector<wchar_t*>::iterator buffer_list_point;
public:
	CString file_path = L"./config/grammar.txt";
	FLAG ReadFromFile();

	FLAG Dump2File(CString content);

	CString GetFilePath();
	void SetFilePath(const wchar_t* path);
	int GetFileLines() const;
	wchar_t* GetLine();
	~IoProcess();
};
