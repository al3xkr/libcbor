/*
 * Copyright (c) 2014-2017 Pavel Kalvoda <me@pavelkalvoda.com>
 *
 * libcbor is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef LIBCBOR_MEMORY_UTILS_H
#define LIBCBOR_MEMORY_UTILS_H

#include <string.h>
#include <stdbool.h>

/** Can a and b be multiplied without overflowing size_t? */
bool _cbor_safe_to_multiply(size_t a, size_t b);

/** Overflow-proof contiguous array allocation
 *
 * @param item_size
 * @param item_count
 * @return Region of item_size * item_count bytes, or NULL if the total size overflows size_t or the underlying allocator failed
 */
void * _cbor_alloc_multiple(size_t item_size, size_t item_count);


/** Overflow-proof contiguous array reallocation
 *
 * This implements the OpenBSD `reallocarray` functionality.
 *
 * @param pointer
 * @param item_size
 * @param item_count
 * @return Realloc'd of item_size * item_count bytes, or NULL if the total size overflows size_t or the underlying allocator failed
 */
void * _cbor_realloc_multiple(void * pointer, size_t item_size, size_t item_count);

#endif //LIBCBOR_MEMORY_UTILS_H
