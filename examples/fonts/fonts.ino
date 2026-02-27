// NOTE: this test uses multiple font files of different sizes and produces a
// large binary. To deploy it to stock ESP32, you might need to use a
// non-standard partition table, e.g. huge_app.csv:
// https://github.com/espressif/arduino-esp32/blob/master/tools/partitions/huge_app.csv

// See
// https://docs.platformio.org/en/latest/platforms/espressif32.html#partition-tables
// for details.

#include "Arduino.h"

#ifdef ROO_TESTING

#include "roo_testing/devices/display/st77xx/st77xx.h"
#include "roo_testing/microcontrollers/esp32/fake_esp32.h"
#include "roo_testing/transducers/ui/viewport/flex_viewport.h"
#include "roo_testing/transducers/ui/viewport/fltk/fltk_viewport.h"

using roo_testing_transducers::FlexViewport;
using roo_testing_transducers::FltkViewport;

struct Emulator {
  FltkViewport viewport;
  FlexViewport flexViewport;

  FakeSt77xxSpi display;

  Emulator()
      : viewport(), flexViewport(viewport, 2), display(flexViewport, 240, 240) {
    FakeEsp32().attachSpiDevice(display, 18, 19, 23);
    FakeEsp32().gpio.attachOutput(5, display.cs());
    FakeEsp32().gpio.attachOutput(2, display.dc());
    FakeEsp32().gpio.attachOutput(4, display.rst());
  }
} emulator;

#endif

