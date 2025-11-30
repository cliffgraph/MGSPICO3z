#pragma once
#include <stdint.h>
#include "ff/ff.h"
#include "mgspico.h"

class MgspicoSettings
{
public:
	struct ITEM
	{
		const char *pName;
		const int num;
		const char *pChoices[6];
	};
	const static int NUM_MENUITEMS;

private:
#pragma pack(push,1)
	// この構造体はそのままファイル保存されるので一度決めた位置・サイズは変更しない。
	struct SETTINGDATA {
		MUSICTYPE	MusicType;
		RPxxxxCLOCK	RpCpuClock;
		uint8_t		AutoRun;			// != 0 : 自動的に演奏を開始する
		uint8_t		RandomPlay;			// != 0 : ランダムの曲順で再生する
		uint8_t		EnforceOPLL;		// != 0 : OPLLの存在模倣する
		SCCMODULE	SccModule;
		HARZ80CLOCK	Harz80Clock;
		uint8_t		LoopCnt;			// ループ回数（0:無限ループ、1、2，3:その回数だけループする）	
		uint8_t		Padding[120];		// (構造体サイズを128byteに保つこと)
	};
#pragma pack(pop)

private:
	FATFS m_fs;
	SETTINGDATA m_Setting;

public:
	MgspicoSettings();
	virtual ~MgspicoSettings();
private:
	void setDefault(SETTINGDATA *p);

public:
	int	GetNumItems() const;
	const ITEM *GetItem(const int index ) const;
	void SetChioce(const int indexItem, const int no);
	int GetChioce(const int indexItem) const;

	bool ReadSettingFrom(const char *pFilePath);
	bool WriteSettingTo(const char *pFilePath);
public:
	MUSICTYPE GetMusicType() const;
	void SetMusicType(const MUSICTYPE type);

	bool Is240MHz() const;
	RPxxxxCLOCK GetRp2040Clock() const;
	void SetRp2040Clock(const RPxxxxCLOCK clk);

	bool GetAutoRun() const;
	void SetAutoRun(const bool bAuto);

	bool GetRandomPlay() const;
	void SetRandomPlay(const bool bRnd);

	bool GetEnforceOPLL() const;
	void SetEnforceOPLL(const bool bEnforce);

	SCCMODULE GetSccModule() const;
	void SetSccModule(const SCCMODULE mod);

	HARZ80CLOCK	GetHarz80Clock() const;
	void SetHarz80Clock(const HARZ80CLOCK clk);

	uint8_t GetLoopCnt() const;
	void SetLoopCnt(const uint8_t n);

};