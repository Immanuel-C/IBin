#include "IBin.h"

#include <sstream>
#include <fstream>
#include <bitset>
#include <iostream>

namespace IBin {
    static const int64_t SIZEOF_WCHAR_BITS = sizeof(wchar_t) * 8;
    static const int64_t SIZEOF_CHAR_BITS = sizeof(char) * 8;

    std::wstring WTextToWBin(const std::wstring& text) noexcept {
        std::wstringstream wss{};
        for (size_t i = 0; i < text.size(); i++) 
            wss << std::bitset<SIZEOF_WCHAR_BITS>{(size_t)text[i]} ;

        return wss.str();
    }

    std::string TextToBin(const std::string& text) noexcept {
        std::stringstream ss{};
        for (size_t i = 0; i < text.size(); i++) 
            ss << std::bitset<SIZEOF_CHAR_BITS>{(size_t)text[i]};

        return ss.str();
    }

    std::wstring WBinToWText(const std::wstring& bin) noexcept {
        std::wstringstream wss;
        for (size_t i = 0; i < bin.size(); i += SIZEOF_WCHAR_BITS)
            wss << (wchar_t)std::bitset<SIZEOF_WCHAR_BITS>{ std::string{ bin.begin() + i, bin.begin() + i + SIZEOF_WCHAR_BITS } }.to_ulong();
        return wss.str();
    }

    std::string BinToText(const std::string& bin) noexcept {
        std::stringstream ss;
        for (size_t i = 0; i < bin.size(); i += SIZEOF_CHAR_BITS)
            ss << (char)std::bitset<SIZEOF_CHAR_BITS>{ std::string{ bin.begin() + i, bin.begin() + i + SIZEOF_CHAR_BITS } }.to_ulong();
        return ss.str();
    } 

    void WTextToWBinFile(const std::wstring& text, const std::string& filename) noexcept {
        std::wofstream fs{ filename, std::ios::binary };
        fs << WTextToWBin(text);
        fs.close();
    }

    void TextToBinFile(const std::string& text, const std::string& filename) noexcept {
        std::ofstream fs{ filename, std::ios::binary };
        fs << TextToBin(text);
        fs.close();
    }

    std::wstring WBinFileToWText(const std::string& filename) noexcept {
        std::wifstream ifs{ filename, std::ios::binary };
        std::wstring bin;
        std::wstring result;

        if (!ifs.is_open()) {
            std::cerr << "IBin Error (WBinFileToWText): " << filename << " doesn't exist!\n";
            return { };
        }

        // Extract contents from file
        ifs >> bin;

        // Convert
        result = WBinToWText(bin);
        return result;
    }

    std::string BinFileToText(const std::string& filename) noexcept {
        std::ifstream ifs{ filename, std::ios::binary };
        std::string bin;
        std::string result;

        if (!ifs.is_open()) {
            std::cerr << "IBin Error (WBinFileToWText): " << filename << " doesn't exist!\n";
            return { };
        }

        // Extract contents from file
        ifs >> bin;

        // Convert
        result = BinToText(bin);


        return result;
    }
}