#include "roo_backport/string_view.h"
#include "roo_display.h"
#include "roo_display/ui/text_label.h"
#include "roo_fonts/NotoSansMono_Bold/10.h"
#include "roo_fonts/NotoSansMono_Bold/12.h"
#include "roo_fonts/NotoSansMono_Bold/15.h"
#include "roo_fonts/NotoSansMono_Bold/18.h"
#include "roo_fonts/NotoSansMono_Bold/27.h"
#include "roo_fonts/NotoSansMono_Bold/40.h"
#include "roo_fonts/NotoSansMono_Bold/60.h"
#include "roo_fonts/NotoSansMono_Bold/8.h"
#include "roo_fonts/NotoSansMono_Bold/90.h"
#include "roo_fonts/NotoSans_BoldItalic/10.h"
#include "roo_fonts/NotoSans_BoldItalic/12.h"
#include "roo_fonts/NotoSans_BoldItalic/15.h"
#include "roo_fonts/NotoSans_BoldItalic/18.h"
#include "roo_fonts/NotoSans_BoldItalic/27.h"
#include "roo_fonts/NotoSans_BoldItalic/40.h"
#include "roo_fonts/NotoSans_BoldItalic/60.h"
#include "roo_fonts/NotoSans_BoldItalic/8.h"
#include "roo_fonts/NotoSans_BoldItalic/90.h"
#include "roo_fonts/NotoSans_Condensed/10.h"
#include "roo_fonts/NotoSans_Condensed/12.h"
#include "roo_fonts/NotoSans_Condensed/15.h"
#include "roo_fonts/NotoSans_Condensed/18.h"
#include "roo_fonts/NotoSans_Condensed/27.h"
#include "roo_fonts/NotoSans_Condensed/40.h"
#include "roo_fonts/NotoSans_Condensed/60.h"
#include "roo_fonts/NotoSans_Condensed/8.h"
#include "roo_fonts/NotoSans_Condensed/90.h"
#include "roo_fonts/NotoSans_CondensedBold/10.h"
#include "roo_fonts/NotoSans_CondensedBold/12.h"
#include "roo_fonts/NotoSans_CondensedBold/15.h"
#include "roo_fonts/NotoSans_CondensedBold/18.h"
#include "roo_fonts/NotoSans_CondensedBold/27.h"
#include "roo_fonts/NotoSans_CondensedBold/40.h"
#include "roo_fonts/NotoSans_CondensedBold/60.h"
#include "roo_fonts/NotoSans_CondensedBold/8.h"
#include "roo_fonts/NotoSans_CondensedBold/90.h"
#include "roo_fonts/NotoSans_CondensedItalic/10.h"
#include "roo_fonts/NotoSans_CondensedItalic/12.h"
#include "roo_fonts/NotoSans_CondensedItalic/15.h"
#include "roo_fonts/NotoSans_CondensedItalic/18.h"
#include "roo_fonts/NotoSans_CondensedItalic/27.h"
#include "roo_fonts/NotoSans_CondensedItalic/40.h"
#include "roo_fonts/NotoSans_CondensedItalic/60.h"
#include "roo_fonts/NotoSans_CondensedItalic/8.h"
#include "roo_fonts/NotoSans_CondensedItalic/90.h"
#include "roo_fonts/NotoSans_Italic/10.h"
#include "roo_fonts/NotoSans_Italic/12.h"
#include "roo_fonts/NotoSans_Italic/15.h"
#include "roo_fonts/NotoSans_Italic/18.h"
#include "roo_fonts/NotoSans_Italic/27.h"
#include "roo_fonts/NotoSans_Italic/40.h"
#include "roo_fonts/NotoSans_Italic/60.h"
#include "roo_fonts/NotoSans_Italic/8.h"
#include "roo_fonts/NotoSans_Italic/90.h"
#include "roo_fonts/NotoSerif_Bold/10.h"
#include "roo_fonts/NotoSerif_Bold/12.h"
#include "roo_fonts/NotoSerif_Bold/15.h"
#include "roo_fonts/NotoSerif_Bold/18.h"
#include "roo_fonts/NotoSerif_Bold/27.h"
#include "roo_fonts/NotoSerif_Bold/40.h"
#include "roo_fonts/NotoSerif_Bold/60.h"
#include "roo_fonts/NotoSerif_Bold/8.h"
#include "roo_fonts/NotoSerif_Bold/90.h"
#include "roo_fonts/NotoSerif_BoldItalic/10.h"
#include "roo_fonts/NotoSerif_BoldItalic/12.h"
#include "roo_fonts/NotoSerif_BoldItalic/15.h"
#include "roo_fonts/NotoSerif_BoldItalic/18.h"
#include "roo_fonts/NotoSerif_BoldItalic/27.h"
#include "roo_fonts/NotoSerif_BoldItalic/40.h"
#include "roo_fonts/NotoSerif_BoldItalic/60.h"
#include "roo_fonts/NotoSerif_BoldItalic/8.h"
#include "roo_fonts/NotoSerif_BoldItalic/90.h"
#include "roo_fonts/NotoSerif_Condensed/10.h"
#include "roo_fonts/NotoSerif_Condensed/12.h"
#include "roo_fonts/NotoSerif_Condensed/15.h"
#include "roo_fonts/NotoSerif_Condensed/18.h"
#include "roo_fonts/NotoSerif_Condensed/27.h"
#include "roo_fonts/NotoSerif_Condensed/40.h"
#include "roo_fonts/NotoSerif_Condensed/60.h"
#include "roo_fonts/NotoSerif_Condensed/8.h"
#include "roo_fonts/NotoSerif_Condensed/90.h"
#include "roo_fonts/NotoSerif_CondensedItalic/10.h"
#include "roo_fonts/NotoSerif_CondensedItalic/12.h"
#include "roo_fonts/NotoSerif_CondensedItalic/15.h"
#include "roo_fonts/NotoSerif_CondensedItalic/18.h"
#include "roo_fonts/NotoSerif_CondensedItalic/27.h"
#include "roo_fonts/NotoSerif_CondensedItalic/40.h"
#include "roo_fonts/NotoSerif_CondensedItalic/60.h"
#include "roo_fonts/NotoSerif_CondensedItalic/8.h"
#include "roo_fonts/NotoSerif_CondensedItalic/90.h"
#include "roo_fonts/NotoSerif_Regular/10.h"
#include "roo_fonts/NotoSerif_Regular/12.h"
#include "roo_fonts/NotoSerif_Regular/15.h"
#include "roo_fonts/NotoSerif_Regular/18.h"
#include "roo_fonts/NotoSerif_Regular/27.h"
#include "roo_fonts/NotoSerif_Regular/40.h"
#include "roo_fonts/NotoSerif_Regular/60.h"
#include "roo_fonts/NotoSerif_Regular/8.h"
#include "roo_fonts/NotoSerif_Regular/90.h"

using namespace roo_display;

#include "roo_display/driver/st7789.h"
St7789spi_240x240<5, 2, 4> device;
Display display(device);

