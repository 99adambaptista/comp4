// Copyright 2019 Adam Baptista

#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

using boost::regex;
using boost::smatch;
using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::posix_time::ptime;
using boost::posix_time::time_duration;

template <typename T>
int to_int(const T& sm) {
    return atoi(sm.str().c_str());
}

int main(int argc, char* argv[]) {
    smatch match;
    string line, str_boot, str_time, str_date, str_done;;
    ptime time_1, time_2;
    int line_num = 1;
    bool boot = false;


    if (argc != 2) {
        cout << "Invalid # of command lind arguments" << endl;
        return 0;
    }
    ifstream inFile(argv[1], ifstream::in);
    if (!inFile.is_open()) {
        cout << "Unable to open file \"" << argv[1] << "\"" << endl;
        return 0;
    }

    string outFileName(string(argv[1]) + ".rpt");
    ofstream outFile;
    outFile.open(outFileName.c_str());

    str_boot = "(.*log.c.166.*)";
    str_done = "(.*oejs.AbstractConnector:Started SelectChannelConnector.*)";
    str_time = "([[:digit:]]{2}):([[:digit:]]{2}):([[:digit:]]{2})";
    str_date = "([[:digit:]]{4})-([[:digit:]]{1,2})-([[:digit:]]{1,2}) ";

    regex re_boot(str_date + str_time + str_boot);
    regex re_done(str_date + str_time + str_done);


    while (getline(inFile, line)) {
        if (regex_match(line, match, re_boot)) {
            if (boot)
                outFile << "**** Incomplete boot **** \n" << endl;
        date _date(from_simple_string(match[0]));
        ptime temp(_date, time_duration(to_int(match[4]), to_int(match[5]),
            to_int(match[6])));
        time_1 = temp;

        outFile << "=== Device boot ===" << endl;
        outFile << line_num << "(" << argv[1] << "): ";
        outFile << match[1] << "-" << match[2] << "-" << match[3] << " ";
        outFile << match[4] << ":" << match[5] << ":" << match[6] << " ";
        outFile << "Boot Start" << endl;
        boot = true;

        } else if (regex_match(line, match, re_done)) {
            if (boot) {
                date _date(from_simple_string(match[0]));
                ptime temp(_date, time_duration(to_int(match[4]),
                    to_int(match[5]), to_int(match[6])));
                time_2 = temp;

                time_duration td = time_2 - time_1;

                outFile << line_num << "(" << argv[1] << "): ";
                outFile << match[1] << "-" << match[2] << "-"
                    << match[3] << " ";
                outFile << match[4] << ":" << match[5] << ":"
                    << match[6] << " ";
                outFile << "Boot Completed" << endl;

                outFile << "\tBoot Time: ";
                outFile << td.total_milliseconds() << "ms \n" << endl;

                boot = false;
            } else {
                outFile << "**** Unexpected boot ****\n" << endl;
            }
        }
        line_num++;
    }
    return 0;
}

