@echo off
chcp 65001
title 创建病毒
echo hi，病毒创建中
echo @echo off> sb.bat
echo echo...> sb.bat
echo timeout /t 0.2 >nul> sb.bat
echo echo 你为什么要打开我啊...> sb.bat
echo echo 我给你看个网页吧？> sb.bat
echo echo start https://dqs147852.github.io/gyc> sb.bat
echo  timeout /t 5 >nul> sb.bat
echo echo 没错，是这个远古网页> sb.bat
echo echo 唉，算了，没意思，5秒后我就把自己关了叭> sb.bat
echo timeout /t 5 />nul> sb.bat

timeout /t 5 >nul
echo 病毒创建完毕！



set /p choice=是否要打开该文件？(Y/N):

IF "%choice%"=="Y" (
    start "" "sb.bat"
) ELSE (
    echo 感谢使用！
)
pause
