/*
 * =====================================================================================
 *
 *       Filename:  Main.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/12/10 10:44:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include<iostream>
#include"SList.h"
#include"Test.cpp"

void test_creating_empty_list(Test* test);
void test_creating_full_list(Test* test);
void test_delete_list(Test* test);
void test_front(Test* test);
void test_push_front(Test* test);
void test_push_back(Test* test);
void test_pop_back(Test* test);
void test_pop_front(Test* test);
void test_iter(Test * test);
void test_reverse(Test * test);
void test_swap(Test* test);
void test_input(Test* test);
void test_cp(Test* test);
void test_const_iter(Test* test);
