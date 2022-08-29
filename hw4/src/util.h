#pragma once
#include <cstdlib>
#include <sstream>
#include <list>
#include <vector>
#include <tuple>


template <typename T>
struct is_vector : std::false_type {};

/**
 * Checks if passed type is a vector
 * @tparam A vector's underlying type
 * @tparam An allocator type
 * 
 */
template <typename T, typename U>
struct is_vector<std::vector<T, U>> : std::true_type {};

template <typename T>
inline constexpr bool is_vector_v = is_vector<T>::value;

template <typename T>
struct is_list : std::false_type {};

template <typename T, typename U>
struct is_list<std::list<T, U>> : std::true_type {};

template <typename T>
inline constexpr bool is_list_v = is_list<T>::value;

template <typename T>
struct is_tuple : std::false_type {};

template <typename... Args>
struct is_tuple<std::tuple<Args...>> : std::true_type {};

template <typename T>
inline constexpr bool is_tuple_v = is_tuple<T>::value;

template <typename T>
inline constexpr bool is_cstr_v = std::is_same_v<const char*, T> || std::is_same_v<char*, T>;

template <typename T>
struct is_string_literal : std::false_type {};

template <size_t N>
struct is_string_literal<const char (&) [N]> : std::true_type {};

template <typename T>
inline constexpr bool is_string_literal_v = is_string_literal<T>::value;

template <typename T, typename S, size_t N>
struct IntegralReprImpl {
    static void Get(T x, S& ss) {
        int b = (x >> 8 * N) & (0xff);
        ss << b << ".";
        IntegralReprImpl<T, S, N - 1>::Get(x, ss);
    }
};

template <typename T, typename S>
struct IntegralReprImpl<T, S, 0> {
    static void Get(T x, S& ss) {
        int b = x & (0xff);
        ss << b;
    }
};

template <typename T, typename std::enable_if_t<std::is_integral_v<T>>* = nullptr>
std::string GetStringRepr(T x) {
    std::stringstream ss;
    IntegralReprImpl<T, decltype(ss), sizeof(x) - 1>::Get(x, ss);
    return ss.str();
}

template <typename T, typename std::enable_if_t<std::is_same_v<std::string, std::decay_t<T>>>* = nullptr>
T&& GetStringRepr(T&& x) {
    return std::forward<T>(x);
}

template <typename T, typename std::enable_if_t<is_cstr_v<T> || is_string_literal_v<T>>* = nullptr>
std::string GetStringRepr(T x) {
    return {x};
}

template <typename T, typename = std::enable_if_t<is_vector_v<T> || is_list_v<T>>>
std::string GetStringRepr(const T& cont) {
    std::stringstream ss;

    auto it = cont.begin();
    for (size_t i = 0; i + 1 < cont.size(); ++i, ++it) {
        ss << *it << ".";
    }
    ss << *it;

    return ss.str();
}

template <typename T, typename E, typename S, size_t N>
struct TupleReprImpl {
    static void Get(const T& t, S& ss) {
        constexpr size_t i = std::tuple_size<T>::value - N - 1;
        static_assert(std::is_same_v<E, std::tuple_element_t<i, T>>,
                "The elements must be the same type.");
        ss << std::get<i>(t) << ".";
        TupleReprImpl<T, E, S, N - 1>::Get(t, ss);
    }
};

template <typename T, typename E, typename S>
struct TupleReprImpl<T, E, S, 0> {
    static void Get(const T& t, S& ss) {
        constexpr size_t i = std::tuple_size<T>::value - 1;
        static_assert(std::is_same_v<E, std::tuple_element_t<i, T>>,
                      "The elements must be the same type.");
        ss << std::get<i>(t);
    }
};

template <typename T, typename std::enable_if<is_tuple_v<T>>::type* = nullptr>
std::string GetStringRepr(const T& t) {
    std::stringstream ss;
    TupleReprImpl<T, std::tuple_element_t<0, T>, std::stringstream, std::tuple_size_v<T> - 1>::Get(t, ss);
    return ss.str();
}

