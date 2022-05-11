#pragma once

#include <string>

#if __cplusplus >= 202002L // c++20+
    #define I_BIN_NO_DISCARD(msg) nodiscard(msg)
#elif __cplusplus == 201703L // c++17
    #define I_BIN_NO_DISCARD(msg) nodiscard
#else
    #define I_BIN_NO_DISCARD(msg)
#endif 


#define I_BIN_NO_RETURN noreturn

namespace IBin {
    /*
        Takes a wide string of text and converts it into a binary wide string
        A wide binary string seems identical to a regular binary string but its read very differently.
        A wide binary string is 32 bits instead of 8 like a normal string, so one character is 32 bits instead of 8.
        No discard
    */
    [[I_BIN_NO_DISCARD("DISCARDED BINARY WSTRING")]] std::wstring WTextToWBin(const std::wstring& text) noexcept;
    /*
        Takes a wide of text and converts it into a binary string
        No discard
    */
    [[I_BIN_NO_DISCARD("DISCARDED BINARY STRING")]] std::string TextToBin(const std::string& text) noexcept;
    /*
        Takes a wide string of binary and converts it into a wide string of text
        A wide binary string seems identical to a regular binary string but its read very differently.
        A wide binary string is 32 bits instead of 8 like a normal string, so one character is 32 bits instead of 8.
        No discard
    */
    [[I_BIN_NO_DISCARD("DISCARDED TEXT WSTRING")]] std::wstring WBinToWText(const std::wstring& bin) noexcept;
    /*
        Takes a string of binary and converts it into a string of text
        No discard
    */
    [[I_BIN_NO_DISCARD("DISCARDED TEXT STRING")]] std::string BinToText(const std::string& bin) noexcept;
    /*
        Takes a wide string and converts it into a wide binary string and then writes it to a new or existing file 
        A wide binary string seems identical to a regular binary string but its read very differently.
        A wide binary string is 32 bits instead of 8 like a normal string, so one character is 32 bits instead of 8.
    */
    void WTextToWBinFile(const std::wstring& text, const std::string& filename) noexcept;
    /*
        Takes a string and converts it into a binary string and then writes it to a new or existing file 
    */
    void TextToBinFile(const std::string& text, const std::string& filename) noexcept;
    /*
        Takes a wide binary file and converts it into a wide string of text
        A wide binary file like a wide binary string seems identical to a regular binary file but it is read differently.
        A wide binary file is 32 bits per character instead of 8 like a normal binary file.
    */
    [[I_BIN_NO_DISCARD("DISCARDED TEXT WSTRING")]] std::wstring WBinFileToWText(const std::string& filename) noexcept;
    /*
        Takes a binary file and converts it into a string of text
        A wide binary file like a wide binary string seems identical to a regular binary file but it is read differently.
        A wide binary file is 32 bits per character instead of 8 like a normal binary file.
    */
    [[I_BIN_NO_DISCARD("DISCARDED TEXT STRING")]] std::string BinFileToText(const std::string& filename) noexcept;
}