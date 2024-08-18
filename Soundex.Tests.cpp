#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_EQ(soundex,"A200");
}

TEST(SoudexTestsuite, BasicSoundex) {
    char soundex[10];
    generateSoundex("Washington", soundex);
    ASSERT_EQ(soundex,"W252");
    generateSoundex("Lee", soundex);
    ASSERT_EQ(soundex,"L000");
    generateSoundex("Gutierrez", soundex);
    ASSERT_EQ(soundex,"G362");
    generateSoundex("Pfister", soundex);
    ASSERT_EQ(soundex,"P236");
    generateSoundex("Jackson", soundex);
    ASSERT_EQ(soundex,"J250");
    generateSoundex("Tymczak",soundex);
    ASSERT_EQ(soundex,"T522");
    generateSoundex("Ashcraft",soundex);
    ASSERT_EQ(soundex,"A261");
    generateSoundex("Friedrich",soundex);
    ASSERT_EQ(soundex,"F636");
    generateSoundex("McClelland",soundex);
    ASSERT_EQ(soundex,"M234");
    generateSoundex("Schmidt",soundex);
    ASSERT_EQ(soundex,"S530");
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

TEST(SoudexTestsuite, RepeatedLetters) {
    char soundex[10];
    generateSoundex("Leeee",soundex);
    ASSERT_EQ(soundex,"L000");
    generateSoundex("Bbbb", soundex);
    ASSERT_EQ(soundex,"B100");
}

TEST(SoudexTestsuite, MixedCase) {
    char soundex[10];
    generateSoundex("Washington",soundex);
    ASSERT_EQ(soundex,"W252");
    generateSoundex("washington",soundex);
    ASSERT_EQ(soundex,"W252");
}

TEST(SoudexTestsuite, LongerNames) {
    char soundex[10];
    generateSoundex("MacDonald",soundex);
    ASSERT_EQ(soundex,"M235");
    generateSoundex("MacDougall",soundex);
    ASSERT_EQ(soundex,"M232");
}

TEST(SoudexTestsuite, NamesWithHyphens) {
    char soundex[10];
    generateSoundex("Smith-Jones",soundex);
    ASSERT_EQ(soundex,"S532");
    generateSoundex("O'Conner", soundex);
    ASSERT_EQ(soundex,"O256");
}
