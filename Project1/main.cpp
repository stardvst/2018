#include <iostream>
#include <chrono>
#include <filesystem>
#include <ctime>

namespace fs = std::experimental::filesystem;

uintmax_t ComputeFileSize(const fs::path &pathToCheck)
{
	if (fs::exists(pathToCheck) &&
		fs::is_regular_file(pathToCheck))
	{
		auto err = std::error_code {};
		auto filesize = fs::file_size(pathToCheck, err);
		if (filesize != static_cast<uintmax_t>(-1))
			return filesize;
	}
	return static_cast<uintmax_t>(-1);
}

void CoutLMT(const fs::path &entry)
{
	auto timeEntry = fs::last_write_time(entry);
	time_t cftime = std::chrono::system_clock::to_time_t(timeEntry);
	std::cout << std::asctime(std::localtime(&cftime));
}

void DisplayFileInfo(const fs::directory_entry &entry, const std::string &lead, const fs::path &filename)
{
	if (filename.extension() == ".docx")
		std::cout << lead << "[*] " << filename.filename() << " (" << entry.path().is_absolute() << ")\n";
}

void DisplayDirTree(const fs::path &pathToShow, int level)
{
	if (fs::exists(pathToShow) && fs::is_directory(pathToShow))
	{
		auto lead = std::string(level * 3, ' ');
		for (const auto &entry : fs::directory_iterator(pathToShow))
		{
			auto filename = entry.path().filename();
			if (fs::is_directory(entry.status()) && entry.path().filename() != ".git")
			{
				std::cout << lead << "[+] " << filename.filename() << '\n';
				DisplayDirTree(entry, level + 1);
				std::cout << '\n';
			}
			else if (fs::is_regular_file(entry.status()))
				DisplayFileInfo(entry, lead, filename);
			else
				std::cout << lead << " [?]" << filename.filename() << '\n';
		}
	}
}

int main()
{
	auto path = "C:\\Windows\\bfsvc.exe";
	std::cout << ComputeFileSize(path) << '\n';
	CoutLMT(path);

	DisplayDirTree("C:\\Users\\liliam\\Documents", 0);

	std::cin.get();
	return 0;
}
