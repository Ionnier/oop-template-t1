#include <gtest/gtest.h>
#include "song.h"
#include <sstream>

TEST(Tema1, Constructor) {
    Song s("foo");
    EXPECT_EQ(s.getName(), "foo");
}

TEST(Tema1, ConstructorCopiere) {
    Song s("foo");
    const Song s2 = s;
    EXPECT_EQ(s.getName(), s2.getName());
}

TEST(Tema1, OperatorEgal) {
    Song s("foo");
    Song t("bar");
    s = t;
    EXPECT_EQ(s.getName(), t.getName());
}

TEST(Tema1, OperatorCitire) {
    std::stringstream ss;
    ss << "bar\n";

    Song s("foo");
    ss >> s;
    EXPECT_EQ(s.getName(), "bar");
}

TEST(Tema1, OperatorAfisare) {
    std::stringstream ss;
    Song s("foo");
    ss << s;
    s.afisare(ss);
    std::string out;
    ss >> out;
    EXPECT_EQ(out, "name=foo");
}