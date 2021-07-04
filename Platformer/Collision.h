#pragma once

#include <type_traits>

template <typename T>
concept Numeric = std::is_arithmetic<T>::value;

template <Numeric T>
struct point {
	T x, y;

	constexpr point() noexcept : x(0.0), y(0.0) { }
	constexpr point(T const x, T const y) noexcept : x(x), y(y) { }

	constexpr void operator = (point<T> const& other) noexcept {
		x = other.x;
		y = other.y;
	}
};

template <Numeric T>
struct rect {
	T x, y, w, h;
};

template <Numeric T, Numeric U>
constexpr bool point_in_rectangle(point<T> p, rect<U> r) noexcept {
	bool horizontal = (p.x >= r.x && p.x <= r.x + r.w);
	bool vertical = (p.y >= r.y && p.y <= r.y + r.h);
	return horizontal && vertical;
}
