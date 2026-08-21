A companion font library for http://github.com/dejwk/roo_display.

Contains the following fonts:

  "NotoSansMono-Bold"
  "NotoSans-Italic"
  "NotoSans-BoldItalic"
  "NotoSans-Condensed"
  "NotoSans-CondensedBold"
  "NotoSans-CondensedItalic"
  "NotoSerif-Regular"
  "NotoSerif-Bold"
  "NotoSerif-BoldItalic"
  "NotoSerif-Condensed"
  "NotoSerif-CondensedItalic"

in the following sizes: 8,10,12,15,18,27,40,60,90.

## Host emulation

Host builds use the roo_testing 2.0 Arduino ESP32 profile. With Bazelisk 1.21
or newer, a plain command defaults to that profile and prints a notice:

    bazel test ...
    bazel test ... --config=asan
    bazel test ... --config=roo_testing_arduino_esp32

The files under .roo_testing/bazelrc/esp32 are vendored from roo_testing;
follow their canonical-source headers when refreshing them.

Run the interactive font catalog under the emulator with:

    bazel run //examples/fonts:fonts
