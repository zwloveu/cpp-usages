#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>

#include "cpp11/feature_modules/module01_range_for/demonstrate_range_for.h"
#include "cpp11/feature_modules/module02_left_right_value/demonstrate_left_right_value.h"
#include "cpp11/feature_modules/module03_raii/demonstrate_raii.h"
#include "cpp11/feature_modules/module04_constructor/demonstrate_constructor.h"
#include "cpp11/feature_modules/module05_pointer/demonstrate_pointer.h"
#include "cpp11/feature_modules/module06_namespace/demonstrate_namespace.h"
#include "cpp11/feature_modules/module07_extern_c/demonstrate_extern_c.h"
#include "cpp11/feature_modules/module08_third_party/demonstrate_third_party.h"

enum class Category
{
    c17,
    cpp11,
    cpp17,
    cpp20,
    cpp23
};

inline std::string category_to_string(Category category) noexcept
{
    switch (category)
    {
    case Category::c17:
        return "c17";
    case Category::cpp11:
        return "cpp11";
    case Category::cpp17:
        return "cpp17";
    case Category::cpp20:
        return "cpp20";
    case Category::cpp23:
        return "cpp23";
    default:
        return "unknown";
    }
}

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

    void register_operation(
        Category category,
        const std::string &key,
        std::function<void()> &&func) noexcept
    {
        std::string formatted_key = category_to_string(category) + "_" + key;
        _ops[formatted_key] = std::move(func);
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
        Category::cpp11,
        "module01_range_for.01_basic",
        []()
        { demonstrate_range_for_basic(); });
    registry.register_operation(
        Category::cpp11,
        "module01_range_for.02_modify",
        []()
        { demonstrate_range_for_modify(); });
    registry.register_operation(
        Category::cpp11,
        "module01_range_for.03_modify.ptr",
        []()
        { demonstrate_range_for_modify_ptr(); });
    registry.register_operation(
        Category::cpp11,
        "module01_range_for.04_modify.iter",
        []()
        { demonstrate_range_for_modify_iter(); });

    registry.register_operation(
        Category::cpp11,
        "module02_left_rightvalue.basic",
        []()
        { demonstrate_left_right_value_basic(); });

    registry.register_operation(
        Category::cpp11,
        "module03_raii.basic",
        []()
        { demonstrate_raii_basic(); });

    registry.register_operation(
        Category::cpp11,
        "module04_constructor.basic",
        []()
        { demonstrate_constructor_basic(); });

    registry.register_operation(
        Category::cpp11,
        "module05_pointer.01_basic",
        []()
        { demonstrate_pointer_basic(); });
    registry.register_operation(
        Category::cpp11,
        "module05_pointer.02_p2array",
        []()
        { demonstrate_pointer_p2array(); });
    registry.register_operation(
        Category::cpp11,
        "module05_pointer.03_p2p",
        []()
        { demonstrate_pointer_p2p(); });
    registry.register_operation(
        Category::cpp11,
        "module05_pointer.04_p2first",
        []()
        { demonstrate_pointer_p_to_first(); });
    registry.register_operation(
        Category::cpp11,
        "module05_pointer.05_voidpointer",
        []()
        { demonstrate_pointer_void(); });
    registry.register_operation(
        Category::cpp11,
        "module05_pointer.06_function_pointer",
        []()
        { demonstrate_pointer_function(); });

    registry.register_operation(
        Category::cpp11,
        "module06_namespace.basic",
        []()
        { module06_namespace::demonstrate_namespace_basic(); });

    registry.register_operation(
        Category::cpp11,
        "module07_extern_c.basic",
        []()
        { demonstrate_extern_c_basic(); });

    registry.register_operation(
        Category::cpp11,
        "module08_third_party.basic",
        []()
        { demonstrate_third_party_basic(); });
}