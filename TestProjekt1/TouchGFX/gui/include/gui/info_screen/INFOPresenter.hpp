#ifndef INFO_PRESENTER_HPP
#define INFO_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class INFOView;

class INFOPresenter : public Presenter, public ModelListener
{
public:
    INFOPresenter(INFOView& v);

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

    virtual ~INFOPresenter() {};

private:
    INFOPresenter();

    INFOView& view;
};


#endif // INFO_PRESENTER_HPP
