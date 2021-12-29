﻿// LR(0) Parsers build in 2021.12.09
// file name: utils.cpp
// Edit by @Michael Zhou
#include "pch.h"
#include "utils.h"

void CopyStr(wchar_t** dst, const wchar_t* src)
{
	*dst = new wchar_t[wcslen(src) + 1];
	*(dst)[wcslen(src)] = '\0';
	for (int i = 0; i < static_cast<int>(wcslen(src)); i++)
	{
		*dst[i] = src[i];
	}
}

wchar_t* CopyStr(const wchar_t* src)
{
	auto dst = new wchar_t[wcslen(src) + 1];
	dst[wcslen(src)] = '\0';
	for (int i = 0; i < static_cast<int>(wcslen(src)); i++)
	{
		dst[i] = src[i];
	}
	return dst;
}

SplitStr::SplitStr(wchar_t* src, const wchar_t c): src(src)
{
	std::vector<wchar_t*> dst;
	int l = 0;

	for (int i = 0; i < static_cast<int>(wcslen(src)); i++)
	{
		if (src[i] == c)
		{
			poses.emplace_back(Pos(l, i - 1));
			l = i + 1;
		}
	}
	poses.emplace_back(Pos(l, static_cast<int>(wcslen(src)) - 1));
}

int SplitStr::NSubStrs() const
{
	return poses.size();
}

void SplitStr::SubStr(wchar_t** dst, const int no) const
{
	Pos temp = poses[no];
	int length = temp.right - temp.left + 2;


	*dst = new wchar_t[length];
	wchar_t* ddst = *dst;
	ddst[length - 1] = '\0';
	for (unsigned i = 0; i < wcslen(ddst); i++)
	{
		ddst[i] = src[i + temp.left];
	}
}

wchar_t* SplitStr::SubStr(const int no) const
{
	Pos temp = poses[no];
	int length = temp.right - temp.left + 2;


	auto dst = new wchar_t[length];
	dst[length - 1] = '\0';
	for (unsigned i = 0; i < wcslen(dst); i++)
	{
		dst[i] = src[i + temp.left];
	}
	return dst;
}

CString Int2String(int t)
{
	CString tmp;
	tmp.Format(L"%d", t);
	return tmp;
}

CString Int2String(std::vector<int> t, int upper_ten = 0)
{
	CString tmp;
	for (int t1 : t)
	{
		if (t1 > 9 && upper_ten == 1)
		{
			tmp += L"[";
			tmp += Int2String(t1);
			tmp += L"]";
		}
		else
		{
			tmp += Int2String(t1);
		}
	}
	return tmp;
}

CString Wchar2String(std::vector<wchar_t> t)
{
	CString tmp;
	for (auto t1 : t)
	{
		tmp += CString(t1);
	}
	return tmp;
}
