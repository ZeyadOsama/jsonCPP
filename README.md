# jsonCPP
<p>
  <img src="https://img.shields.io/pypi/status/Django.svg" alt="stable"/>
  <img src="https://img.shields.io/badge/contributions-welcome-orange.svg" alt="contributions-welcome-orange"/>
</p>

C++ JSON **```(*.json)```** Parser.

## Usage
In your  **```CMakeLists.txt```** file add these lines
```cmake
add_subdirectory(json)
include_directories(json/include)
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


