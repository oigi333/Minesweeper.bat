

if "%1"=="Init" (
	set Console.WriteLine=call %0 :Console.WriteLine
	set Console.Write=call %0 :Console.Write
	set Console.SetColor=call %0 :Console.SetColor
	set Console.SetCursorPosition=call %0 :Console.SetCursorPosition
	set Console.ReadLine=call %0 :Console.ReadLine
	goto :EOF
)

call %*
goto :EOF

:Console.WriteLine
	cppbatAPI "Print" %1 -n
goto :EOF

:Console.Write
	cppbatAPI "Print" %1
goto :EOF

:Console.SetColor
	cppbatAPI "SetConsoleColor" %1 %2 %3 %4
goto :EOF 

:Console.SetCursorPosition
	cppbatAPI "SetCursorPosition" %1 %2
goto :EOF

:Console.ReadLine
	set /p %1=
goto :EOF