#include <stdafx.hpp>
#include "AddressProvider.hpp"

RED4ext::AddressProvider::AddressProvider() noexcept
{
    AddressResolver::SetDefault(*this);
}

uintptr_t RED4ext::AddressProvider::ResolveAddress(uint32_t aAddressID)
{
    return RED4ext::UniversalRelocBase::Resolve(aAddressID);
}
