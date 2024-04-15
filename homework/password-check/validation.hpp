#pragma once

// #include <string>
#include <string_view>

enum class ErrorCode {
  Ok,
  PasswordNeedsAtLeastNineCharacters,
  PasswordNeedsAtLeastOneNumber,
  PasswordNeedsAtLeastOneSpecialCharacter,
  PasswordNeedsAtLeastOneUppercaseLetter,
  PasswordsDoNotMatch
};
namespace {

std::string_view message_ok{"Ok"};
std::string_view message_min_9_chars{"Password needs to have at least nine characters"};
std::string_view message_min_1_digit{"Password needs to have at least one number"};
std::string_view message_min_1_special_char{"Password needs to have at least one special character"};
std::string_view message_min_1_uppercase{"Password needs to have at least one uppercase letter"};
std::string_view message_not_match{"Passwords do not match"};

constexpr short int min_password_length{9};

}  //  namespace

std::string_view getErrorMessage(const ErrorCode& result);

bool doPasswordsMatch(std::string_view password, const std::string_view repeated_password);

ErrorCode checkPasswordRules(std::string_view password);

ErrorCode checkPassword(std::string_view password, std::string_view repeated_password);
