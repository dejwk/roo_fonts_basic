# roo_fonts_basic 1.0.5

- Updated `roo_display` to 3.3.0 in Bazel and raised the PlatformIO minimum requirement to 3.3.0.
- Updated Bazel dependencies to `rules_cc` 0.2.25 and `roo_testing` 2.1.2.
- Updated the shared CI workflow to `roo_testing` 2.1.2.
- Added consolidated release notes for previous versions.

---

# [roo_fonts_basic 1.0.4](https://github.com/dejwk/roo_fonts_basic/releases/tag/1.0.4)

Published 2026-08-30.

This release modernizes the development and CI setup and adds an interactive host-emulation example.

### Added

- Runnable emulator font catalog: `bazel run //examples/fonts:fonts`.
- Arduino ESP32 host-emulation profile via `roo_testing` 2.x.
- AddressSanitizer configuration for host builds.
- Pull-request and manual CI triggers.

### Changed

- Updated the `roo_display` dependency to version 3.2.2 or newer.
- Updated Bazel tooling and centralized CI through the shared `roo_testing` workflow.
- Expanded README instructions for host emulation and sanitizer builds.

Full changes: https://github.com/dejwk/roo_fonts_basic/compare/1.0.3...1.0.4

---

# [roo_fonts_basic 1.0.3](https://github.com/dejwk/roo_fonts_basic/releases/tag/1.0.3)

Published 2026-08-07.

Added subscripts for small integers (2-5).

**Full Changelog**: https://github.com/dejwk/roo_fonts_basic/compare/1.0.2...1.0.3

---

# [roo_fonts_basic 1.0.2](https://github.com/dejwk/roo_fonts_basic/releases/tag/1.0.2)

Published 2026-02-27.

Fixed compilation issue in the example.

---

# [roo_fonts_basic 1.0.1](https://github.com/dejwk/roo_fonts_basic/releases/tag/1.0.1)

Published 2026-02-25.

* Added unit testing, continuous integration, an example.

**Full Changelog**: https://github.com/dejwk/roo_fonts_basic/compare/1.0.0...1.0.1

---

# [roo_fonts_basic 1.0.0](https://github.com/dejwk/roo_fonts_basic/releases/tag/1.0.0)

Published 2026-02-25.

Initial release.

---

