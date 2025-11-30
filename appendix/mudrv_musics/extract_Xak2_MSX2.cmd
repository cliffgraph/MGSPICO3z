@echo off
python extract_0c00.py "disks/Xak2_D1.dsk" MUDRV/Xak2 No1
python extract_0c00.py "disks/Xak2_D2.dsk" MUDRV/Xak2 No2
python extract_0c00.py "disks/Xak2_D3.dsk" MUDRV/Xak2 No3
python extract_0c00.py "disks/Xak2_D4.dsk" MUDRV/Xak2 No4
python extract_0c00.py "disks/Xak2_D5.dsk" MUDRV/Xak2 No5
python extract_binary.py "disks/Xak2_D1.dsk" 0x12E00 0x200 MUDRV/Xak2/Xak2.KIK
pause

