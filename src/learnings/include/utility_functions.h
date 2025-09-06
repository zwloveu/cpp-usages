#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <iterator>

namespace utility_functions
{
    template <typename Iter>
    struct EnumerateIterator
    {
        using value_type = std::pair<size_t, typename std::iterator_traits<Iter>::reference>;
        using reference = value_type;
        using pointer = void;
        using difference_type = typename std::iterator_traits<Iter>::difference_type;
        using iterator_category = typename std::iterator_traits<Iter>::iterator_category;

        Iter iter;
        size_t index;

        EnumerateIterator(Iter iter, size_t index) : iter(iter), index(index) {}

        reference operator*() const { return {index, *iter}; }

        EnumerateIterator &operator++()
        {
            ++iter;
            ++index;
            return *this;
        }

        bool operator!=(const EnumerateIterator &other) const
        {
            return iter != other.iter;
        }
    };

    template <typename Iter>
    struct EnumerateRange
    {
        Iter begin_iter;
        Iter end_iter;

        EnumerateRange(Iter begin, Iter end) : begin_iter{begin}, end_iter{end} {}

        EnumerateIterator<Iter> begin() const
        {
            return {begin_iter, 0};
        }

        EnumerateIterator<Iter> end() const
        {
            return {end_iter, 0};
        }
    };

    template <typename Iter>
    EnumerateRange<Iter> enumerate(Iter begin, Iter end)
    {
        return EnumerateRange<Iter>(begin, end);
    }
}