# IBin

IBin is a way to convert text into binary and vice versa.

**IBin requires at least C++11** but C++20 is recommended.

**To compile IBin's example premake5 must be installed**. Then run the build.bat if on Windows, run the build.sh if on Unix like systems.

All functions have documentation. Most code editors like vscode and visual studio should support hovering over the functions and seeing the docs.

Here is an example of IBin:
```cpp
std::string textToBin = IBin::TextToBin("Hello!");
std::string binToText = IBin::BinToText(textToBin);

std::cout << "TextToBin Output: " << textToBin << '\n';
std::cout << "BinToText Output: " << binToText << '\n';

IBin::TextToBinFile("Hello Bin File!\n", "BinFile.bin");
std::string binFileToText = IBin::BinFileToText("BinFile.bin");
std::cout << "BinFileToText Output: " << binFileToText << '\n';

std::wstring wTextToWBin = IBin::WTextToWBin(L"wHello!");
std::wstring wBinToWText = IBin::WBinToWText(wTextToWBin);

std::wcout << "WTextToWBin Output: " << wTextToWBin << '\n';
std::wcout << "WBinToWText Output: " << wBinToWText << '\n';

IBin::WTextToWBinFile(L"Hello WBin File!\n", "WBinFile.bin");
std::wstring wBinFileToText = IBin::WBinFileToWText("WBinFile.bin");
std::wcout << "WBinFileToWText Output: " << wBinFileToText << '\n';

```
