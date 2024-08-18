#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_EQ(soundex,"A200");
  generateSoundex("Washington", soundex);
  ASSERT_EQ(soundex,"W252");
  generateSoundex("Lee", soundex);
  ASSERT_EQ(soundex,"L000");
 
}

TEST(SoudexTestsuite, EdgeCases) {
    char soundex[5];
    generateSoundex("",soundex);
    ASSERT_EQ(soundex,"");
    generateSoundex("A",soundex);
    ASSERT_EQ(soundex,"A000");
    generateSoundex("Aa",soundex);
    ASSERT_EQ(soundex,"A000");
    generateSoundex("J.",soundex);
    ASSERT_EQ(soundex,"J000");
}

TEST(SoudexTestsuite, Variations) {
   char soundex[10];
    generateSoundex("Johnson",soundex);
    ASSERT_EQ(soundex,"J525");
    generateSoundex("Johnston",soundex);
    ASSERT_EQ(soundex,"J525");
    generateSoundex("Johnsen",soundex);
    ASSERT_EQ(soundex,"J525");
    generateSoundex("Johns",soundex);
    ASSERT_EQ(soundex,"J520");
}

TEST(SoudexTestsuite, NamesWithHyphens) {
    char soundex[10];
    generateSoundex("Smith-Jones",soundex);
    ASSERT_EQ(soundex,"S532");
    generateSoundex("O'Conner", soundex);
    ASSERT_EQ(soundex,"O256");
}
