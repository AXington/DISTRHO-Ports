/*
 * Carla shared memory utils
 * Copyright (C) 2013-2014 Filipe Coelho <falktx@falktx.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * For a full copy of the GNU General Public License see the doc/GPL.txt file.
 */

#ifndef CARLA_SHM_UTILS_HPP_INCLUDED
#define CARLA_SHM_UTILS_HPP_INCLUDED

#include "CarlaUtils.hpp"

#ifdef CARLA_OS_WIN
struct shm_t { HANDLE shm; HANDLE map; };
#else
# include <fcntl.h>
# include <sys/mman.h>
typedef int shm_t;
#endif

#ifdef CARLA_OS_WIN
static shm_t gNullCarlaShm = { nullptr, nullptr };
#else
static shm_t gNullCarlaShm = -1;
#endif

// -----------------------------------------------------------------------
// shared memory calls

static inline
bool carla_is_shm_valid(const shm_t& shm) noexcept
{
#ifdef CARLA_OS_WIN
    return (shm.shm != nullptr && shm.shm != INVALID_HANDLE_VALUE);
#else
    return (shm >= 0);
#endif
}

static inline
void carla_shm_init(shm_t& shm) noexcept
{
#ifdef CARLA_OS_WIN
    shm.shm = nullptr;
    shm.map = nullptr;
#else
    shm = -1;
#endif
}

#ifdef CARLA_OS_WIN
static inline
shm_t carla_shm_create(const char* const name)
{
    CARLA_SAFE_ASSERT_RETURN(name != nullptr && name[0] != '\0', gNullCarlaShm);

    shm_t ret;
    ret.shm = nullptr; // TODO
    ret.map = nullptr;

    return ret;
}

static inline
shm_t carla_shm_attach(const char* const name)
{
    CARLA_SAFE_ASSERT_RETURN(name != nullptr && name[0] != '\0', gNullCarlaShm);

    shm_t ret;
    ret.shm = CreateFileA(name, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    ret.map = nullptr;

    return ret;
}
#else
static inline
shm_t carla_shm_create(const char* const name)
{
    CARLA_SAFE_ASSERT_RETURN(name != nullptr && name[0] != '\0', gNullCarlaShm);

    return shm_open(name, O_RDWR|O_CREAT|O_EXCL, 0600);
}

static inline
shm_t carla_shm_attach(const char* const name)
{
    CARLA_SAFE_ASSERT_RETURN(name != nullptr && name[0] != '\0', gNullCarlaShm);

    return shm_open(name, O_RDWR, 0);
}
#endif

static inline
void carla_shm_close(shm_t& shm)
{
    CARLA_SAFE_ASSERT_RETURN(carla_is_shm_valid(shm),);

#ifdef CARLA_OS_WIN
    CARLA_SAFE_ASSERT(shm.map == nullptr);

    CloseHandle(shm.shm);
    shm.shm = nullptr;
#else
    close(shm);
    shm = -1;
#endif
}

static inline
void* carla_shm_map(shm_t& shm, const size_t size)
{
    CARLA_SAFE_ASSERT_RETURN(carla_is_shm_valid(shm), nullptr);
    CARLA_SAFE_ASSERT_RETURN(size > 0, nullptr);

#ifdef CARLA_OS_WIN
    CARLA_SAFE_ASSERT_RETURN(shm.map == nullptr, nullptr);

    HANDLE map = CreateFileMapping(shm.shm, NULL, PAGE_READWRITE, size, size, NULL);

    CARLA_SAFE_ASSERT_RETURN(map != nullptr, nullptr);

    HANDLE ptr = MapViewOfFile(map, FILE_MAP_COPY, 0, 0, size);

    if (ptr == nullptr)
    {
        CloseHandle(map);
        return nullptr;
    }

    shm.map = map;

    return ptr;
#else
    if (ftruncate(shm, static_cast<off_t>(size)) != 0)
        return nullptr;

    return mmap(nullptr, size, PROT_READ|PROT_WRITE, MAP_SHARED, shm, 0);
#endif
}

static inline
void carla_shm_unmap(shm_t& shm, void* const ptr, const size_t size)
{
    CARLA_SAFE_ASSERT_RETURN(carla_is_shm_valid(shm),);
    CARLA_SAFE_ASSERT_RETURN(ptr != nullptr,);
    CARLA_SAFE_ASSERT_RETURN(size > 0,);

#ifdef CARLA_OS_WIN
    CARLA_SAFE_ASSERT_RETURN(shm.map != nullptr,);

    UnmapViewOfFile(ptr);
    CloseHandle(shm.map);
    shm.map = nullptr;
    return;

    // unused
    (void)size;
#else
    munmap(ptr, size);
    return;

    // unused
    (void)shm;
#endif
}

// -----------------------------------------------------------------------
// shared memory, templated calls

template<typename T>
static inline
bool carla_shm_map(shm_t& shm, T*& value)
{
    value = (T*)carla_shm_map(shm, sizeof(T));
    return (value != nullptr);
}

template<typename T>
static inline
void carla_shm_unmap(shm_t& shm, T*& value)
{
    carla_shm_unmap(shm, value, sizeof(T));
    value = nullptr;
}

// -----------------------------------------------------------------------

#endif // CARLA_SHM_UTILS_HPP_INCLUDED
