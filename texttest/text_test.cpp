#include <gtest.h>

#include <gtest.h>
#include "Text.h"

TEST(text, can_create_text_without_throws)
{
	ASSERT_NO_THROW(Text text("world"));
}

TEST(text, can_create_copy_text_without_throws)
{
	Text text1("Hello world");
	ASSERT_NO_THROW(Text text(text1));
}

TEST(text, can_insert_text_1_without_throws)
{
	Text text("Hello world");
	ASSERT_NO_THROW(text.Insert(5, "HI"));
}

TEST(text, can_insert_text_2_without_throws)
{
	Text text("Hello world");
	TTree word("HI");
	TTree* tmp;
	tmp = text.GetRoot()->GetNextLevel()->GetNextLevel();
	ASSERT_NO_THROW(text.Insert(tmp, &word));
}

TEST(text, can_find_text_1_without_throws)
{
	Text text("Hello world");
	ASSERT_NO_THROW(text.Find("llo"));
}

TEST(text, can_find_text_1)
{
	Text text("Hello world");
	EXPECT_EQ(text.Find("llo"), 2);
}

TEST(text, can_find_text_2_without_throws)
{
	Text text("Hello world");
	ASSERT_NO_THROW(text.FindTree("llo"));
}

TEST(text, can_find_text_2)
{
	TTree::ClearMemory();
	Text text("Hello world");
	TTree* tmp = text.FindTree("He");
	EXPECT_EQ(text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel(), tmp);
}

TEST(text, can_copy_text_1_without_throws)
{
	Text text("Hello world");
	ASSERT_NO_THROW(text.Copy(2, 3));
}

TEST(text, can_copy_text_1)
{
	Text text("Hello world");
	char* tmp = text.Copy(2, 3);
	EXPECT_EQ(tmp[0], 'l');
	EXPECT_EQ(tmp[1], 'l');
	EXPECT_EQ(tmp[2], 'o');
}

TEST(text, can_copy_text_2_without_throws)
{
	Text text("Hello world");
	TTree* tmp = text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel();
	ASSERT_NO_THROW(text.Copy(tmp, 3));
}

TEST(text, can_copy_text_2)
{
	Text text("Hello world");
	TTree* tmp_1 = text.GetRoot()->GetNextLevel()->GetNextLevel();
	TTree* tmp_2 = text.Copy(tmp_1, 2);
	EXPECT_EQ(tmp_2->GetNextLevel()->GetNextLevel()->GetNextLevel()->GetLetter(), 'H');
	EXPECT_EQ(tmp_2->GetNextLevel()->GetNextLevel()->GetNextLevel()->GetSameLevel()->GetLetter(), 'e');
	TTree::ClearMemory();
}


