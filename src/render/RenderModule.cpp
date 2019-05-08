#include "RenderModule.h"

class RenderModule : public IRenderModule {
    
    virtual IRenderSystem* CreateRenderSystem(const char* name);
};

IMPLEMENT_MODULE(RenderModule)

IRenderSystem *RenderModule::CreateRenderSystem(const char *name)
{
    return nullptr;
}
