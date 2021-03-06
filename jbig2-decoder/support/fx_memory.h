// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef _FX_MEMORY_H_
#define _FX_MEMORY_H_
#ifndef _FX_SYSTEM_H_
#include "fx_system.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif
#define FX_Alloc(type, size)						(type*)calloc(size, sizeof(type))
#define FX_Realloc(type, ptr, size)					(type*)realloc(ptr, sizeof(type) * (size))
#define FX_AllocNL(type, size)						FX_Alloc(type, size)
#define FX_ReallocNL(type, ptr, size)				FX_Realloc(type, ptr, size)
#define FX_Free(ptr)								free(ptr)

#ifdef __cplusplus
}
#endif
#ifdef __cplusplus
class CFX_Object
{
public:
    void*			operator new (size_t size, FX_LPCSTR file, int line)
    {
        return malloc(size);
    }
    void			operator delete (void* p, FX_LPCSTR file, int line)
    {
        free(p);
    }
    void*			operator new (size_t size)
    {
        return malloc(size);
    }
    void			operator delete (void* p)
    {
        free(p);
    }
    void*			operator new[] (size_t size, FX_LPCSTR file, int line)
    {
        return malloc(size);
    }
    void			operator delete[] (void* p, FX_LPCSTR file, int line)
    {
        free(p);
    }
    void*			operator new[] (size_t size)
    {
        return malloc(size);
    }
    void			operator delete[] (void* p)
    {
        free(p);
    }
    void*			operator new (size_t, void* buf)
    {
        return buf;
    }
    void			operator delete (void*, void*)							{}
};
#endif
#endif
