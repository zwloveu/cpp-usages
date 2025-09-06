#pragma once

#include <cstring>

class RAIIString
{
private:
    char *_data;
    size_t _size;

    void reset() noexcept
    {
        _data = nullptr;
        _size = 0;
    }

public:
    RAIIString(const RAIIString &) = delete;
    RAIIString &operator=(const RAIIString &) = delete;
    RAIIString(const char *str = "")
    {
        if (str == nullptr)
            str = "";

        _size = std::strlen(str);
        _data = new char[_size + 1];
        std::strcpy(_data, str);
    }
    RAIIString(RAIIString &&other) noexcept
        : _data{other._data}, _size{other._size}
    {
        other.reset();
    }
    RAIIString &operator=(RAIIString &&other) noexcept
    {
        if (this != &other)
        {
            delete[] _data;
            _data = other._data;
            _size = other._size;

            other.reset();
        }
        return *this;
    }

    ~RAIIString()
    {
        delete[] _data;
    }

    const char *c_str() const { return _data; }
    size_t size() const { return _size; }
};