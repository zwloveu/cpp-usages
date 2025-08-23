#pragma once

#include <cstring>

class MyString
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
    MyString(const MyString &) = delete;
    MyString &operator=(const MyString &) = delete;
    MyString(const char *str = "")
    {
        if (str == nullptr)
            str = "";

        _size = std::strlen(str);
        _data = new char[_size + 1];
        std::strcpy(_data, str);
    }
    MyString(MyString &&other) noexcept
        : _data{other._data}, _size{other._size}
    {
        other.reset();
    }
    MyString &operator=(MyString &&other) noexcept
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

    ~MyString()
    {
        delete[] _data;
    }

    const char *c_str() const { return _data; }
    size_t size() const { return _size; }
};