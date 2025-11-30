@echo off
python extract_0c00.py "disks/FRAY_TR_D0.dsk" MUDRV/FRAYtR D0
python extract_0c00.py "disks/FRAY_TR_D1.dsk" MUDRV/FRAYtR D1
python extract_0c00.py "disks/FRAY_TR_D2.dsk" MUDRV/FRAYtR D2
python extract_0c00.py "disks/FRAY_TR_G0.dsk" MUDRV/FRAYtR G0
python extract_0c00.py "disks/FRAY_TR_G1.dsk" MUDRV/FRAYtR G1
python extract_binary.py "disks/FRAY_TR_D0.dsk" 0x4200 0x200 MUDRV/FRAYtR/FRAYtR.KIK
pause

