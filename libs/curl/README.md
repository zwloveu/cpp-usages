# Build Release

## Windows+MinW64+Ninja in curl source root folder
```
cmake.EXE -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -S . -B ./build -G Ninja -DCURL_STATICLIB=ON -DBUILD_SHARED_LIBS=OFF -DCMAKE_USE_WINSSL=ON

cmake --build ./build --config Release
```