#pragma once

#include <string>

#if __cplusplus >= 202002L // c++20
    #define I_BIN_NO_DISCARD(msg) nodiscard(msg)
#elif __cplusplus == 201703L // c++17
    #define I_BIN_NO_DISCARD(msg) nodiscard
#else
    #define I_BIN_NO_DISCARD(msg)
#endif 


#define I_BIN_NO_RETURN noreturn

namespace IBin {
    [[I_BIN_NO_DISCARD("DISCARDED BINARY WSTRING")]] std::wstring WTextToWBin(const std::wstring& text);
    [[I_BIN_NO_DISCARD("DISCARDED BINARY STRING")]] std::string TextToBin(const std::string& text);
    [[I_BIN_NO_DISCARD("DISCARDED TEXT WSTRING")]] std::wstring WBinToWText(const std::wstring& bin);
    [[I_BIN_NO_DISCARD("DISCARDED TEXT STRING")]] std::string BinToText(const std::string& bin); 
    void WTextToWBinFile(const std::wstring& text, const std::string& filename);
    void TextToBinFile(const std::string& text, const std::string& filename);
    [[I_BIN_NO_DISCARD("DISCARDED TEXT WSTRING")]] std::wstring WBinFileToWText(const std::string& filename);
    [[I_BIN_NO_DISCARD("DISCARDED TEXT STRING")]] std::string BinFileToText(const std::string& filename);
}