struct FontFamily {
  FontFamily(const Font& f8, const Font& f10, const Font& f12, const Font& f15,
             const Font& f18, const Font& f27, const Font& f40, const Font& f60,
             const Font& f90)
      : f8(f8),
        f10(f10),
        f12(f12),
        f15(f15),
        f18(f18),
        f27(f27),
        f40(f40),
        f60(f60),
        f90(f90) {}

  const Font& f8;
  const Font& f10;
  const Font& f12;
  const Font& f15;
  const Font& f18;
  const Font& f27;
  const Font& f40;
  const Font& f60;
  const Font& f90;
};

FontFamily notoSansItalic(font_NotoSans_Italic_8(), font_NotoSans_Italic_10(),
                          font_NotoSans_Italic_12(), font_NotoSans_Italic_15(),
                          font_NotoSans_Italic_18(), font_NotoSans_Italic_27(),
                          font_NotoSans_Italic_40(), font_NotoSans_Italic_60(),
                          font_NotoSans_Italic_90());

FontFamily notoSansBoldItalic(
    font_NotoSans_BoldItalic_8(), font_NotoSans_BoldItalic_10(),
    font_NotoSans_BoldItalic_12(), font_NotoSans_BoldItalic_15(),
    font_NotoSans_BoldItalic_18(), font_NotoSans_BoldItalic_27(),
    font_NotoSans_BoldItalic_40(), font_NotoSans_BoldItalic_60(),
    font_NotoSans_BoldItalic_90());

FontFamily notoSansCondensed(
    font_NotoSans_Condensed_8(), font_NotoSans_Condensed_10(),
    font_NotoSans_Condensed_12(), font_NotoSans_Condensed_15(),
    font_NotoSans_Condensed_18(), font_NotoSans_Condensed_27(),
    font_NotoSans_Condensed_40(), font_NotoSans_Condensed_60(),
    font_NotoSans_Condensed_90());

FontFamily notoSansCondensedBold(
    font_NotoSans_CondensedBold_8(), font_NotoSans_CondensedBold_10(),
    font_NotoSans_CondensedBold_12(), font_NotoSans_CondensedBold_15(),
    font_NotoSans_CondensedBold_18(), font_NotoSans_CondensedBold_27(),
    font_NotoSans_CondensedBold_40(), font_NotoSans_CondensedBold_60(),
    font_NotoSans_CondensedBold_90());

FontFamily notoSansCondensedItalic(
    font_NotoSans_CondensedItalic_8(), font_NotoSans_CondensedItalic_10(),
    font_NotoSans_CondensedItalic_12(), font_NotoSans_CondensedItalic_15(),
    font_NotoSans_CondensedItalic_18(), font_NotoSans_CondensedItalic_27(),
    font_NotoSans_CondensedItalic_40(), font_NotoSans_CondensedItalic_60(),
    font_NotoSans_CondensedItalic_90());

FontFamily notoSerifRegular(
    font_NotoSerif_Regular_8(), font_NotoSerif_Regular_10(),
    font_NotoSerif_Regular_12(), font_NotoSerif_Regular_15(),
    font_NotoSerif_Regular_18(), font_NotoSerif_Regular_27(),
    font_NotoSerif_Regular_40(), font_NotoSerif_Regular_60(),
    font_NotoSerif_Regular_90());

FontFamily notoSerifBold(font_NotoSerif_Bold_8(), font_NotoSerif_Bold_10(),
                         font_NotoSerif_Bold_12(), font_NotoSerif_Bold_15(),
                         font_NotoSerif_Bold_18(), font_NotoSerif_Bold_27(),
                         font_NotoSerif_Bold_40(), font_NotoSerif_Bold_60(),
                         font_NotoSerif_Bold_90());

FontFamily notoSerifBoldItalic(
    font_NotoSerif_BoldItalic_8(), font_NotoSerif_BoldItalic_10(),
    font_NotoSerif_BoldItalic_12(), font_NotoSerif_BoldItalic_15(),
    font_NotoSerif_BoldItalic_18(), font_NotoSerif_BoldItalic_27(),
    font_NotoSerif_BoldItalic_40(), font_NotoSerif_BoldItalic_60(),
    font_NotoSerif_BoldItalic_90());

