
#include "Module.h"
#include <string>
#include <map>
#include <memory>
#include <dlfcn.h>

namespace
{
struct ModuleMeta
{
    Module *module;
    void *handle;
    
    ModuleMeta(Module *module, void *handle) : module(module), handle(handle)
    {
    }

    ModuleMeta(ModuleMeta &&m)
    {
        handle = m.handle;
        module = m.module;

        m.handle = nullptr;
        m.module = nullptr;
    }

    ~ModuleMeta()
    {
        if (handle)
        {
            if (module)
            {
                delete module;
            }
            ::dlclose(handle);
        }
    }
};

typedef std::map<std::string, ModuleMeta> ModuleMap;
ModuleMap loadedModules;

void _LoadModule(const char *name, void **handle, Module **module)
{
    auto realName = "lib" + std::string(name) + "D.dylib";

    /* Open macOS dynamic library */
    auto _handle = dlopen(realName.c_str(), RTLD_LAZY);
    if (!_handle)
        throw std::runtime_error("failed to load dynamic library (DYLIB): \"" + std::string(name) + "\"");

    auto pfCreateModule = reinterpret_cast<PF_CreateModule>(dlsym(_handle, "CreateModule"));

    *handle = _handle;
    *module = pfCreateModule();
}

} // namespace

Module *Module::LoadModule(const char *name)
{
    auto iter = loadedModules.find(std::string(name));
    if (iter != loadedModules.end())
    {
        return iter->second.module;
    }

    Module *module;
    void *handle;
    _LoadModule(name, &handle, &module);

    loadedModules.emplace(std::string(name), ModuleMeta{module, handle});
    return module;
}
