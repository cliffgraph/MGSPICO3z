#include "MgspicoSettings.h"
#include "sdfat.h"


MgspicoSettings::MgspicoSettings()
{
	setDefault(&m_Setting);
	return;
}

MgspicoSettings::~MgspicoSettings()
{
	// do nothign
	return;
}

void MgspicoSettings::setDefault(SETTINGDATA *p)
{
	p->MusicType = MUSICTYPE::MGS;
	p->RpCpuClock = RPxxxxCLOCK::CLK125MHZ;
	p->AutoRun = 0;
	p->RandomPlay = 0;
	p->EnforceOPLL = 0;
	p->SccModule = SCCMODULE::IKASCC;
	p->Harz80Clock = HARZ80CLOCK::HARZ3M58HZ;
	for( int t = 0; t < (int)sizeof(m_Setting.Padding); ++t)
		p->Padding[t] = 0x00;
	return;
}

int	MgspicoSettings::GetNumItems() const
{
	return NUM_MENUITEMS;
}


const int MgspicoSettings::NUM_MENUITEMS = 6;	// メニュー数

const MgspicoSettings::ITEM *MgspicoSettings::GetItem(const int indexItem) const
{
	static const ITEM items[] = 
	{
		{"music",		6,	{" MGS ", "MuSICA", " NDP ", " VGM ", " TGF ", "MUDRV"}	},
		{"loop cnt",	4,	{" * ", " 1 ", " 2 ", " 3 ", }				},
		{"auto run",	2,	{"OFF", "ON", }							},
		{"random",		2,	{"OFF", "ON", }							},
		{"use.SCC",		1,	{"IKASCC", "WTS", }						},
		{"harz clk",	2,	{"3.58MHz", "7.16MHz", }				},
	//	{"clock",		2,	{"125MHz", "240MHz", }					},
	};
	return &items[indexItem];
}

void MgspicoSettings::SetChioce(const int indexItem, const int no)
{
	switch(indexItem)
	{
		case 0:	m_Setting.MusicType = (MUSICTYPE)no;		break;
		case 1:	m_Setting.LoopCnt = (uint8_t)no;			break;
		case 2:	m_Setting.AutoRun = no;						break;
		case 3:	m_Setting.RandomPlay = no;					break;
		case 4:	m_Setting.SccModule = (SCCMODULE)no;		break;
		case 5:	m_Setting.Harz80Clock = (HARZ80CLOCK)no;	break;
	//	case x:	m_Setting.RpCpuClock = (RPxxxxCLOCK)no;		break;
		default:											break;
	}
	return;
}

int MgspicoSettings::GetChioce(const int indexItem) const
{
	int no = 0;
	switch(indexItem)
	{
		case 0:	no = (int)m_Setting.MusicType;		break;
		case 1:	no = (int)m_Setting.LoopCnt;		break;
		case 2:	no = m_Setting.AutoRun;				break;
		case 3:	no = m_Setting.RandomPlay;			break;
		case 4:	no = (int)m_Setting.SccModule;		break;
		case 5:	no = (int)m_Setting.Harz80Clock;	break;
	//	case x:	no = (int)m_Setting.RpCpuClock;		break;
		default:									break;
	}
	return no;
}

bool MgspicoSettings::ReadSettingFrom(const char *pFilePath)
{
	UINT readSize;
	if( sd_fatReadFileFrom(pFilePath, sizeof(m_Setting), (uint8_t*)&m_Setting, &readSize) ) {
		if( sizeof(m_Setting) == readSize ) {
			// 正常に読み込めた
			return true;
		}
	}
	// 読み込み失敗、またはサイズ不一致の場合は、デフォルト値に戻す
	setDefault(&m_Setting);
	return false;;
}

bool MgspicoSettings::WriteSettingTo(const char *pFilePath)
{
	if( sd_fatWriteFileTo(pFilePath, (uint8_t *)&m_Setting, sizeof(m_Setting), false) )
		return true;
	return false;
}

MUSICTYPE MgspicoSettings::GetMusicType() const
{
	return m_Setting.MusicType;
}

void MgspicoSettings::SetMusicType(const MUSICTYPE type)
{
	m_Setting.MusicType = type;
	return;
}

bool MgspicoSettings::Is240MHz() const
{
	return (m_Setting.RpCpuClock == RPxxxxCLOCK::CLK240MHZ);
}

RPxxxxCLOCK MgspicoSettings::GetRp2040Clock() const
{
	return m_Setting.RpCpuClock;
}

void MgspicoSettings::SetRp2040Clock(const RPxxxxCLOCK clk)
{
	m_Setting.RpCpuClock = clk;
	return;
}

bool MgspicoSettings::GetAutoRun() const
{
	return (m_Setting.AutoRun==0)?false:true;
}

void MgspicoSettings::SetAutoRun(const bool bAuto)
{
	m_Setting.AutoRun = (bAuto)?1:0;
	return;
}

bool MgspicoSettings::GetRandomPlay() const
{
	return (m_Setting.RandomPlay==0)?false:true;
}

void MgspicoSettings::SetRandomPlay(const bool bRnd)
{
	m_Setting.RandomPlay = (bRnd)?1:0;
	return;
}

bool MgspicoSettings::GetEnforceOPLL() const
{
	return (m_Setting.EnforceOPLL==0)?false:true;
}

void MgspicoSettings::SetEnforceOPLL(const bool bEnforce)
{
	m_Setting.EnforceOPLL = (bEnforce)?1:0;
	return;
}

SCCMODULE MgspicoSettings::GetSccModule() const
{
	return m_Setting.SccModule;
}

void MgspicoSettings::SetSccModule(const SCCMODULE mod)
{
	m_Setting.SccModule = mod;
	return;
}

HARZ80CLOCK MgspicoSettings::GetHarz80Clock() const
{
	return m_Setting.Harz80Clock;
}

void MgspicoSettings::SetHarz80Clock(const HARZ80CLOCK clk)
{
	m_Setting.Harz80Clock = clk;
	return;
}

uint8_t MgspicoSettings::GetLoopCnt() const
{
	return m_Setting.LoopCnt;
}

void MgspicoSettings::SetLoopCnt(const uint8_t cnt)
{
	m_Setting.LoopCnt = cnt;
	return;
}

