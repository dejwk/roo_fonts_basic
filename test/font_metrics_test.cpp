#include "roo_display.h"
#include "roo_display/font/font.h"
#include "roo_fonts/NotoSerif_Regular/12.h"
#include "testing_drawable.h"

namespace roo_display {

using namespace testing;

const Font& font() { return font_NotoSerif_Regular_12(); }

class Label : public Drawable {
 public:
  Label(const string& label) : label_(label) {}

 private:
  void drawTo(const Surface& s) const override {
    font().drawHorizontalString(s, label_, color::White);
  }

  Box extents() const override {
    return font().getHorizontalStringMetrics(label_).screen_extents();
  }

  std::string label_;
};

TEST(FontTest, SimpleTextNoBackground) {
  FakeScreen<Argb4444> screen(26, 18, color::Black);
  screen.Draw(Label("Aftp"), 2, 14);

  EXPECT_THAT(screen, MatchesContent(Grayscale4(), 26, 18,
                                     "                          "
                                     "                          "
                                     "                          "
                                     "                          "
                                     "            ACD1          "
                                     "     6D    5A 832         "
                                     "     AD4   89 1B4         "
                                     "    1989  7DDB9*C9A*6AC9  "
                                     "    743E   89  D4  BB  C5 "
                                     "    B  D5  89  D4  A7  89 "
                                     "   3C99CA  89  D4  A6  7A "
                                     "   82  2*1 89  D4  A7  89 "
                                     "   D    E6 89  C5  AC  C5 "
                                     "  D*B  A*EA**C 6DA A8BC9  "
                                     "                   A6     "
                                     "                   B7     "
                                     "                  9*E5    "
                                     "                          "));
}

}  // namespace roo_display
