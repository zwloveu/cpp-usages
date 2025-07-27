# project structor

cpp-usages/
├── include/
│ └── thirdparty/
│ │ └── mylib.h
├── libs/
│ ├── win64/
│ │ └── mylib.lib
│ └── linux-x64/
│ │ └── libmylib.a
├── src/
│ ├── cprimerplus/
│ ├── libs/
│ │ └── mymath

# Release command, in build folder, run:

cmake --build . --config Release
