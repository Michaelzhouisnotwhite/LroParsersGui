#include "pch.h"
#include "IoProcess.h"

FLAG IoProcess::ReadFromFile()
{
	int res = file.Open(file_path, std::ios::in);
	wchar_t buffer[1024];
	if (!res)
	{
		return ERROR;
	}
	// while (infile.getline(buffer, sizeof(buffer)))
	// {
	// 	auto tmp = CopyStr(buffer);
	// 	buffer_list.push_back(tmp);
	// }
	return NORMAL;
}

int IoProcess::Dump2File(CString content)
{
	int res = file.Open(file_path, CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone);
	if (!res)
	{
		return ERROR;
	}

	file.WriteString(content);
	file.Close();

	return NORMAL;
}

CString IoProcess::GetFilePath()
{
	return file_path;
}

void IoProcess::SetFilePath(const wchar_t* path)
{
	file_path = CString(path);
}

int IoProcess::GetFileLines() const
{
	return buffer_list.size();
}

wchar_t* IoProcess::GetLine()
{
	return *buffer_list_point++;
}

IoProcess::~IoProcess()
{
	for (auto value : buffer_list)
	{
		delete[] value;
	}
}
