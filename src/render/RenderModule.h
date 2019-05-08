#pragma once

#include "Module.h"

class IRenderSystem;

class IRenderModule : public Module
{
public:
    virtual IRenderSystem *CreateRenderSystem(const char *name) = 0;
};
