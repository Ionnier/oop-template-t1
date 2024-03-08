#include <gtest/gtest.h>
#include <album.h>

TEST(Tema1, OperatorAdaugare) {
    Album a("foo", "bar");
    Song s("sd");
    a + s;
    EXPECT_EQ(a.getSongs().size(), 1);
}

TEST(Tema1, OperatorAccesare) {
    Album a("foo", "bar");
    EXPECT_EQ(a[0], nullptr);
    Song s("sd");
    a + s;
    EXPECT_EQ(a[0]->getName(), s.getName());
    EXPECT_NE((a[0]), &s);
}