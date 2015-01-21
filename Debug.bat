@echo off
cd build\bin\Debug\
gdb -x=commands -batch gameserver.exe
pause
