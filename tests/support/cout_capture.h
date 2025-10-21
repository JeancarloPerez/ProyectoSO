#pragma once
#include <iostream>
#include <sstream>

struct CoutCapture {
    std::streambuf* old = nullptr;
    std::ostringstream oss;
    CoutCapture() { old = std::cout.rdbuf(oss.rdbuf()); }
    ~CoutCapture() { std::cout.rdbuf(old); }
    std::string str() const { return oss.str(); }
};
