#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

#include "Logger.hpp"

/*
char* AppData = getenv("APPDATA");
char* localAppData = getenv("LOCALAPPDATA");
*/
std::string appDataToString(getenv("APPDATA"));
std::string localAppDataToString(getenv("LOCALAPPDATA"));

std::vector<std::string> localAppDataPaths = {
    localAppDataToString + "\\Discord",
    localAppDataToString + "\\DiscordCanary",
    localAppDataToString + "\\DiscordDevelopment",
    localAppDataToString + "\\DiscordPTB"
};

std::vector<std::string> localAppDataAuthorizedFiles = {
    "core.asar",
    "index.js",
    "package.json"
};

int main()
{
    Utils::consoleTitle("Home");
    for (auto& dir : localAppDataPaths) {
        std::string folderName = dir.substr(dir.find_last_of("/\\") + 1);
        Logger::Info("Verifying " + folderName + "...");
        int dirs = 0;
        if (!std::filesystem::exists(dir)) {
            //Logger::Error("Looks like you don't have X version of Discord"); // Using Split Or Something To Put It Here
        } else {
            for (auto& finalPath : Utils::getDirectories(dir, true)) {
                if (std::filesystem::exists(finalPath) && Utils::endsWith(finalPath, "discord_desktop_core")) {
                    dirs++;
                    std::vector<std::string> notSupposedToExistDirs = Utils::getDirectories(finalPath, false);
                    if (notSupposedToExistDirs.size() != 0) {
                        Logger::Warn("Suspicious Folder founds & deleted.");
                        for (auto& notSupposedToExistDir : notSupposedToExistDirs) {
                            std::filesystem::remove_all(notSupposedToExistDir);
                        }
                    }
                    for (auto& file : Utils::getFiles(finalPath)) {
                        std::string fileName = file.substr(file.find_last_of("/\\") + 1);
                        if (std::find(localAppDataAuthorizedFiles.begin(), localAppDataAuthorizedFiles.end(), fileName) == localAppDataAuthorizedFiles.end()) {
                            Logger::Warn("Suspicious File found & deleted.");
                            std::filesystem::remove(file);
                        }
                        if (fileName == "index.js") {
                            std::string content = "module.exports = require('./core.asar');";
                            if (Utils::file_contents(file) != content) {
                                Utils::writeAllText(file, content);
                                Logger::Warn("Suspicious Modifications.. Fixed !");
                            }
                        }
                    }
                }
            }
            if (dirs == 0) {
                Logger::Warn("Hum.. Looks like a not completelly Installed Discord Client or badly removed.. I'll fix it by deleting it.\n\nDelete(Y/N): ");
                std::string choice;
                std::cin >> choice;
                if (Utils::toLower(choice) == "y") {
                    Logger::Info("Deleted !");
                    std::filesystem::remove_all(dir);
                }
                else if (Utils::toLower(choice) == "n") {
                    Logger::Info("Cancelled !");
                }
                else {
                    std::cout << "You can't make a choice ?";
                    system("pause");
                    exit(1337);
                }
            }
        }
    }
    Logger::Info("Finished !");
    system("pause");
}