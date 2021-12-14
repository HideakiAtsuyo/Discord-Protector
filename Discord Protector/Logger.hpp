#pragma once

#include <iostream>
#include <string>

#include "Utils.hpp"

static class Logger {
public:
	static void Info(std::string x) { // Wish Mode Activated
		Utils::color(2, 0);
		std::cout << "[";
		Utils::color(3, 0);
		std::cout << "INFO";
		Utils::color(2, 0);
		std::cout << "] ";
		Utils::color(3, 0);
		std::cout << x << std::endl;
		Utils::color(15, 0);
	}
	static void Error(std::string x) { // Wish Mode Activated
		Utils::color(2, 0);
		std::cout << "[";
		Utils::color(12, 0);
		std::cout << "ERROR";
		Utils::color(2, 0);
		std::cout << "] ";
		Utils::color(12, 0);
		std::cout << x << std::endl;
		Utils::color(15, 0);
	}
	static void Warn(std::string x) { // Wish Mode Activated
		Utils::color(2, 0);
		std::cout << "[";
		Utils::color(14, 0);
		std::cout << "WARN";
		Utils::color(2, 0);
		std::cout << "] ";
		Utils::color(14, 0);
		std::cout << x << std::endl;
		Utils::color(15, 0);
	}
	static void Anything(std::string x) {
		std::cout << x << std::endl;
	}
};