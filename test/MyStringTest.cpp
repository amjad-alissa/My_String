#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE MyString_Test_Suite

#include <iostream>
#include "MyString.h"
#include "MyString.cpp"
#include <boost/test/included/unit_test.hpp>

using namespace Assignment06;

struct Fixture {
public:
    Fixture() {

        myString1 = MyString();
        myString2 = MyString("Hello,,");
        myString3 = MyString("Test In Progress...,,");
        myString4 = MyString({'a', 'b', 'c', 'd', 'e', 'f', ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F', '\0'});
        myString5 = MyString("World!");
        myString6 = MyString("Test has been Successful");
        myString7 = MyString({'\0'});
        myString8 = MyString("");

    }

    ~Fixture() = default;

    MyString myString1;
    MyString myString2;
    MyString myString3;
    MyString myString4;
    MyString myString5;
    MyString myString6;
    MyString myString7;
    MyString myString8;

};

BOOST_AUTO_TEST_SUITE(MyString_Test_Suite)

    BOOST_FIXTURE_TEST_CASE(Cnstructors_test, Fixture) {
        MyString temp(myString2);

        BOOST_CHECK_EQUAL(myString1.length(), 0);
        BOOST_CHECK_EQUAL(myString7.length(), 0);
        BOOST_CHECK_EQUAL(myString8.length(), 0);
        BOOST_CHECK_EQUAL(myString2.length(), 7);
        BOOST_CHECK_EQUAL(myString3.length(), 21);
        BOOST_CHECK_EQUAL(myString4.length(), 16);
        BOOST_CHECK_EQUAL(temp, myString2);

    }

    BOOST_FIXTURE_TEST_CASE(IsEmpty_test, Fixture) {

        BOOST_CHECK_EQUAL(myString1.is_empty(), true);
        BOOST_CHECK_EQUAL(myString7.is_empty(), true);
        BOOST_CHECK_EQUAL(myString8.is_empty(), true);
        BOOST_CHECK_EQUAL(myString2.is_empty(), false);
        BOOST_CHECK_EQUAL(myString3.is_empty(), false);
        BOOST_CHECK_EQUAL(myString4.is_empty(), false);

    }

    BOOST_FIXTURE_TEST_CASE(PlusEquals_Assignment_Operators_test, Fixture) {

        char ch = '?';
        char world[] = {'W', 'o', 'r', 'l', 'd', '!', '\0'};
        MyString myString22 = MyString("Hello,,World!");
        MyString myString33 = MyString("Test In Progress...,,Test has been Successful");
        MyString myString55 = MyString("World!?");
        MyString temp;

        temp = myString5 += ch;
        BOOST_CHECK_EQUAL(temp, myString55);

        temp = myString2 += world;
        BOOST_CHECK_EQUAL(temp, myString22);

        temp = myString3 += myString6;
        BOOST_CHECK_EQUAL(temp, myString33);
    }

    BOOST_FIXTURE_TEST_CASE(Plus_Assignment_Operators_test, Fixture) {

        char *ptr_chars = new char[3]{'G', 'H', '\0'};
        MyString myString11 = MyString("Test has been Successful");
        MyString myString44 = MyString(
                {'a', 'b', 'c', 'd', 'e', 'f', ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', '\0'});
        MyString myString111 = MyString("GH");
        MyString temp;

        temp = myString6 + myString1;
        BOOST_CHECK_EQUAL(temp, myString11);

        temp = myString4 + ptr_chars;
        BOOST_CHECK_EQUAL(temp, myString44);

        temp = ptr_chars + myString1;
        BOOST_CHECK_EQUAL(temp, myString111);

        delete[] ptr_chars;
    }

    BOOST_FIXTURE_TEST_CASE(Indexing_Operator_test, Fixture) {

        const MyString temp1 = myString2;

        BOOST_CHECK_EQUAL(temp1[0], 'H');
        BOOST_CHECK_THROW(temp1[-1], std::out_of_range);
        BOOST_CHECK_THROW(temp1[7], std::out_of_range);

        MyString temp("Mello,,");
        myString2[0] = 'M';
        BOOST_CHECK_EQUAL(myString2, temp);


        BOOST_CHECK_THROW(myString2[-1] = 'W', std::out_of_range);
        BOOST_CHECK_THROW(myString2[7] = '!', std::out_of_range);
    }

    BOOST_FIXTURE_TEST_CASE(C_String_test, Fixture) {

        char *ptr_char;

        ptr_char = new char[1]{};
        BOOST_CHECK_EQUAL(myString1.c_str(), ptr_char);
        delete[] ptr_char;

        ptr_char = new char[7]{'H', 'e', 'l', 'l', 'o', ',', ','};
        BOOST_CHECK_EQUAL(myString2.c_str(), ptr_char);
        delete[] ptr_char;

        ptr_char = new char[17]{'a', 'b', 'c', 'd', 'e', 'f', ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F'};
        BOOST_CHECK_EQUAL(myString4.c_str(), ptr_char);
        delete[] ptr_char;

        ptr_char = new char[1]{'a'};
        BOOST_CHECK_EQUAL(myString1.c_str() != ptr_char, true);
        delete[] ptr_char;
    }

    BOOST_FIXTURE_TEST_CASE(Swap_test, Fixture) {

        MyString temp1;
        MyString temp2;

        temp1 = myString6;
        temp2 = myString2;

        myString6.swap(myString2);
        BOOST_CHECK_EQUAL(myString6, temp2);
        BOOST_CHECK_EQUAL(myString2, temp1);
        BOOST_CHECK_EQUAL(myString6 == temp1, false);
        BOOST_CHECK_EQUAL(myString2 == temp2, false);

        temp1 = myString3;
        temp2 = myString4;

        myString3.swap(myString4);
        BOOST_CHECK_EQUAL(myString3, temp2);
        BOOST_CHECK_EQUAL(myString4, temp1);
        BOOST_CHECK_EQUAL(myString3 == temp1, false);
        BOOST_CHECK_EQUAL(myString4 == temp2, false);
    }

    BOOST_FIXTURE_TEST_CASE(Comparison_Operators_test, Fixture) {

        MyString temp1;
        MyString temp2;

        temp1 = myString1;
        temp2 = myString2;

        BOOST_CHECK_EQUAL(myString1 == temp1, true);
        BOOST_CHECK_EQUAL(myString2 == temp2, true);
        BOOST_CHECK_EQUAL(myString2 == myString1, false);

        BOOST_CHECK_EQUAL(myString1 != temp1, false);
        BOOST_CHECK_EQUAL(myString2 != temp2, false);
        BOOST_CHECK_EQUAL(myString2 != myString1, true);

        BOOST_CHECK_EQUAL(myString1 >= temp1, true);
        BOOST_CHECK_EQUAL(myString1 <= temp1, true);
        BOOST_CHECK_EQUAL(myString2 >= temp2, true);
        BOOST_CHECK_EQUAL(myString2 <= temp2, true);

        BOOST_CHECK_EQUAL(myString1 > temp1, false);
        BOOST_CHECK_EQUAL(myString1 < temp1, false);
        BOOST_CHECK_EQUAL(myString2 > temp2, false);
        BOOST_CHECK_EQUAL(myString2 < temp2, false);
    }

    BOOST_FIXTURE_TEST_CASE(Input_Operator_test, Fixture) {

        MyString temp1;
        MyString temp2("Hello");

        std::istringstream iStr;
        iStr.str("Hello");
        iStr >> temp1;

        BOOST_CHECK_EQUAL(temp1, temp2);

        temp2 = MyString("Hello,,,World!");
        std::istringstream iStr1;
        iStr1.str(",,,World!");
        iStr1 >> temp1;

        BOOST_CHECK_EQUAL(temp1, temp2);
    }

    BOOST_FIXTURE_TEST_CASE(Output_Operator_test, Fixture) {

        std::ostringstream oStr;
        oStr << myString2;
        BOOST_CHECK_EQUAL(oStr.str(), "Hello,,");

        std::ostringstream oStr1;
        oStr1 << myString3;
        BOOST_CHECK_EQUAL(oStr1.str(), "Test In Progress...,,");

        std::ostringstream oStr2;
        oStr2 << myString4;
        BOOST_CHECK_EQUAL(oStr2.str(), "abcdef    ABCDEF");
    }

BOOST_AUTO_TEST_SUITE_END()