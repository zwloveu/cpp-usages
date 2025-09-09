# mymath2 build
## windows+vs2022
```
cmake -S . -B ./out/build/win64/release -G "Visual Studio 17 2022"
cmake --build ./out/build/win64/release --config Release --target mymath2
```

## linux+gcc
```
cmake -S . -B ./out/build/linux/release -DCMAKE_BUILD_TYPE=Release -G Ninja
cmake --build ./out/build/linux/release --target mymath2
```