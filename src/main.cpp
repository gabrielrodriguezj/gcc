#include <iostream>
#include <fstream>


int readFile(std::string&, const std::string&);

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout<<"Correct use: gcc [file.c]";

        exit(64);
    }

    std::string source;
    if(const int res = readFile(source, argv[1]); res != 0) {
        return res;
    }

    std::cout<<"Source file: "<< std::endl <<source;
    return 0;
}

int readFile(std::string& source, const std::string& path) {

    std::ifstream fs{ path };
    if(fs.fail()){
        std::cout<<"File not found: " << path;
        return -1;
    }

    std::string str;
    fs.seekg(0, std::ios::end);
    str.reserve(fs.tellg());
    fs.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(fs)),
                std::istreambuf_iterator<char>());

    source.assign(str.begin(), str.end());

    return 0;
}
