#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t length;

    void copyFrom(const char* str, size_t len) {
        data = new char[len + 1];
        std::memcpy(data, str, len);
        data[len] = '\0';
        length = len;
    }

public:
    String() : data(nullptr), length(0) {
        data = new char[1];
        data[0] = '\0';
    }

    String(const char* str) {
        if (str) {
            length = std::strlen(str);
            copyFrom(str, length);
        } else {
            data = new char[1];
            data[0] = '\0';
            length = 0;
        }
    }

    String(const String& other) {
        if (other.data) {
            copyFrom(other.data, other.length);
        } else {
            data = new char[1];
            data[0] = '\0';
            length = 0;
        }
    }
