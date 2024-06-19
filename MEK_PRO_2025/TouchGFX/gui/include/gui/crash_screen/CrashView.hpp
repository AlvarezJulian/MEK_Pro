#ifndef CRASHVIEW_HPP
#define CRASHVIEW_HPP

#include <gui_generated/crash_screen/CrashViewBase.hpp>
#include <gui/crash_screen/CrashPresenter.hpp>

class CrashView : public CrashViewBase
{
public:
    CrashView();
    virtual ~CrashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CRASHVIEW_HPP
