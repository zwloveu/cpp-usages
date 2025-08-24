#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>

#include "module01_range_for/demonstrate_range_for.h"
#include "module02_left_right_value/demonstrate_left_right_value.h"
#include "module03_raii/demonstrate_raii.h"
#include "module04_constructor/demonstrate_constructor.h"
#include "module05_pointer/demonstrate_pointer.h"
#include "module06_namespace/demonstrate_namespace.h"
#include "module07_extern_c/demonstrate_extern_c.h"

class OperationRegistry
{
private:
    OperationRegistry() = default;
    std::map<std::string, std::function<void()>> _ops;

public:
    OperationRegistry(const OperationRegistry &) = delete;
    OperationRegistry &operator=(const OperationRegistry &) = delete;
    OperationRegistry(OperationRegistry &&) = delete;
    OperationRegistry &operator=(OperationRegistry &&) = delete;

    static OperationRegistry &get_instance()
    {
        static OperationRegistry instance;
        return instance;
    }

    void register_operation(const std::string &key, std::function<void()> func) noexcept
    {
        _ops[key] = std::move(func);
    }

    const std::map<std::string, std::function<void()>> &get_operations() const
    {
        return _ops;
    }
};

inline void register_all_operations()
{
    auto &registry = OperationRegistry::get_instance();

    registry.register_operation(
        "module01_range_for.basic",
        []()
        { demonstrate_range_for_basic(); });
    registry.register_operation(
        "module01_range_for.modify",
        []()
        { demonstrate_range_for_modify(); });
    registry.register_operation(
        "module01_range_for.modify.ptr",
        []()
        { demonstrate_range_for_modify_ptr(); });
    registry.register_operation(
        "module01_range_for.modify.iter",
        []()
        { demonstrate_range_for_modify_iter(); });

    registry.register_operation(
        "module02_left_rightvalue.basic",
        []()
        { demonstrate_left_right_value_basic(); });

    registry.register_operation(
        "module03_raii.basic",
        []()
        { demonstrate_raii_basic(); });

    registry.register_operation(
        "module04_constructor.basic",
        []()
        { demonstrate_constructor_basic(); });

    registry.register_operation(
        "module05_pointer.basic",
        []()
        { demonstrate_pointer_basic(); });

    registry.register_operation(
        "module06_namespace.basic",
        []()
        { module06_namespace::demonstrate_namespace_basic(); });

    registry.register_operation(
        "module07_extern_c.basic",
        []()
        { demonstrate_extern_c_basic(); });
}