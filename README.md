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

# LLVM
## install: https://apt.llvm.org/
```
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh <version number> all
# or
sudo ./llvm.sh all
```
## set default version
```
sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-20 100
sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-20 100
sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-20 100
sudo update-alternatives --install /usr/bin/lld lld /usr/bin/lld-20 100
sudo update-alternatives --install /usr/bin/lldb-dap lldb-dap /usr/bin/lldb-dap-20 100
sudo update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-20 100
```