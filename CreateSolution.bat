DEL /S *.sln
DEL /S *.vcxproj
DEL /S *.vcxproj.filters
DEL /S *.vcxproj.user
DEL /q .vs
rmdir /q /s build

DEL /S imgui.ini

CALL vendor\premake\premake5.exe vs2022

pause