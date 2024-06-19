#ifndef CRASHPRESENTER_HPP
#define CRASHPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class CrashView;

class CrashPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    CrashPresenter(CrashView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~CrashPresenter() {}

private:
    CrashPresenter();

    CrashView& view;
};

#endif // CRASHPRESENTER_HPP
