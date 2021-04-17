/* Character set */
#define NUMERIC_CHAR_SET NumericCharSet
#define ALPHABETIC_CHAR_SET AlphabeticCharSet

// Numberic character set
char NumericCharSet(char c) {
  if (IsNumericChar(c)) return c;

  return '\0';
}

// Alphabetic character set
char AlphabeticCharSet(char c) {
  if (IsAlphabeticChar(c)) return c;

  return '\0';
}
