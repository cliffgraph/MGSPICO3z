@echo off
python extract_0c00.py disks/CAMP_DAISENRYAKU2_MSX2.dsk MUDRV/CMPDAIS2 D
python extract_binary.py disks/CAMP_DAISENRYAKU2_MSX2.dsk 0x88207 0x200 MUDRV/CMPDAIS2/CMPDAIS2.KIK

pause

