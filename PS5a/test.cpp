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

#include "RingBuffer.cpp"

//BOOST_AUTO_TEST_SUITE(rb);

BOOST_AUTO_TEST_CASE(my_boost_test_1) {
	RingBuffer rb(5);

	rb.enqueue(2);
	rb.enqueue(1);
	rb.enqueue(0);

	BOOST_REQUIRE(rb.dequeue() == 2);
	BOOST_REQUIRE(rb.dequeue() == 1);
	BOOST_REQUIRE(rb.dequeue() == 0);
}

BOOST_AUTO_TEST_CASE(my_boost_test_2) {
	// normal constructor
	BOOST_REQUIRE_NO_THROW(RingBuffer(100));

	// this should fail
	BOOST_REQUIRE_THROW(RingBuffer(0), exception);
	BOOST_REQUIRE_THROW(RingBuffer(0), invalid_argument);
    BOOST_REQUIRE_THROW(RingBuffer(1), exception);
	BOOST_REQUIRE_THROW(RingBuffer(1), invalid_argument);
}

BOOST_AUTO_TEST_CASE(my_boost_test_3) {
	RingBuffer rb(2);

    BOOST_REQUIRE_THROW(rb.dequeue(), exception);
    BOOST_REQUIRE_THROW(rb.dequeue(), runtime_error);

    BOOST_REQUIRE_THROW(rb.peek(), exception);
    BOOST_REQUIRE_THROW(rb.peek(), runtime_error);

    rb.enqueue(1);
    rb.enqueue(2);
    rb.enqueue(4);
    BOOST_REQUIRE_THROW(rb.enqueue(3), exception);
    BOOST_REQUIRE_THROW(rb.enqueue(3), runtime_error);
}


