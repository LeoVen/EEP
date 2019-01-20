echo off
set projectname=%1
\masm32\bin\ml /c /Zd /coff %projectname%.asm
\masm32\bin\Link /SUBSYSTEM:CONSOLE %projectname%.obj