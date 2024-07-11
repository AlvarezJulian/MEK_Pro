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

	virtual void Start_User_ID_Received(char *data);
	virtual void Start_Status_LOGIN_OUT_Changed(bool state);
	virtual void Start_wifi_Signal_Changed(uint8_t val);
	virtual void Start_Bluetooth_Status_Changed(bool state);
	virtual void Start_LogIn_Time_Changed(int hour, int min, int sec);

	/*
	 * SET
	 */
	void SaveUserID(char *UserID) {
		model->setCurrentUserID(UserID);
	}
	void saveLogStatus(bool state) {
		model->SetLogStatus(state);
	}
	void saveWorkshopStatus(bool state) {
		model->SetWorkshopStatus(state);
	}
	void saveHour(uint16_t hour) {
		model->setCurrentHour(hour);
	}
	void saveMinute(uint16_t minute) {
		model->setCurrentMinute(minute);
	}
	void saveSecond(uint16_t second) {
		model->setCurrentSecond(second);
	}

	void saveLogHour(uint16_t hour) {
		model->SetLogHour(hour);
	}
	void saveLogMinute(uint16_t minute) {
		model->SetLogMinute(minute);
	}
	void saveLogSecond(uint16_t second) {
		model->SetLogSecond(second);
	}

	/*
	 * GET
	 */
	char* getUserId() {
		return model->getCurrentUserID();
	}
	bool getLogStatus() {
		return model->getLogStatus();
	}
	bool getWorkshopStatus() {
		return model->getWorkshopStatus();
	}
	int16_t getHour() {
		return model->getCurrentHour();
	}
	int16_t getMinute() {
		return model->getCurrentMinute();
	}
	int16_t getSecond() {
		return model->getCurrentSecond();
	}

	int16_t getLogHour() {
		return model->getLogHour();
	}
	int16_t getLogMinute() {
		return model->getLogMinute();
	}
	int16_t getLogSecond() {
		return model->getLogSecond();
	}

	virtual ~StartPresenter() {
	}
#endif // SIMULATOR
private:
	StartPresenter();

	StartView &view;
};

#endif // STARTPRESENTER_HPP
