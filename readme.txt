set PATH=%PATH%;D:\usr\local\ssl\bin
set INCLUDE=%INCLUDE%;D:\usr\local\ssl\include
set LIB=%LIB%;D:\usr\local\ssl\lib
set PATH=%PATH%;C:\Python27

configure.bat -confirm-license -opensource -debug-and-release -nomake tests -nomake examples -opengl desktop -openssl-linked











