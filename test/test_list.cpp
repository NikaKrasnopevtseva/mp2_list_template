#include "list.h"
#include <gtest.h>

TEST(List, created_empty_list)
{
	List<int> list;
	EXPECT_EQ(1, list.isEmpty());
}
TEST(List, created_list_with_full_head)
{
	List<int> list(1);
	EXPECT_EQ(1, list.ViewHead());
}
TEST(List, throws_when_try_to_check_tail_from_empty_list)
{
	List<int> list;
	ASSERT_ANY_THROW(list.ViewTail());
}
TEST(List, throws_when_try_to_check_head_from_empty_list)
{
	List<int> list;
	ASSERT_ANY_THROW(list.ViewHead());
}
TEST(List,can_insert_to_tail)
{
	List<int> list;
	list.InsertToTail(1);
	EXPECT_EQ(1, list.ViewTail());
}TEST(List, can_insert_to_head)
{
	List<int> list;
	list.InsertToTail(1);
	list.InsertToTail(2);
	list.InsertToHead(3);
	EXPECT_EQ(3, list.ViewHead());
}
TEST(List, isEmpty_works_right)
{
	List<int> list;
	list.InsertToTail(1);
	EXPECT_EQ(0, list.isEmpty());
}
TEST(List, can_delete_d)
{
	List<int> list(1), list1(1);
	list.InsertToTail(2);
	list.Delete(2);
	EXPECT_EQ(1, list==list1);
}
TEST(List, can_delete_d_when_there_arent)
{
	List<int> list(1), list1(1);
	list.InsertToTail(2);
	list1.InsertToTail(2);
	list.Delete(3);
	EXPECT_EQ(1, list == list1);
}
TEST(List, can_delete_d_from_head)
{
	List<int> list;
	list.InsertToTail(1);
	list.Delete(1);
	EXPECT_EQ(1, list.isEmpty());
}
TEST(List, can_delete_all_d)
{
	List<int> list1;
	list1.InsertToTail(1);
	list1.InsertToTail(2);
	list1.InsertToTail(2);
	list1.InsertToTail(3);
	list1.DeleteAll(2);
	List<int> list2(1);
	list2.InsertToTail(3);
	EXPECT_EQ(1, list1==list2);
}
TEST(List, can_delete_all_d_with_head)
{
	List<int> list1;
	list1.InsertToTail(2);
	list1.InsertToTail(2);
	list1.InsertToTail(2);
	list1.InsertToTail(3);
	list1.DeleteAll(2);
	List<int> list2(3);
	EXPECT_EQ(1, list1 == list2);
}
TEST(List, can_delete_all_d_when_there_arent)
{
	List<int> list1;
	list1.InsertToTail(2);
	list1.InsertToTail(2);
	list1.InsertToTail(2);
	list1.InsertToTail(3);
	list1.DeleteAll(1);
	List<int> list2;
	list2.InsertToTail(2);
	list2.InsertToTail(2);
	list2.InsertToTail(2);
	list2.InsertToTail(3);

	EXPECT_EQ(1, list1 == list2);
}
TEST(List, can_get_size)
{
	List<int> list;
	list.InsertToTail(1);
	list.InsertToTail(2);
	list.InsertToTail(2);
	EXPECT_EQ(3, list.GetSize());
}
TEST(List, are_lists_equal_with_equal_size)
{
	List<int> list1(1), list2(1);
	list1.InsertToTail(2); list2.InsertToTail(2);
	list1.InsertToTail(3); list2.InsertToTail(3);
	EXPECT_EQ(1, list1==list2);
}
TEST(List, are_lists_not_equal_with_not_equal_size)
{
	List<int> list1(1), list2(1);
	list1.InsertToTail(2); list2.InsertToTail(2);
	list1.InsertToTail(3); list2.InsertToTail(3);
	list2.InsertToTail(3);
	EXPECT_EQ(0, list1 == list2);
}
TEST(List, are_lists_not_equal)
{
	List<int> list1(1), list2(1);
	list1.InsertToTail(2); list2.InsertToTail(2);
	list1.InsertToTail(3); list2.InsertToTail(4);
	EXPECT_EQ(0, list1 == list2);
}
TEST(List, can_assign_lists)
{
	List<int> list1(1), list2;
	list1.InsertToTail(2); 
	list1.InsertToTail(3); 
	list2 = list1;
	EXPECT_EQ(1, list1 == list2);
}
TEST(List, can_copy_lists)
{
	List<int> list1(1);
	list1.InsertToTail(2);
	list1.InsertToTail(3);
	List<int>list2(list1);
	EXPECT_EQ(1, list1 == list2);
}
TEST(List, can_clean_list)
{
	List<int> list(1);
	list.InsertToTail(2);
	list.InsertToTail(3);
	list.Clean();
	EXPECT_EQ(1, list.isEmpty());
}
TEST(List, can_inverse_list)
{
	List<int> list1(1);
	list1.InsertToTail(2);
	list1.InsertToTail(3);
	list1.Inverse();
	List<int> list2(3);
	list2.InsertToTail(2);
	list2.InsertToTail(1);
	EXPECT_EQ(1, list1==list2);
}
TEST(List, can_made_unique)
{
	List<int> list1(1);
	list1.InsertToTail(2);
	list1.InsertToTail(2);
	list1.InsertToTail(1);
	list1.InsertToTail(3);
	list1.InsertToTail(3);
	list1.InsertToTail(3);
	list1.MadeUnique();
	List<int> list2(1);
	list2.InsertToTail(2);
	list2.InsertToTail(3);
	EXPECT_EQ(1, list1 == list2);
}
TEST(List, can_made_unique2)
{
	List<int> list1(1);
	list1.InsertToTail(1);
	list1.InsertToTail(2);
	list1.InsertToTail(1);
	list1.InsertToTail(3);
	list1.InsertToTail(3);
	list1.InsertToTail(3);
	list1.MadeUnique();
	List<int> list2(1);
	list2.InsertToTail(2);
	list2.InsertToTail(3);
	EXPECT_EQ(1, list1 == list2);
}
TEST(List, can_go_to_string)
{
	List<int> list1(1);
	list1.InsertToTail(2);
	list1.InsertToTail(3);
	string s1 = list1.ToString();
	string s2 = "1;2;3;";
	EXPECT_EQ(1, s1 == s2);
}
TEST(List, can_merge_lists)
{
	List<int> list1(1);
	list1.InsertToTail(2);
	list1.InsertToTail(3);
	List<int> list2(4);
	list2.InsertToTail(5);
	list2.InsertToTail(6);
	List<int> list3 = list1.Merge(list2);
	List<int> listres(1);
	listres.InsertToTail(2);
	listres.InsertToTail(3);
	listres.InsertToTail(4);
	listres.InsertToTail(5);
	listres.InsertToTail(6);
	EXPECT_EQ(1, list3 == listres);
}
TEST(List, can_insert_after)
{
	List<int> list1(1);
	list1.InsertToTail(3);
	list1.InsertToTail(4);
	list1.InsertAfter(list1.begin(), 2);
	List<int> list2(1);
	list2.InsertToTail(2);
	list2.InsertToTail(3);
	list2.InsertToTail(4);
	EXPECT_EQ(1, list1 == list2);
}
TEST(List, can_search_node)
{
	List<int> list1(1);
	list1.InsertToTail(2);
	list1.InsertToTail(3);
	EXPECT_EQ(1, list1.tail() == list1.Search(3));
}
TEST(List, can_delete_from_start_to_finish)
{
	List<int> list1(1);
	list1.InsertToTail(2);
	list1.InsertToTail(3);
	list1.InsertToTail(4);
	list1.InsertToTail(5);
	List<int> list2(1);
	list2.InsertToTail(5);
	list1.Delete(list1.Search(2), list1.Search(4));
	EXPECT_EQ(1,list1 == list2);
}
TEST(List, can_merge_lists_from_start_and_return)
{
	List<int> list1(1);
	list1.InsertToTail(5);
	list1.InsertToTail(6);
	List<int> list2(2);
	list2.InsertToTail(3);
	list2.InsertToTail(4);
	List<int> list3 = list1.Merge(list1.begin(), list2);
	List<int> listres(1);
	listres.InsertToTail(2);
	listres.InsertToTail(3);
	listres.InsertToTail(4);
	listres.InsertToTail(5);
	listres.InsertToTail(6);
	EXPECT_EQ(1, list3 == listres);
}
TEST(List, can_merge_with_list_from_start)
{
	List<int> list1(1);
	list1.InsertToTail(5);
	list1.InsertToTail(6);
	List<int> list2(2);
	list2.InsertToTail(3);
	list2.InsertToTail(4);
	list1.MergeWith(list1.begin(), list2);
	List<int> listres(1);
	listres.InsertToTail(2);
	listres.InsertToTail(3);
	listres.InsertToTail(4);
	listres.InsertToTail(5);
	listres.InsertToTail(6);
	EXPECT_EQ(1, list1 == listres);
}
