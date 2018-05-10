@echo off

:AppInit
    setlocal EnableDelayedExpansion
    call Console Init
    color F8


:Main
    call Board new gameBoard 20 20 10
    %gameBoard.Create%
    :gameLoop
    goto :gameLoop


:AppEnd
    color 0A
