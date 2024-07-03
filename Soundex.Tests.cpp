#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
 // ASSERT_EQ(soundex,"A200");
}
int main()
{
    TEST("BOOK","B200")
     // Basic tests
   TEST("Washington", "W252");
    TEST("Lee", "L000");
    TEST("Gutierrez", "G362");
    TEST("Pfister", "P236");
    TEST("Jackson", "J250");

    // Edge cases
    TEST("", ""); // Empty input
    TEST("B", "B000"); // Single character input
    TEST("Ae", "A000"); // Input with vowel
    TEST("G.", "G000"); // Input with non-alphabetic character

    // Variations
    TEST("Johnson", "J525");
    TEST("Johnston", "J525");
    TEST("Johnsen", "J525");
    TEST("Johns", "J520");

    // Handling of repeated letters
    TEST("Leeee", "L000");
    TEST("Bbbb", "B100");

    // Handling of mixed case
    TEST("Washington", "W252");
    TEST("washington", "W252");

    // Test longer names
    TEST("MacDonald", "M235");
    TEST("MacDougall", "M232");

    // Test names with hyphens
    TEST("Smith-Jones", "S532");
    TEST("O'Conner", "O256");
}
