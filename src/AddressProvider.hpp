#pragma once

#include <RED4ext/RED4ext.hpp>
#include "AddressResolver.hpp"

namespace RED4ext
{
class AddressProvider : public AddressResolver
{
public:
    AddressProvider() noexcept;

    uintptr_t ResolveAddress(uint32_t aAddressID) override;
};
}
