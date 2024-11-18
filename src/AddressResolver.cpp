#include <stdafx.hpp>
#include <cassert>

#include "AddressResolver.hpp"

namespace
{
AddressResolver* s_default;
}

void AddressResolver::SetDefault(AddressResolver& aResolver)
{
    s_default = &aResolver;
}

AddressResolver& AddressResolver::GetDefault()
{
    assert(s_default);
    return *s_default;
}
