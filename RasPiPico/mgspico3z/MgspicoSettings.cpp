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
	p->MusicType = MUSICDATA::MGS;
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

const MgspicoSettings::ITEM *MgspicoSettings::GetItem(const int indexItem) const
{
	static const ITEM items[] = 
	{
		{"music",		5,	{"MGS", "MuSICA", "----1", "----2", "NDP", }	},
		{"auto run",	2,	{"OFF", "ON", }									},
		{"random",		2,	{"OFF", "ON", }									},
		{"use.SCC",		1,	{"IKASCC", "WTS", }								},
		{"harz clk",	2,	{"3.58MHz", "7.16MHz", }						},
	//	{"clock",		2,	{"125MHz", "240MHz", }							},
	};
	return &items[indexItem];
}

void MgspicoSettings::SetChioce(const int indexItem, const int no)
{
	switch(indexItem)
	{
		case 0:	m_Setting.MusicType = (MUSICDATA)no;		break;
		case 1:	m_Setting.AutoRun = no;						break;
		case 2:	m_Setting.RandomPlay = no;					break;
		case 3:	m_Setting.SccModule = (SCCMODULE)no;		break;
		case 4:	m_Setting.Harz80Clock = (HARZ80CLOCK)no;	break;
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
		case 1:	no = m_Setting.AutoRun;				break;
		case 2:	no = m_Setting.RandomPlay;			break;
		case 3:	no = (int)m_Setting.SccModule;		break;
		case 4:	no = (int)m_Setting.Harz80Clock;	break;
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
			return true;
		}
	}
	setDefault(&m_Setting);
	return false;;
}

bool MgspicoSettings::WriteSettingTo(const char *pFilePath)
{
	if( sd_fatWriteFileTo(pFilePath, (uint8_t *)&m_Setting, sizeof(m_Setting), false) )
		return true;
	return false;
}

MgspicoSettings::MUSICDATA MgspicoSettings::GetMusicType() const
{
	return m_Setting.MusicType;
}

void MgspicoSettings::SetMusicType(const MgspicoSettings::MUSICDATA type)
{
	m_Setting.MusicType = type;
	return;
}

bool MgspicoSettings::Is240MHz() const
{
	return (m_Setting.RpCpuClock == RPxxxxCLOCK::CLK240MHZ);
}

MgspicoSettings::RPxxxxCLOCK MgspicoSettings::GetRp2040Clock() const
{
	return m_Setting.RpCpuClock;
}

void MgspicoSettings::SetRp2040Clock(const MgspicoSettings::RPxxxxCLOCK clk)
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

MgspicoSettings::SCCMODULE MgspicoSettings::GetSccModule() const
{
	return m_Setting.SccModule;
}

void MgspicoSettings::SetSccModule(const MgspicoSettings::SCCMODULE mod)
{
	m_Setting.SccModule = mod;
	return;
}

MgspicoSettings::HARZ80CLOCK MgspicoSettings::GetHarz80Clock() const
{
	return m_Setting.Harz80Clock;
}

void MgspicoSettings::SetHarz80Clock(const MgspicoSettings::HARZ80CLOCK clk)
{
	m_Setting.Harz80Clock = clk;
	return;
}

