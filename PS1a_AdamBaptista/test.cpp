// Copyright 2015 fredm@cs.uml.edu for 91.204 Computing IV
// Wed Mar 25 06:32:17 2015
// Dr. Y. Rykalova:
// Please be aware that it is an "start-up" code
// You should use the proper naming (RingBuffer, etc.) according to 
// the assignment  requirements

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/included/unit_test.hpp>

#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "LSFR.hpp"

BOOST_AUTO_TEST_SUITE(lsfr);

BOOST_AUTO_TEST_CASE(my_boost_test_1) {
	//took from pdf
	LSFR lsfr_test_1("01101000010", 8);
	BOOST_REQUIRE(lsfr_test_1.step() == 1);
	BOOST_REQUIRE(lsfr_test_1.step() == 1);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 1);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 1);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	
	LSFR lsfr_test_2("01101000010", 8);
	BOOST_REQUIRE(lsfr_test_2.generate(5) == 25);
}

BOOST_AUTO_TEST_CASE(my_boost_test_2) {
	//all 0
	LSFR lsfr_test_1("00000000000", 8);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	
	LSFR lsfr_test_2("00000000000", 8);
	BOOST_REQUIRE(lsfr_test_2.generate(5) == 0);
}

BOOST_AUTO_TEST_CASE(my_boost_test_3) {
	//all 1
	LSFR lsfr_test_1("11111111111", 10);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	BOOST_REQUIRE(lsfr_test_1.step() == 0);
	
	LSFR lsfr_test_2("00000", 3);
	BOOST_REQUIRE(lsfr_test_2.generate(1000) == 0);
}

}
