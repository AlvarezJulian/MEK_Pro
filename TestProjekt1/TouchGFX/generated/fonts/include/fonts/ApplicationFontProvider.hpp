/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
#define TOUCHGFX_APPLICATIONFONTPROVIDER_HPP

#include <touchgfx/FontManager.hpp>

namespace touchgfx
{
class FlashDataReader;
}

struct Typography
{
    static const touchgfx::FontId LARGE = 0;
    static const touchgfx::FontId DEFAULT = 1;
    static const touchgfx::FontId MEDIUM = 2;
    static const touchgfx::FontId VERYBIG = 3;
    static const touchgfx::FontId BIGGER = 4;
    static const touchgfx::FontId SMALL = 5;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId LARGE = 0;   // verdana_40_4bpp
    static const touchgfx::FontId DEFAULT = 1; // verdana_20_4bpp
    static const touchgfx::FontId MEDIUM = 2;  // verdana_25_4bpp
    static const touchgfx::FontId VERYBIG = 3; // verdanab_60_4bpp
    static const touchgfx::FontId BIGGER = 4;  // verdana_60_4bpp
    static const touchgfx::FontId SMALL = 5;   // verdana_10_4bpp
    static const uint16_t NUMBER_OF_FONTS = 6;
};

class ApplicationFontProvider : public touchgfx::FontProvider
{
public:
    virtual touchgfx::Font* getFont(touchgfx::FontId typography);

    static void setFlashReader(touchgfx::FlashDataReader* /*flashReader*/)
    {
    }

    static touchgfx::FlashDataReader* getFlashReader()
    {
        return 0;
    }
};

#endif // TOUCHGFX_APPLICATIONFONTPROVIDER_HPP