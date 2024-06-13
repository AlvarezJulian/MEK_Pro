/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) // Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

// Default TypedTextDatabase
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x47, 0x50, 0x49, 0x4f, 0x20, 0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x47, 0x50, 0x49, 0x4f, 0x20, 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x47, 0x50, 0x49, 0x4f, 0x20, 0x34, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x47, 0x50, 0x49, 0x4f, 0x20, 0x35, 0x20, 0x20, 0x20, 0x20, 0x0, // @0 "GPIO 0          GPIO 1                    GPIO 4                GPIO 5    "
    0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x0, // @75 "=============================="
    0x44, 0x69, 0x73, 0x61, 0x62, 0x6c, 0x65, 0x20, 0x41, 0x75, 0x74, 0x6f, 0x6d, 0x61, 0x74, 0x69, 0x63, 0x20, 0x52, 0x65, 0x61, 0x64, 0x21, 0x0, // @106 "Disable Automatic Read!"
    0x47, 0x50, 0x49, 0x4f, 0x20, 0x31, 0x20, 0x77, 0x61, 0x73, 0x20, 0x70, 0x75, 0x6c, 0x6c, 0x65, 0x64, 0x20, 0x4c, 0x4f, 0x57, 0x0, // @130 "GPIO 1 was pulled LOW"
    0x4e, 0x4f, 0x54, 0x20, 0x49, 0x4d, 0x50, 0x4c, 0x45, 0x4d, 0x45, 0x4e, 0x54, 0x45, 0x44, 0x20, 0x59, 0x45, 0x54, 0x0, // @152 "NOT IMPLEMENTED YET"
    0x38, 0x30, 0x30, 0x20, 0x78, 0x20, 0x34, 0x38, 0x30, 0x20, 0x45, 0x76, 0x61, 0x4b, 0x69, 0x74, 0x0, // @172 "800 x 480 EvaKit"
    0x53, 0x6c, 0x69, 0x64, 0x65, 0x72, 0x20, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3a, 0x0, // @189 "Slider Position:"
    0x20, 0x2, 0x20, 0x44, 0x65, 0x67, 0x2e, 0x20, 0x43, 0x0, // @206 " <> Deg. C"
    0x43, 0x6f, 0x6e, 0x74, 0x69, 0x6e, 0x75, 0x6f, 0x75, 0x73, 0x20, 0x52, 0x65, 0x61, 0x64, 0x0, // @216 "Continuous Read"
    0x47, 0x50, 0x49, 0x4f, 0x20, 0x53, 0x63, 0x72, 0x65, 0x65, 0x6e, 0x20, 0x20, 0x0, // @232 "GPIO Screen  "
    0x53, 0x65, 0x6c, 0x65, 0x63, 0x74, 0x20, 0x53, 0x63, 0x72, 0x65, 0x65, 0x6e, 0x0, // @246 "Select Screen"
    0x43, 0x6f, 0x6d, 0x70, 0x69, 0x6c, 0x65, 0x20, 0x64, 0x61, 0x74, 0x65, 0x0, // @260 "Compile date"
    0x52, 0x53, 0x32, 0x33, 0x32, 0x20, 0x53, 0x63, 0x72, 0x65, 0x65, 0x6e, 0x0, // @273 "RS232 Screen"
    0x52, 0x53, 0x34, 0x38, 0x35, 0x20, 0x53, 0x63, 0x72, 0x65, 0x65, 0x6e, 0x0, // @286 "RS485 Screen"
    0x41, 0x54, 0x20, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x3a, 0x0, // @299 "AT version:"
    0x4d, 0x61, 0x6e, 0x75, 0x61, 0x6c, 0x20, 0x52, 0x65, 0x61, 0x64, 0x0, // @311 "Manual Read"
    0x54, 0x65, 0x73, 0x74, 0x20, 0x47, 0x50, 0x49, 0x4f, 0x20, 0x34, 0x0, // @323 "Test GPIO 4"
    0x43, 0x41, 0x4e, 0x20, 0x53, 0x63, 0x72, 0x65, 0x65, 0x6e, 0x0, // @335 "CAN Screen"
    0x43, 0x44, 0x43, 0x20, 0x53, 0x63, 0x72, 0x65, 0x65, 0x6e, 0x0, // @346 "CDC Screen"
    0x49, 0x32, 0x43, 0x20, 0x53, 0x63, 0x72, 0x65, 0x65, 0x6e, 0x0, // @357 "I2C Screen"
    0x44, 0x65, 0x73, 0x69, 0x67, 0x6e, 0x65, 0x72, 0x3a, 0x0, // @368 "Designer:"
    0x52, 0x65, 0x61, 0x64, 0x20, 0x4f, 0x6e, 0x63, 0x65, 0x0, // @378 "Read Once"
    0x2, 0x25, 0x0, // @388 "<>%"
    0x50, 0x72, 0x6f, 0x6a, 0x65, 0x63, 0x74, 0x3a, 0x0, // @391 "Project:"
    0x56, 0x34, 0x2e, 0x31, 0x36, 0x20, 0x75, 0x70, 0x0, // @400 "V4.16 up"
    0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x3a, 0x0, // @409 "Version:"
    0x2, 0x0, // @418 "<>"
    0x55, 0x53, 0x42, 0x20, 0x43, 0x44, 0x43, 0x0, // @420 "USB CDC"
    0x55, 0x53, 0x42, 0x20, 0x48, 0x49, 0x44, 0x0, // @428 "USB HID"
    0x52, 0x65, 0x6d, 0x6f, 0x74, 0x65, 0x0, // @436 "Remote"
    0x56, 0x31, 0x2e, 0x36, 0x2e, 0x30, 0x0, // @443 "V1.6.0"
    0x34, 0x2e, 0x58, 0x2e, 0x58, 0x0, // @450 "4.X.X"
    0x44, 0x61, 0x74, 0x65, 0x3a, 0x0, // @456 "Date:"
    0x4c, 0x6f, 0x63, 0x61, 0x6c, 0x0, // @462 "Local"
    0x52, 0x53, 0x32, 0x33, 0x32, 0x0, // @468 "RS232"
    0x52, 0x53, 0x34, 0x38, 0x35, 0x0, // @474 "RS485"
    0x53, 0x74, 0x61, 0x72, 0x74, 0x0, // @480 "Start"
    0x42, 0x61, 0x63, 0x6b, 0x0, // @486 "Back"
    0x47, 0x50, 0x49, 0x4f, 0x0, // @491 "GPIO"
    0x49, 0x4e, 0x46, 0x4f, 0x0, // @496 "INFO"
    0x31, 0x30, 0x30, 0x0, // @501 "100"
    0x43, 0x41, 0x4e, 0x0, // @505 "CAN"
    0x49, 0x32, 0x43, 0x0, // @509 "I2C"
    0x53, 0x50, 0x49, 0x0, // @513 "SPI"
    0x32, 0x30, 0x0, // @517 "20"
    0x35, 0x30, 0x0, // @520 "50"
    0x38, 0x30, 0x0, // @523 "80"
    0x4f, 0x4b, 0x0, // @526 "OK"
    0x33, 0x0, // @529 "3"
    0x38, 0x0 // @531 "8"
};

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const uint32_t indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

// Array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

// Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            // Dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            // Compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
