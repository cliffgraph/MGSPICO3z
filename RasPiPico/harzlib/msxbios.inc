;code:utf-8(bom)
;@auther Harumakkin

IO:
	.SLOTPG		equ			0xA8			; 各ページのスロット割り当て

DOS:
	.SYSTEMCALL	equ			0x0005

BIOS:
	.CHKRAM		equ			0x0000
	.SYNCHR		equ			0x0008
	.RDSLT		equ			0x000C
	.CHRGTR		equ			0x0010
	.WRSLT		equ			0x0014
	.OUTDO		equ			0x0018
	.CALSLT		equ			0x001C
	.DCOMPR		equ			0x0020
	.ENASLT		equ			0x0024
	.GETYPR		equ			0x0028
	.CALLF		equ			0x0030
	.KEYINT		equ			0x0038
	.INITIO		equ			0x003B
	.INIFNK		equ			0x003E
	.DISSCR		equ			0x0041
	.ENASCR		equ			0x0044
	.WRTVDP		equ			0x0047
	.RDVRM		equ			0x004A
	.WRTVRM		equ			0x004D
	.SETRD		equ			0x0050
	.SETWRT		equ			0x0053
	.FILVRM		equ			0x0056
	.LDIRMV		equ			0x0059
	.LDIRVM		equ			0x005C
	.CHGMOD		equ			0x005F
	.CHGCLR		equ			0x0062
	.NMI		equ			0x0066
	.CLRSPR		equ			0x0069
	.INITXT		equ			0x006C
	.INIT32		equ			0x006F
	.INIGRP		equ			0x0072
	.INIMLT		equ			0x0075
	.SETTXT		equ			0x0078
	.SETT32		equ			0x007B
	.SETGRP		equ			0x007E
	.SETMLT		equ			0x0081
	.CALPAT		equ			0x0084
	.CALATR		equ			0x0087
	.GSPSIZ		equ			0x008A
	.GRPPRT		equ			0x008D
	.GICINI		equ			0x0090
	.WRTPSG		equ			0x0093
	.RDPSG		equ			0x0096
	.STRTMS		equ			0x0099
	.CHSNS		equ			0x009C
	.CHGET		equ			0x009F
	.CHPUT		equ			0x00A2
	.LPTOUT		equ			0x00A5
	.LPTSTT		equ			0x00A8
	.CNVCHR		equ			0x00AB
	.PINLIN		equ			0x00AE
	.INLIN		equ			0x00B1
	.QINLIN		equ			0x00B4
	.BREAKX		equ			0x00B7
	.BEEP		equ			0x00C0
	.CLS		equ			0x00C3
	.POSIT		equ			0x00C6
	.FNKSB		equ			0x00C9
	.ERAFNK		equ			0x00CC
	.DSPFNK		equ			0x00CF
	.TOTEXT		equ			0x00D2
	.GTSTCK		equ			0x00D5
	.GTTRIG		equ			0x00D8
	.GTPAD		equ			0x00DB
	.GTPDL		equ			0x00DE
	.TAPION		equ			0x00E1
	.TAPIN		equ			0x00E4
	.TAPIOF		equ			0x00E7
	.TAPOON		equ			0x00EA
	.TAPOUT		equ			0x00ED
	.TAPOOF		equ			0x00F0
	.STMOTR		equ			0x00F3
	.CHGCAP		equ			0x0132
	.CHGSND		equ			0x0135
	.RSLREG		equ			0x0138
	.WSLREG		equ			0x013B
	.RDVDP		equ			0x013E
	.SNSMAT		equ			0x0141
	.ISFLIO		equ			0x014A
	.OUTDLP		equ			0x014D
	.KILBUF		equ			0x0156
	.CALBAS		equ			0x0159
;
	.CHGCPU		equ			0x0180
	.GETCPU		equ			0x0183
	.PCMPLY		equ			0x0186
	.PCMREC		equ			0x0189

SYSWORK:
	.JIFFY		equ			0xfc9e		; word.

ORG_HARZENTRY	equ			0x3000		; エントリーポイント
ORG_INTRENTRY	equ			0x3040
ORG_WORKIF		equ			0x30F0
ORG_CODE		equ			0x3100