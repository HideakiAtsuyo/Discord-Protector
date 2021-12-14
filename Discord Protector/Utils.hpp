#pragma once

#include <Windows.h>
#include <filesystem>
#include <fstream>

static class Utils {
public:
    static void color(int fg, int bg)
    {
        HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H, bg * 16 + fg);
    }

    static void consoleTitle(std::string x) {
        x = "Discord Protector | " + x + " | By Hideaki Atsuyo"; // Wish Mode Activated
        SetConsoleTitleA(x.c_str());
    }

    static std::string toLower(std::string x) {
        std::locale loc;
        for (std::string::size_type i = 0; i < x.length(); ++i)
            std::tolower(x[i], loc);
        return x;
    }

    static std::vector<std::string> getFiles(const std::string& s)
    {
        std::vector<std::string> r;
        for (auto& p : std::filesystem::directory_iterator(s))
            if (p.is_regular_file())
                r.push_back(p.path().string());
        return r;
    }

    static std::vector<std::string> getDirectories(const std::string& s, bool recursive = true)
    {
        std::vector<std::string> r;
        if (recursive) {
            for (auto& p : std::filesystem::recursive_directory_iterator(s))
                if (p.is_directory())
                    r.push_back(p.path().string());
        }
        else {
            for (auto& p : std::filesystem::directory_iterator(s))
                if (p.is_directory())
                    r.push_back(p.path().string());
        }
        return r;
    }

    /* Ty */
    static bool endsWith(const std::string& mainStr, const std::string& toMatch)
    {
        if (mainStr.size() >= toMatch.size() &&
            mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
            return true;
        return false;
    }

    static std::string file_contents(const std::filesystem::path& path)
    {
        if (!std::filesystem::is_regular_file(path))
            return { };
        std::ifstream file(path, std::ios::in | std::ios::binary);
        if (!file.is_open())
            return { };
        const std::size_t& size = std::filesystem::file_size(path);
        std::string content(size, '\0');
        file.read(content.data(), size);
        file.close();
        return content;
    }
    /* Ty */
};