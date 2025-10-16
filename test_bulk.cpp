#define BOOST_TEST_MODULE test_version

#include <iostream>

#include "lib.h"
#include <boost/test/unit_test.hpp>

#include "Bulk/Bulk.h"
#include "Bulk/Bulk_moc.h"
#include "Logger/LogSystem.h"
#include "Logger/StdCoutLogger_moc.h"

BOOST_AUTO_TEST_SUITE(test_editor)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_CASE(test_valid_sum)
{
    BOOST_CHECK(1 + 1 == 2);
}

BOOST_AUTO_TEST_CASE(test_bulk_1)
{
    otus::Bulk::SetMaxCommands(3);

    otus::Bulk_moc bulk;
    bulk.AddCommand("cmd1");
    bulk.AddCommand("cmd2");

    std::string strTest;
    for (const auto &c : bulk.GetCommands_Moc())
    {
        strTest += c;
    }

    std::cout << strTest << "\n";
    BOOST_CHECK(strTest == "cmd1cmd2");
}

BOOST_AUTO_TEST_CASE(test_bulk_2)
{
    otus::Bulk::SetMaxCommands(3);

    otus::Bulk_moc bulk;
    bulk.AddCommand("cmd1");
    bulk.AddCommand("cmd2");
    bulk.AddCommand("cmd3");

    std::string strTest;
    for (const auto &c : bulk.GetCommands_Moc())
    {
        strTest += c;
    }

    std::cout << strTest << "\n";
    BOOST_CHECK(strTest == "");
}

BOOST_AUTO_TEST_CASE(test_bulk_3)
{
    otus::Bulk::SetMaxCommands(3);

    otus::Bulk_moc bulk;
    bulk.AddCommand("cmd1");
    bulk.AddCommand("cmd2");
    bulk.AddCommand("{");
    bulk.AddCommand("cmd3");

    std::string strTest;
    for (const auto &c : bulk.GetCommands_Moc())
    {
        strTest += c;
    }

    std::cout << strTest << "\n";
    BOOST_CHECK(strTest == "cmd3");
}

BOOST_AUTO_TEST_SUITE_END()