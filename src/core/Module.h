#pragma once

#include "Config.h"

class Module
{
public:
    Module() = default;
    virtual ~Module() = default;

    Module(const Module &) = delete;
    Module &operator=(const Module &) = delete;

    static bool IsModuleLoaded(const char *moduleName);
    static Module *GetModule(const char *moduleName);
    static Module *LoadModule(const char *moduleName);
};

typedef Module *(*PF_CreateModule)();

#if defined(MONOLITHIC_BINARY)
#define IMPLEMENT_MODULE(MODULE) \
    extern "C"                   \
    {                            \
        Module *CreateModule()   \
        {                        \
            return new MODULE(); \
        }                        \
    }

#else

#define IMPLEMENT_MODULE(MODULE) \
    extern "C"                   \
    {                            \
        Module *CreateModule()   \
        {                        \
            return new MODULE(); \
        }                        \
    }

#endif