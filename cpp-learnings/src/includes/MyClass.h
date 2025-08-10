class MyClass
{
private:
    int x;

public:
    MyClass() = delete;
    MyClass(int x);
    MyClass(const MyClass& rhs);
    MyClass& operator=(const MyClass& rhs);

    void print_x() const;
};