#include <Includes/obfuscate.h>
#define enc(str) OBFUSCATE(str)
#include <jni/API.h>
#include "bmod.h"
#include <jni/Proxy.h>
#include <json.hpp>

#define BMOD_SIZE(_ARR) ((int)(sizeof(_ARR) / sizeof(*(_ARR))))

struct BModMenu;
BModMenu *GBModMenu = NULL;

static void (*bmod_init_callback)() = 0;
static void (*bmod_widget_callback)(int, bool, int) = 0;

void BMod::SetInitCallbackFunction(void (*callback)())
{
    bmod_init_callback = callback;
}

void BMod::SetWidgetCallback(void (*callback)(int, bool, int))
{
    bmod_widget_callback = callback;
}

struct BModMenu
{
public:
    android::widget::RelativeLayout LayoutContainer;
    android::widget::LinearLayout LayoutWindow;
    android::widget::LinearLayout LayoutMenuWrap;
    android::widget::LinearLayout LayoutMenu;
    android::widget::LinearLayout LayoutLogin;
    android::widget::LinearLayout Icon;
    android::app::Activity Activity;
    bool IsLogin = false;
    BModMenu(android::app::Activity activity) : Activity(activity),
                                                LayoutContainer(activity), LayoutWindow(activity),
                                                LayoutMenu(activity), LayoutLogin(activity), LayoutMenuWrap(activity), Icon(activity)
    {
        InitBaseView();
    }

private:
    void InitBaseView();
    void InitLoginView();
    void InitLayoutHeader();
    void InitLayoutFooter();
    int dp(int value)
    {
        return (int)android::util::TypedValue::ApplyDimension(1, (float)value,
                                                              Activity.GetResources().GetDisplayMetrics());
    }
    android::view::View DividerHorizontal()
    {
        android::view::View view = android::view::View(Activity);
        view.SetBackgroundColor(BModMenu_WindowBorderColor);
        view.SetLayoutParams(android::view::ViewGroup_LayoutParams(-1, 1));
        return view;
    }
};

static struct BModMenuOpenLinkListener : jni::Proxy<android::view::View_OnClickListener,
                                                    java::lang::Runnable>
{
public:
    BModMenuOpenLinkListener(const char *str)
    {
        m_url = std::string(str);
    }

    void OpenUrl()
    {
        if (GBModMenu)
        {
            GBModMenu->Activity.RunOnUiThread(*this);
        }
    }

    virtual void OnClick(const android::view::View &view)
    {
        OpenUrl();
    }

    virtual void Run() { return DoOpenUrl(); }

private:
    std::string m_url;

    void DoOpenUrl()
    {
        auto intent = android::content::Intent();
        intent.SetAction(android::content::Intent::fACTION_VIEW());
        intent.SetData(android::net::Uri::Parse(m_url.c_str()));
        intent.SetFlags(0x10000000);
        GBModMenu->Activity.StartActivity(intent);
    }
};
