@echo off
:: 设置VS2022的环境变量路径
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

:: 进入项目所在目录
cd /d "D:\Source\EnhancedNativeTrainer\EnhancedNativeTrainer-FIying-Scotsman"

:: 调用MSBuild进行编译
msbuild "EnhancedNativeTrainer.sln" /p:Configuration=Release

:: 检查编译是否成功
if %errorlevel% neq 0 (
    echo 编译失败，退出脚本。
    pause
    exit /b %errorlevel%
)

:: 定义目标路径
set TARGET_PATH=D:\Games\GTAV

:: 创建目标路径（如果不存在）
if not exist "%TARGET_PATH%" (
    mkdir "%TARGET_PATH%"
)

:: 将特定格式的文件复制到目标路径（例如 .dll 和 .exe 文件）
xcopy "D:\Source\EnhancedNativeTrainer\EnhancedNativeTrainer-FIying-Scotsman\EnhancedNativeTrainer\bin\Release\*.asi" "%TARGET_PATH%\" /Y

echo 指定格式的文件已复制到 %TARGET_PATH%
pause
