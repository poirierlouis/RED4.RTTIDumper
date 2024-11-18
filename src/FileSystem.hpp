#pragma once

#include <cstdint>
#include "RED4ext/CString.hpp"
#include "Raw.hpp"

namespace RED4ext
{
struct FileHandle
{
    ~FileHandle();

    operator bool() const noexcept
    {
        return ptr;
    }

    uint64_t ptr; // 00
};

struct FileSystem
{
    virtual ~FileSystem() = 0;                                  // 00
    virtual FileHandle Open(CString aPath, uint8_t aFlags) = 0; // 08

    static FileSystem* Get();
};
}

namespace Raw::FileSystem
{
constexpr uint32_t FileSystem_Instance = 3788966949;
constexpr uint32_t FileSystem_Close = 633872857;

constexpr auto Instance = RED4ext::RawPtr<
    /* addr = */ FileSystem_Instance,
    /* type = */ RED4ext::FileSystem*>();

constexpr auto Close = RED4ext::RawFunc<
    /* addr = */ FileSystem_Close,
    /* type = */ void (*)(RED4ext::FileHandle* aHandle)>();
}
