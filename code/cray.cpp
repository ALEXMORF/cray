#include "cray.h"

internal void
RunCRay(app_memory Memory)
{
    ASSERT(sizeof(cray) <= Memory.Size);
    cray *CRay = (cray *)Memory.Data;
    
    if (!Memory.IsInitialized)
    {
        
        Memory.IsInitialized = true;
    }
}