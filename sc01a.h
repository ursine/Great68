//
// Created by bear on 1/16/25.
//

#pragma once

#include <cstdint>
#include <array>

extern std::array<uint8_t, 512> sc01a_bin;

/// \brief Extract a single bit from an integer
///
/// Extracts a single bit from an integer into the least significant bit
/// position.
///
/// \param [in] x The integer to extract the bit from.
/// \param [in] n The bit to extract, where zero is the least
///   significant bit of the input.
/// \return Zero if the specified bit is unset, or one if it is set.
/// \sa bitswap
template <typename T, typename U>
constexpr T BIT(T x, U n) noexcept {
	return (x >> n) & T(1);
}

/// \brief Extract bits in arbitrary order
///
/// Extracts bits from an integer.  Specify the bits in the order they
/// should be arranged in the output, from most significant to least
/// significant.  The extracted bits will be packed into a right-aligned
/// field in the output.
///
/// \param [in] val The integer to extract bits from.
/// \param [in] b The first bit to extract from the input
///   extract, where zero is the least significant bit of the input.
///   This bit will appear in the most significant position of the
///   right-aligned output field.
/// \param [in] c The remaining bits to extract, where zero is the
///   least significant bit of the input.
/// \return The extracted bits packed into a right-aligned field.
template <typename T, typename U, typename... V>
constexpr T bitswap(T val, U b, V... c) noexcept
{
	if constexpr (sizeof...(c) > 0U)
		return (BIT(val, b) << sizeof...(c)) | bitswap(val, c...);
	else
		return BIT(val, b);
}

