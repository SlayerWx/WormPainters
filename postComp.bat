copy %1assets\raylib.dll %2 /y
mkdir %2assets
xcopy %1assets\assets %2\assets /s /E /y /i
pause