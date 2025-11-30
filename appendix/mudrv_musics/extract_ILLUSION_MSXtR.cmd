@echo off
python extract_0c00.py "disks/ILLCity_No1.dsk" MUDRV/ILLUSION No1
python extract_0c00.py "disks/ILLCity_No2.dsk" MUDRV/ILLUSION No2
python extract_0c00.py "disks/ILLCity_No3.dsk" MUDRV/ILLUSION No3
python extract_0c00.py "disks/ILLCity_No4.dsk" MUDRV/ILLUSION No4
python extract_0c00.py "disks/ILLCity_No5.dsk" MUDRV/ILLUSION No5
python extract_0c00.py "disks/ILLCity_No6.dsk" MUDRV/ILLUSION No6
python extract_0c00.py "disks/ILLCity_No7.dsk" MUDRV/ILLUSION No7
python extract_binary.py "disks/ILLCity_No1.dsk" 0x3800 0x200 MUDRV/ILLUSION/ILLUSION.KIK
pause

