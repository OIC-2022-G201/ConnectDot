#pragma once
namespace base_engine {
template <class Tag>
struct YesNo {
 private:
  bool yes_no;

  struct Helper {
    bool yes_no;
  };

 public:
  [[nodiscard]] YesNo() = default;

  [[nodiscard]] explicit constexpr YesNo(bool yesNo) noexcept : yes_no{yesNo} {}

  [[nodiscard]] constexpr YesNo(Helper helper) noexcept
      : yes_no{helper.yes_no} {}

  [[nodiscard]] explicit constexpr operator bool() const noexcept {
    return yes_no;
  }

  [[nodiscard]] constexpr bool getBool() const noexcept { return yes_no; }

  constexpr auto operator<=>(const YesNo&) const noexcept = default;

  static constexpr Helper Yes{true};

  static constexpr Helper No{false};
};
}  // namespace base_engine