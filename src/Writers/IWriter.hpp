#pragma once

#include "Types.hpp"
#include "ScriptBundle.hpp"

class IWriter
{
public:
    virtual ~IWriter() = default;

    virtual void CollectScripts(const RED4ext::ScriptBundle& aBundle) = 0;

    virtual void Write(Global& aGlobal) = 0;
    virtual void Write(std::shared_ptr<Class> aClass) = 0;
    virtual void Write(std::shared_ptr<Enum> aEnum) = 0;
    virtual void Write(std::shared_ptr<BitField> aBit) = 0;
    virtual void Flush() = 0;
};
