/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/cdc_screen/CDCViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

CDCViewBase::CDCViewBase() :
    buttonCallback(this, &CDCViewBase::buttonCallbackHandler),
    sliderValueChangedCallback(this, &CDCViewBase::sliderValueChangedCallbackHandler)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(box1);

    BackButton.setXY(700, 14);
    BackButton.setBitmaps(touchgfx::Bitmap(BITMAP_BLUISH3_ID), touchgfx::Bitmap(BITMAP_BLUISH3_ID));
    BackButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_NOPS));
    BackButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    BackButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    BackButton.setAction(buttonCallback);
    add(BackButton);

    textArea1.setXY(9, 0);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_F65W));
    add(textArea1);

    slider1.setXY(62, 383);
    slider1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_LARGE_SLIDER_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_LARGE_SLIDER_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_LARGE_INDICATORS_SLIDER_ROUND_NOB_ID));
    slider1.setupHorizontalSlider(2, 22, 0, 0, 621);
    slider1.setValueRange(0, 100);
    slider1.setValue(20);
    slider1.setNewValueCallback(sliderValueChangedCallback);
    add(slider1);

    textArea2.setPosition(230, 295, 189, 31);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UR6E));
    add(textArea2);

    USBCDCSliderValue.setPosition(432, 295, 75, 31);
    USBCDCSliderValue.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    USBCDCSliderValue.setLinespacing(0);
    Unicode::snprintf(USBCDCSliderValueBuffer, USBCDCSLIDERVALUE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_U8LF).getText());
    USBCDCSliderValue.setWildcard(USBCDCSliderValueBuffer);
    USBCDCSliderValue.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XSJ9));
    add(USBCDCSliderValue);

    imageProgress1.setXY(516, 200);
    imageProgress1.setProgressIndicatorPosition(2, 2, 180, 16);
    imageProgress1.setRange(0, 100);
    imageProgress1.setDirection(touchgfx::AbstractDirectionProgress::RIGHT);
    imageProgress1.setBackground(touchgfx::Bitmap(BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_PROGRESS_INDICATOR_BG_SQUARE_0_DEGREES_ID));
    imageProgress1.setBitmap(BITMAP_BLUE_PROGRESSINDICATORS_FILL_TILING_PROGRESS_INDICATOR_FILL_GRADIENT_NORMAL_HORIZONTAL_ID);
    imageProgress1.setValue(20);
    imageProgress1.setAnchorAtZero(false);
    add(imageProgress1);

    circleProgress1.setXY(76, 168);
    circleProgress1.setProgressIndicatorPosition(0, 0, 104, 104);
    circleProgress1.setRange(0, 100);
    circleProgress1.setCenter(52, 52);
    circleProgress1.setRadius(50);
    circleProgress1.setLineWidth(0);
    circleProgress1.setStartEndAngle(0, 360);
    circleProgress1.setBackground(touchgfx::Bitmap(BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_CIRCLE_INDICATOR_BG_FULL_ID));
    circleProgress1Painter.setColor(touchgfx::Color::getColorFromRGB(235, 25, 25));
    circleProgress1.setPainter(circleProgress1Painter);
    circleProgress1.setValue(20);
    add(circleProgress1);

    boxProgress1.setXY(275, 200);
    boxProgress1.setProgressIndicatorPosition(2, 2, 180, 16);
    boxProgress1.setRange(0, 100);
    boxProgress1.setDirection(touchgfx::AbstractDirectionProgress::RIGHT);
    boxProgress1.setBackground(touchgfx::Bitmap(BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_PROGRESS_INDICATOR_BG_SQUARE_0_DEGREES_ID));
    boxProgress1.setColor(touchgfx::Color::getColorFromRGB(61, 226, 85));
    boxProgress1.setValue(80);
    add(boxProgress1);
}

CDCViewBase::~CDCViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void CDCViewBase::setupScreen()
{

}

void CDCViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &BackButton)
    {
        //GoToSelect
        //When BackButton clicked change screen to Select
        //Go to Select with no screen transition
        application().gotoSelectScreenNoTransition();
    }
}

void CDCViewBase::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider1)
    {
        //USBCDCSendSliderValue
        //When slider1 value changed call virtual function
        //Call USBCDCSendSliderValue
        USBCDCSendSliderValue(value);
        //CircleProgress
        //When slider1 value changed execute C++ code
        //Execute C++ code
        circleProgress1.setValue(value);
        //BoxProgess
        //When slider1 value changed execute C++ code
        //Execute C++ code
        boxProgress1.setValue(100-value);
        //Interaction1
        //When slider1 value changed execute C++ code
        //Execute C++ code
        imageProgress1.setValue(value);
    }
}