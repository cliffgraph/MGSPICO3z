@echo off
python extract_0c00.py "disks/XAK_D1.dsk" MUDRV/Xak No1
python extract_0c00.py "disks/XAK_D2.dsk" MUDRV/Xak No2
python extract_0c00.py "disks/XAK_D3.dsk" MUDRV/Xak No3
python extract_binary.py "disks/XAK_D1.dsk" 0x12E00 0x200 MUDRV/XAK/XAK.KIK
pause

