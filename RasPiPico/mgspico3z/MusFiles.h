#pragma once

#include "MgspicoSettings.h"

// ファイル名の文字長
static const int LEN_FILE_SPEC = 8;
static const int LEN_FILE_EXT = 3;
static const int LEN_FILE_NAME = LEN_FILE_SPEC+1+LEN_FILE_EXT;
static const int LEN_FILE_PATH_MAX = 255;

class MusFiles
{
public:
	struct FILESPEC{
		uint16_t no;					// ファイル番号(0=directory, 1=1st file, ...)
		char name[LEN_FILE_NAME+1];		// ファイル名（拡張子込み）
	};

private:
	static const int MAX_FILEITEMS = 1000;
	int m_NumItems;
	int m_NumFiles;
	FILESPEC m_Files[MAX_FILEITEMS];

public:
	MusFiles();
	virtual ~MusFiles();

private:
	void listupDirs(FILESPEC *pList, int *pNumItems, const char *pDir = "\\");
	void listupFiles(FILESPEC *pList, int *pNumItems, int *pNumFiles, const char *pWild, const char *pDir);
public:
	static void DeleteTermPath(char *pPath);
	static bool IsExistDir(const char *pDir);
	static bool IsExistFile(const char *pFile);

public:
	void ClearList();
	void ReadFileNames(const char *pWild, const char *pCurDir);
	int GetNumItems() const;
	int GetNumFiles() const;
	bool IsEmpty() const;
	int GetTopFileNo() const;
	const FILESPEC *GetItemSpec(const int no) const;
	const char* GetDirName(const int no) const;
};
