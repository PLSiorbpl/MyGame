:: Tak używam tego do innych projektów np. MyCraft
setlocal

:: ------Flags-------
set Flags1=-I src
set Flags2=-O3 -std=c++17 -Llib -static-libstdc++ -static-libgcc -static


:: ------Path--------


:: ------Sources-----


:: -----Compilation--
g++ %Flags1% src/Main.cpp %Flags2% -o ../MyGame.exe

cd ..
MyGame.exe
pause
