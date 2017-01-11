#pragma once

#include "SandboxAPI.h"

class SANDBOX_API Engine
{
private:

public:
    /**
     * Initialize all essential components of the Sandbox engine
     */
    bool Initialize();

    void DoTests();
};