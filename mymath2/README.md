# mymath2 is a separate cmake project

## It is used to generated thirdparty libs to be used in libs in project root folder.

## build command in mymath2 folder

cmake -S . -B ./build/win64 -G "Visual Studio 17 2022" -A x64

# release command in mymath2/build/win64

cmake --build ./build/win64 --config Release
