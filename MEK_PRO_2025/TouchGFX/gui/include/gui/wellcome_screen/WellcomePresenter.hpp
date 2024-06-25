#ifndef WELLCOMEPRESENTER_HPP
#define WELLCOMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class WellcomeView;

class WellcomePresenter: public touchgfx::Presenter, public ModelListener {
public:
	WellcomePresenter(WellcomeView &v);

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
#ifndef SIMULATOR
//	virtual void Wellcome_ChangeWindow_Received(uint8_t index);
//	virtual void Wellcome_Change_Language_Received(uint8_t index);

#endif
	virtual ~WellcomePresenter() {
	}

private:
	WellcomePresenter();

	WellcomeView &view;
};

#endif // WELLCOMEPRESENTER_HPP
