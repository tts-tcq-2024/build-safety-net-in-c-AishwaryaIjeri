#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_EQ(soundex,"A200");
}

TEST(SoudexTestsuite, BasicSoundex) {
    generateSoundex("Washington", soundex);
    ASSERT_EQ(soundex,"W252");
    generateSoundex("Lee", soundex);
    ASSERT_EQ(soundex,"L000");
    generateSoundex("Gutierrez", soundex);
    ASSERT_EQ(soundex,"G362");
    generateSoundex("Pfister", soundex);.
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
    generateSoundex("",soundex);
    ASSERT_EQ(soundex,"");
    generateSoundex("A",soundex);
    ASSERT_EQ(soundex,"A000");
    generateSoundex("Aa",soundex);
    ASSERT_EQ(soundex,"A000");
    generateSoundex("J.",soundex);
    ASSERT_EQ(soundex,"J000");
}

TEST(soundex, Variations) {
    assertSoundex("Johnson",soundex);
    ASSERT_EQ(soundex,"J525");
    assertSoundex("Johnston",soundex);
    ASSERT_EQ(soundex,"J525");
    assertSoundex("Johnsen",soundex);
    ASSERT_EQ(soundex,"J525");
    assertSoundex("Johns",soundex);
    ASSERT_EQ(soundex,"J520");
}

TEST_F(soundex, RepeatedLetters) {
    assertSoundex("Leeee",soundex);
    ASSERT_EQ(soundex,"L000");
    assertSoundex("Bbbb", soundex);
    ASSERT_EQ(soundex,"B100");
}

TEST(soundex, MixedCase) {
    assertSoundex("Washington",soundex);
    ASSERT_EQ(soundex,"W252");
    assertSoundex("washington",soundex);
    ASSERT_EQ(soundex,"W252");
}

TEST(soundex, LongerNames) {
    assertSoundex("MacDonald",soundex);
    ASSERT_EQ(soundex,"M235");
    assertSoundex("MacDougall",soundex);
    ASSERT_EQ(soundex,"M232");
}

TEST(soundex, NamesWithHyphens) {
    assertSoundex("Smith-Jones",soundex);
    ASSERT_EQ(soundex,"S532");
    assertSoundex("O'Conner", soundex);
    ASSERT_EQ(soundex,"O256");
}
