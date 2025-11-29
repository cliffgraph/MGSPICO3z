#include <string.h>
#include "global.h"
#include "MusFiles.h"
#include "ff/ff.h"
#include "ff/diskio.h"
#include "sdfat.h"

MusFiles::MusFiles() 
{
	m_NumFiles = 0;
	return;
}

MusFiles::~MusFiles()
{
	// do nothing
	return;
}

void
MusFiles::listupDirs(FILESPEC *pList, int *pNumItems, const char *pDir)
{
	if( !(pDir[0] == '\\' && pDir[1] == '\0') && *pNumItems < MAX_FILEITEMS) {
		pList[0].no = 0;
		strcpy(pList[0].name, "..");
		++*pNumItems;
	}

	static FATFS g_fs;
    FRESULT ret = f_mount( &g_fs, "", 1 );
    if( ret != FR_OK ) {
        return;
    }
	DIR dirObj;
	FILINFO fno;
	FRESULT fr = f_findfirst(&dirObj, &fno, pDir, "*");
    while (fr == FR_OK && fno.fname[0] && *pNumItems < MAX_FILEITEMS) {
		if( (fno.fattrib & AM_DIR) != 0 ) { // ディレクトリのみ
			auto *pRec = &pList[*pNumItems];
			pRec->no = 0;
			strcpy(pRec->name, fno.fname);
			++*pNumItems;
		}
        fr = f_findnext(&dirObj, &fno); 
    }
	f_closedir(&dirObj);
	return;
};

void
MusFiles::listupFiles(FILESPEC *pList, int *pNumItems, int *pNumFiles, const char *pWild, const char *pDir)
{
	static FATFS g_fs;
    FRESULT ret = f_mount( &g_fs, "", 1 );
    if( ret != FR_OK ) {
        return;
    }
	DIR dirObj;
	FILINFO fno;
	FRESULT fr = f_findfirst(&dirObj, &fno, pDir, pWild);
    while (fr == FR_OK && fno.fname[0] && *pNumItems < MAX_FILEITEMS) {
		if( !((fno.fattrib & AM_DIR)!=0)) {
			auto *pRec = &pList[*pNumItems];
			pRec->no = *pNumFiles + 1; // ファイル番号は1から
			strcpy(pRec->name, fno.fname);
			++*pNumItems;
			++*pNumFiles;
		}
        fr = f_findnext(&dirObj, &fno); 
    }
	f_closedir(&dirObj);
	return;
};

bool
MusFiles::IsExistDir(const char *pDir)
{
	if( pDir[0] == '\0' )
		return false;	// 空文字列の場合は、存在しないとする

	if( pDir[0] == '\\' && pDir[1] == '\0')
		return true;	// ルートディレクトリは存在する

	static FATFS g_fs;
	FRESULT ret = f_mount( &g_fs, "", 1 );
	if( ret != FR_OK ) {
		return false;
	}
	DIR dirObj;
	FRESULT fr = f_opendir(&dirObj, pDir);
	if( fr == FR_OK ) {
		f_closedir(&dirObj);
		return true;
	}
	return false;
}

bool
MusFiles::IsExistFile(const char *pFile)
{
	if( pFile[0] == '\0' )
		return false;	// 空文字列の場合は、存在しないとする

	static FATFS g_fs;
	FRESULT ret = f_mount( &g_fs, "", 1 );
	if( ret != FR_OK ) {
		return false;
	}
	FIL fil;
	FRESULT fr = f_open(&fil, pFile, FA_READ);
	if( fr == FR_OK ) {
		f_close(&fil);
		return true;
	}
	return false;
}

void
MusFiles::DeleteTermPath(char *pPath)
{
	if( pPath[0] == '\\' && pPath[1] == '\0')
		return;
	const int len = strlen(pPath);
	for( int t = len-1; 0 <= t; --t ) {
		if( pPath[t] == '\\' ) {
			pPath[t] = '\0';
			break;
		}
	}
	return;
}

void
MusFiles::ClearList()
{
	m_NumItems = 0;
	m_NumFiles = 0;
	return;
}

void
MusFiles::ReadFileNames(const char *pWild, const char *pCurDir)
{
	m_NumItems = 0;
	m_NumFiles = 0;
	listupDirs(m_Files, &m_NumItems, pCurDir);
	listupFiles(m_Files, &m_NumItems, &m_NumFiles, pWild, pCurDir);
	return;
}

int
MusFiles::GetNumItems() const
{
	return m_NumItems;
}

int
MusFiles::GetNumFiles() const
{
	return m_NumFiles;
}

bool
MusFiles::IsEmpty() const
{
	return (m_NumItems==0)?true:false;
}

int
MusFiles::GetTopFileNo() const
{
	// 空の場合は0を返す
	if( m_NumFiles == 0 )
		return 0;

	for( int t = 0; t < m_NumItems; ++t ) {
		if( m_Files[t].no != 0 ) { // 1が最初のファイル番号
			return t+1;
		}
	}
	return 0;
}

const MusFiles::FILESPEC
*MusFiles::GetItemSpec(const int no) const
{
	return (no <= 0 || m_NumItems < no) ? nullptr : &m_Files[no-1];
}

const char*
MusFiles::GetDirName(const int no) const
{
	if (no <= 0 || m_NumItems < no)
		return nullptr;
	auto *pF = &m_Files[no-1];
	if( pF->no == 0 )
		return pF->name;
	return nullptr;
}