FontFamily notoSerifCondensed(
    font_NotoSerif_Condensed_8(), font_NotoSerif_Condensed_10(),
    font_NotoSerif_Condensed_12(), font_NotoSerif_Condensed_15(),
    font_NotoSerif_Condensed_18(), font_NotoSerif_Condensed_27(),
    font_NotoSerif_Condensed_40(), font_NotoSerif_Condensed_60(),
    font_NotoSerif_Condensed_90());

FontFamily notoSerifCondensedItalic(
    font_NotoSerif_CondensedItalic_8(), font_NotoSerif_CondensedItalic_10(),
    font_NotoSerif_CondensedItalic_12(), font_NotoSerif_CondensedItalic_15(),
    font_NotoSerif_CondensedItalic_18(), font_NotoSerif_CondensedItalic_27(),
    font_NotoSerif_CondensedItalic_40(), font_NotoSerif_CondensedItalic_60(),
    font_NotoSerif_CondensedItalic_90());

FontFamily notoSansMonoBold(
    font_NotoSansMono_Bold_8(), font_NotoSansMono_Bold_10(),
    font_NotoSansMono_Bold_12(), font_NotoSansMono_Bold_15(),
    font_NotoSansMono_Bold_18(), font_NotoSansMono_Bold_27(),
    font_NotoSansMono_Bold_40(), font_NotoSansMono_Bold_60(),
    font_NotoSansMono_Bold_90());

int16_t printLn(DrawingContext& dc, const Font& font, int16_t x, int16_t y,
                roo::string_view text, Color color) {
  dc.draw(StringViewLabel(text, font, color, FillMode::kExtents), x,
          y + font.metrics().glyphYMax());
  return font.metrics().linespace() + 1;
}

void setup() {
  Serial.begin(115200);
  SPI.begin();
  display.init(color::Gainsboro);
}

int16_t printText(const char* family_name, const FontFamily& fonts) {
  DrawingContext dc(display);
  dc.fill(color::Gainsboro);
  const char* text = "Zażółć gęślą jaźń 12345.67890 !@#$%^&*()";
  Color color = color::Black;

  int16_t y = 1;
  dc.setBackgroundColor(color::Gainsboro);
  y += printLn(dc, fonts.f12, 4, y, family_name, color::Black);
  dc.setBackgroundColor(color::Beige);
  y += printLn(dc, fonts.f8, 10, y, text, color);
  dc.setBackgroundColor(color::PapayaWhip);
  y += printLn(dc, fonts.f10, 10, y, text, color);
  dc.setBackgroundColor(color::PowderBlue);
  y += printLn(dc, fonts.f12, 10, y, text, color);
  dc.setBackgroundColor(color::LightGreen);
  y += printLn(dc, fonts.f15, 10, y, text, color);
  dc.setBackgroundColor(color::MistyRose);
  y += printLn(dc, fonts.f18, 10, y, text, color);
  dc.setBackgroundColor(color::LemonChiffon);
  y += printLn(dc, fonts.f27, 10, y, text, color);
  dc.setBackgroundColor(color::Beige);
  y += printLn(dc, fonts.f40, 10, y, text, color);
  dc.setBackgroundColor(color::PapayaWhip);
  y += printLn(dc, fonts.f60, 10, y, text, color);
  dc.setBackgroundColor(color::PowderBlue);
  y += printLn(dc, fonts.f90, 10, y, text, color);
  delay(1000);
  return y;
}

void loop() {
  printText("NotoSans Italic", notoSansItalic);
  printText("NotoSans BoldItalic", notoSansBoldItalic);
  printText("NotoSans Condensed", notoSansCondensed);
  printText("NotoSans CondensedBold", notoSansCondensedBold);
  printText("NotoSans CondensedItalic", notoSansCondensedItalic);
  printText("NotoSerif Regular", notoSerifRegular);
  printText("NotoSerif Bold", notoSerifBold);
  printText("NotoSerif BoldItalic", notoSerifBoldItalic);
  printText("NotoSerif Condensed", notoSerifCondensed);
  printText("NotoSerif CondensedItalic", notoSerifCondensedItalic);
  printText("NotoSansMono Bold", notoSansMonoBold);

  delay(1200);
}
