# jsonCPP

[![CI Actions Status](https://github.com/ZeyadOsama/jsonCPP/workflows/CI/badge.svg)](https://github.com/ZeyadOsama/jsonCPP/actions)
<img src="https://img.shields.io/pypi/status/Django.svg" alt="stable"/>
<img src="https://img.shields.io/badge/contributions-welcome-orange.svg" alt="contributions-welcome-orange"/>

## About
C++ JSON **```(*.json)```** Parser.

## Usage
In your  **```CMakeLists.txt```** file add these lines

```cmake
add_subdirectory(json)
include_directories(include)
```

Then add this header in the file you'd like to have your parser at
```c++
#include <json.h>

using namespace json;
```

### Multiple Files
```c++
vector<string> v;
v.push_back(json_file_path_1);
v.push_back(json_file_path_2);
v.push_back(json_file_path_3);

json::Value val = Parser::ParseMultiple(v);
```

### Single Files
```c++
string json_file_path_1 = "<path>"
json::Value val = Parser::ParseFile(json_file_path_1);
```

## Versioning
When installing jsonCPP, require it's version. For us, this is what ```major.minor.patch``` means:

- ```major``` - **MAJOR breaking changes**; includes major new features, major changes in how the whole system works, and complete rewrites; it allows us to _considerably_ improve the product, and add features that were previously impossible.
- ```minor``` - **MINOR breaking changes**; it allows us to add big new features.
- ```patch``` - **NO breaking changes**; includes bug fixes and non-breaking new features.

## Changelog
For all-time versions, please see the [CHANGELOG](CHANGELOG.rst) file.


## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details



