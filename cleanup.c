/*
 * cleanup.c - Frees used memory by the game
 * Copyright 2012 Yifan Lu
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "cleanup.h"
#include "resolve.h"
#include "scefuncs.h"
#include "utils.h"

/********************************************//**
 *  \brief Free up the RAM
 *  
 *  Frees up memory used by the loaded game.
 *  \returns Zero on success, otherwise error
 ***********************************************/
int
uvl_cleanup_memory ()
{
    // close and delete all threads
    if (uvl_unload_all_modules () < 0)
    {
        LOG ("Failed to unload all modules.");
        return -1;
    }
    // free allocated memory
    // delete event flags, semaphors, mutexs, etc
    // close all file handles
}

/********************************************//**
 *  \brief Unloads loaded modules
 *  
 *  \returns Zero on success, otherwise error
 ***********************************************/
int
uvl_unload_all_modules ()
{
    loaded_module_info_t m_mod_info;
    PsvUID mod_list[MAX_LOADED_MODS];
    u32_t num_loaded = MAX_LOADED_MODS;
    int status;
    int i;

    if (sceKernelGetModuleList (0xFF, mod_list, &num_loaded) < 0)
    {
        LOG ("Failed to get module list.");
        return -1;
    }
    for (i = 0; i < num_loaded; i++)
    {
       if (sceKernelStopUnloadModule (mod_list[i], 0, NULL, &status, NULL) < 0)
       {
            LOG ("Failed to unload module %X, continuing...", mod_list[i]);
            continue;
       }
    }
    return 0;
}
