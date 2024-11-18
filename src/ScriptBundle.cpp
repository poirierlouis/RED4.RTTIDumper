#include <stdafx.hpp>
#include "ScriptBundle.hpp"
#include "FileSystem.hpp"

constexpr uint32_t ScriptBundle_ctor = 3991604425;
constexpr uint32_t ScriptBundle_dtor = 3993832650;
constexpr uint32_t ScriptBundle_Read = 3761639893;
constexpr uint32_t ScriptBundle_Validate = 3482458695;

RED4ext::ScriptBundle::ScriptBundle()
{
    using func_t = void (*)(ScriptBundle*);
    static UniversalRelocFunc<func_t> func(ScriptBundle_ctor);
    func(this);
}

RED4ext::ScriptBundle::~ScriptBundle()
{
    using func_t = void (*)(ScriptBundle*);
    static UniversalRelocFunc<func_t> func(ScriptBundle_dtor);
    func(this);
}

bool RED4ext::ScriptBundle::Read(const CString& aPath)
{
    auto file = FileSystem::Get()->Open(aPath, 1);
    if (file)
    {
        using func_t = bool (*)(ScriptBundle*, uint64_t);
        static UniversalRelocFunc<func_t> func(ScriptBundle_Read);
        return func(this, file.ptr);
    }
    else
    {
        return false;
    }
}

RED4ext::DynArray<RED4ext::ScriptDefinition*> RED4ext::ScriptBundle::Collect(bool aDeep) const
{
    DynArray<ScriptDefinition*> definitions;

    for (auto* func : globals)
    {
        definitions.PushBack(func);

        if (aDeep)
        {
            for (auto* param : func->params)
                definitions.PushBack(param);

            for (auto* local : func->localVars)
                definitions.PushBack(local);
        }
    }

    for (auto* type : enums)
    {
        definitions.PushBack(type);
    }

    for (auto* type : bitfields)
    {
        definitions.PushBack(type);
    }

    for (auto* type : classes)
    {
        definitions.PushBack(type);

        if (aDeep)
        {
            for (auto* prop : type->properties)
                definitions.PushBack(prop);

            for (auto* prop : type->overrides)
                definitions.PushBack(prop);

            for (auto* func : type->functions)
            {
                definitions.PushBack(func);

                for (auto* param : func->params)
                    definitions.PushBack(param);

                for (auto* local : func->localVars)
                    definitions.PushBack(local);
            }
        }
    }

    for (auto* type : types)
    {
        definitions.PushBack(type);
    }

    return definitions;
}
