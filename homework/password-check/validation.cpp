#include "validation.hpp"

#include <algorithm>
#include <cctype>
#include <string_view>

std::string_view getErrorMessage(const ErrorCode& result) {
  switch (result) {
    case ErrorCode::Ok:
      return message_ok;
      break;
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
      return message_min_9_chars;
      break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
      return message_min_1_digit;
      break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
      return message_min_1_special_char;
      break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
      return message_min_1_uppercase;
      break;
    case ErrorCode::PasswordsDoNotMatch:
      return message_not_match;
      break;
  }
  return std::string_view("");
}

bool doPasswordsMatch(std::string_view password, const std::string_view repeated_password) {
  return password == repeated_password;
}

ErrorCode checkPasswordRules(std::string_view password) {
  if (password.length() < min_password_length) {
    return ErrorCode::PasswordNeedsAtLeastNineCharacters;
  }

  if (std::none_of(password.begin(), password.end(), std::isdigit)) {
    return ErrorCode::PasswordNeedsAtLeastOneNumber;
  }

  if (std::none_of(password.begin(), password.end(), std::ispunct)) {
    return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
  }

  if (std::none_of(password.begin(), password.end(), std::isupper)) {
    return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
  }

  return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string_view password, std::string_view repeated_password) {
  if (!doPasswordsMatch(password, repeated_password)) {
    return ErrorCode::PasswordsDoNotMatch;
  }

  return checkPasswordRules(password);
}
