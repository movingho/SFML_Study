@echo off
echo =========================================
echo  Generating Visual Studio 2022 project...
echo =========================================

rem 'build' 폴더가 있다면 깨끗하게 삭제
if exist build (
    echo Deleting existing build directory...
    rmdir /s /q build
)

rem Visual Studio 2022 생성기로 프로젝트 생성
cmake -B build -G "Visual Studio 17 2022"

echo.
echo Project generation complete!
echo You can now open the .sln file in the 'build' directory.
pause