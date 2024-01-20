@echo off
chcp 65001

title 只有super boy 才会打开
setlocal enabledelayedexpansion

set idx=0
for /L %%i in (1,1,10000) do (
    set /a idx=!idx!+1
    set color=!idx!
    if !color! gtr 15 set idx=0
    color !color!
    echo 我是病毒!
    timeout /t 0.3 /nobreak >nul
)

color 07
echo Done!
pause >nul
