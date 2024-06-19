#ifndef STARTPRESENTER_HPP
#define STARTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class StartView;

class StartPresenter: public touchgfx::Presenter, public ModelListener {
public:
	StartPresenter(StartView &v);

	/**
	 * The activate function is called automatically when this screen is "switched in"
	 * (ie. made active). Initialization logic can be placed here.
	 */

	/**
	 * The deactivate function is called automatically when this screen is "switched out"
	 * (ie. made inactive). Teardown functionality can be placed here.
	 */
	virtual void deactivate();
	virtual void activate();
#ifndef SIMULATOR
//	virtual void CANReceived(uint8_t *data);
	virtual void Start_User_ID_Received(uint8_t *data);
	virtual void Start_Status_LOGIN_Received();
	virtual void Start_Status_LOGOUT_Received();
	virtual void Start_Change_Language_Received(uint8_t index);

#endif
	virtual ~StartPresenter() {
	}

private:
	StartPresenter();

	StartView &view;
};

#endif // STARTPRESENTER_HPP
