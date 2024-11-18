#pragma once

#include "Types.hpp"
#include "Writers/IWriter.hpp"
#include "ScriptBundle.hpp"

class Dumper
{
public:
    Dumper(RED4ext::PluginHandle aHandle, const RED4ext::Sdk* aSdk);

    void Run(std::shared_ptr<IWriter> aWriter);

private:
    void CollectTypes();

    void CollectType(RED4ext::CBitfield* aEnum);
    void CollectType(RED4ext::CEnum* aEnum);

    void CollectType(RED4ext::CClass* aClass);
    void CollectStatics();

    void CollectScripts();

    void OrderFunctions();

    RED4ext::PluginHandle m_handle;
    const RED4ext::Sdk* m_sdk;

    Global m_global;
    RED4ext::ScriptBundle m_bundle;

    std::map<std::string, std::shared_ptr<BaseType>> m_types;
    RED4ext::DynArray<RED4ext::ScriptDefinition*> m_definitions;
};
