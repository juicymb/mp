#pragma once

//hapus ini jika sudah selesai test
#define BMOD_NO_LOGIN

#define JSON_NO_IO
#include <stdio.h>
#include <jni.h>
#include <string.h>

#define BMOD_GET_KEY_URL "https://t.me/HEFUNHAX"

#define BMOD_MENU_VERSION 1.0f
#define BMOD_BRANCH_VERSION ""
#define BMOD_MENU_URL_TG "https://t.me/HEFUNHAX"
#define BMOD_MENU_URL_YT "https://t.me/HEFUNHAX"

#define BModMenu_WindowTitle "FunHax - PlugIn"
#define BModMenu_WindowSubTitle "Mobile Legends : Bang Bang"

#define BMOD_MENU_WINDOW_GRADIENT

// 8 DIGIT HEX
#ifdef BMOD_MENU_WINDOW_GRADIENT
#define BModMenu_WindowBackground \
    (int[]) { 0xCC2B4261, 0xCC2B4261, 0xCC4E6C9C, 0xCC2B4261 }
#else
#define BModMenu_WindowBackground 0xCC2B4261
#endif

#define BModMenu_WindowWidth 305
#define BModMenu_WindowHeight 245
#define BModMenu_WindowBorderSize 1
#define BModMenu_WindowBorderRadius 6.0f

#ifdef BMOD_MENU_WINDOW_GRADIENT
#define BModMenu_WindowBorderColor BModMenu_WindowBackground[2]
#else
#define BModMenu_WindowBorderColor 0xCC4E6C9C
#endif

#define BModMenu_MainTextColor 0xD9FFFFFF
#define BModMenu_FontSizeSmall 10.0f
#define BModMenu_FontSizeMedium 12.0f
#define BModMenu_FontSizeLarge 14.0f

#define BModMenu_IconSize 45

#define BModMenu_TogleColor \
    (int[]) { -13145178, -13145178, -13145178, -12615734 }
#define BModMenu_TogleCornerRadius 6.0f
#define BModMenu_TogleStrokeColor -11892026

#define BModMenu_SliderThumbColor 0xD9FFFFFF
#define BModMenu_SliderProgressColor -12615734

namespace BMod
{
    extern int IsLogin; //
    bool InitMenu(JavaVM *vm);
    void SetInitCallbackFunction(void (*callback)());
    void SetWidgetCallback(void (*callback)(int, bool, int));
    void AddToggle(int, const char *);
    void AddSlider(int, const char *, int);
    void AddCategory(const char *);
	void AddRadioButton(int,const char *,const char*);
	void Toast(const char *,int);
}
