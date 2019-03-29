/**
 * \file
 * Functions and types for CRC checks.
 *
 * Generated on Sat Feb 23 21:45:35 2019
 * by pycrc v0.9.2, https://pycrc.org
 * using the configuration:
 *  - Width         = 32
 *  - Poly          = 0x1edc6f41
 *  - XorIn         = 0xffffffff
 *  - ReflectIn     = True
 *  - XorOut        = 0xffffffff
 *  - ReflectOut    = True
 *  - Algorithm     = table-driven
 *
 * This file defines the functions crc_init(), crc_update() and crc_finalize().
 *
 * The crc_init() function returns the inital \c crc value and must be called
 * before the first call to crc_update().
 * Similarly, the crc_finalize() function must be called after the last call
 * to crc_update(), before the \c crc is being used.
 * is being used.
 *
 * The crc_update() function can be called any number of times (including zero
 * times) in between the crc_init() and crc_finalize() calls.
 *
 * This pseudo-code shows an example usage of the API:
 * \code{.c}
 * crc_t crc;
 * unsigned char data[MAX_DATA_LEN];
 * size_t data_len;
 *
 * crc = crc_init();
 * while ((data_len = read_data(data, MAX_DATA_LEN)) > 0) {
 *     crc = crc_update(crc, data, data_len);
 * }
 * crc = crc_finalize(crc);
 * \endcode
 */

/*
 * Transliterated to C++ by Jacob Schloss
 */

#pragma once

#include <cstdlib>
#include <cstdint>

class crc_32c
{
public:
	/**
	 * The type of the CRC values.
	 *
	 * This type must be big enough to contain at least 32 bits.
	 */
	typedef uint_fast32_t crc_t;


	/**
	 * Calculate the initial crc value.
	 *
	 * \return     The initial crc value.
	 */
	static constexpr crc_t crc_init()
	{
	    return 0xffffffff;
	}


	/**
	 * Update the crc value with new data.
	 *
	 * \param[in] crc      The current crc value.
	 * \param[in] data     Pointer to a buffer of \a data_len bytes.
	 * \param[in] data_len Number of bytes in the \a data buffer.
	 * \return             The updated crc value.
	 */
	static crc_t crc_update(crc_t crc, const void *data, size_t data_len);


	/**
	 * Calculate the final crc value.
	 *
	 * \param[in] crc  The current crc value.
	 * \return     The final crc value.
	 */
	static constexpr crc_t crc_finalize(crc_t crc)
	{
	    return crc ^ 0xffffffff;
	}


protected:
	static const crc_t crc_table[256];

};
