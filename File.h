#ifndef JUL_FILE_H
#define JUL_FILE_H

#include <fstream>
#include <string>
#include <cassert>

namespace jul {
// -------------------------------------------------------------------------------------
// Copy a file. This function will not throw like std::filesystem::copy_file but just
// return 'false' on a missing file / directory.
// Depending on the local std::ifstream/ofstream implementation this function should
// be non-blocking on the file to copy (fingers crossed)
// -------------------------------------------------------------------------------------
inline bool copy_file(const std::string& src_name, const std::string& dst_name)
{
    assert(!src_name.empty());
    assert(!dst_name.empty());

    std::ifstream src(src_name, std::ios::binary);
    if (!src.is_open()) { return false; }

    std::ofstream dst(dst_name, std::ios::binary);
    if (!dst.is_open()) { return false; }

    dst << src.rdbuf();
    return true;
}



// -------------------------------------------------------------------------------------
// Parse a file line by line. Fails silent on missing files by just returning an empty vector
// -------------------------------------------------------------------------------------
inline std::vector<std::string> file_to_lines(const std::string& file_name)
{
    assert(!file_name.empty());

    std::ifstream file(file_name);
    std::vector<std::string> lines{};
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}



// 'Function' should be of type std::function<void(std::string)> for similar
template <class Function>
void for_each_line(const std::string& file_name, Function&& fn)
{
    assert(!file_name.empty());

    std::ifstream file(file_name);
    std::string line;
    while (std::getline(file, line)) {
        fn(line);
    }
}
}

#endif // JUL_FILE_H