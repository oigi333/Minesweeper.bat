if "%1"=="new" (
    set %2.Create=call %0 :Board.Create %2
    set %2.Width=%3
    set %2.Height=%4
    set %2.NumberOfBombs=%5

	goto :EOF
)

call %*
goto :EOF

:Board.Create
    set Board.Create.bombPlanted=0


    :Board.Create.Loop
        set /A Board.Create.bombPlanted=%Board.Create.bombPlanted%+1
    if %Board.Create.bombPlanted% lss !%1.NumberOfBombs! goto :Board.Create.Loop
goto :EOF