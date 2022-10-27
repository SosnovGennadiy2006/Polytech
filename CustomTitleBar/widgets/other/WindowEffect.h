//
// Created by Gennadiy Sosnov on 03.10.2022.
//

#ifndef POLYTECH_WINDOWEFFECT_H
#define POLYTECH_WINDOWEFFECT_H

#include "windows.h"
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")

namespace WindowEffect
{
    void moveWindow(HWND hWnd);
    void addShadowEffect(HWND hWnd);
    void removeShadowEffect(HWND hWnd);
    void removeMenuShadowEffect(HWND hWnd);
    void addWindowAnimation(HWND hWnd);
};

#endif//POLYTECH_WINDOWEFFECT_H
