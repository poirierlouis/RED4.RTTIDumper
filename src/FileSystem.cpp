#include <stdafx.hpp>
#include "FileSystem.hpp"

RED4ext::FileSystem* RED4ext::FileSystem::Get()
{
    return Raw::FileSystem::Instance;
}

RED4ext::FileHandle::~FileHandle()
{
    Raw::FileSystem::Close(this);
}
