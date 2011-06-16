// CommandLineParser
//
// Simply parses the 'argv', based upon the registed ways to do it
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_COMMAND_LINE_PARSER_H_
#define _OE_COMMAND_LINE_PARSER_H_

#include <string>
#include <vector>

namespace OpenEngine {
namespace Utils {

/**
 * Utility to ease parsing the 'argv' given from a commandline at program start.
 *
 * @class CommandLineParser CommandLineParser.h
 */
class CommandLineParser 
{
    // ---------
    // Functions
    public:
        /** 
         * A seed like constructor
         * Really just used to save the argc, and argv in a vector<string>
         * format.
         * 
         * @param argc the argc, passed to the program at start.
         * @param argv the argv, passed to the program at start.
         */
        CommandLineParser(int argc, char* argv[]);

        /** 
         * A method for switching a boolean if a flag is found in the argv[]
         * Will only check till first string match
         * 
         * @param s an identifier string to try to match
         * @param b a boolean reference, to be switched, if string match found
         *
         * @return bool to indicate whether the boolean b was switched.
         */
        bool registerModule(std::string s, bool &b);

        /** 
         * A method for setting an integer if a flag is found in the argv[],
         * followed by an integer value.
         * Will only check till first string match
         * 
         * @param s an identifier string to try to match
         * @param i an integer reference, to be set, with the following value, if string match found
         *
         * @return bool to indicate whether a value was set to i.
         */
        bool registerModule(std::string s, int &i);
        //bool registerModule(std::string s, void* v);
    protected:
    private:

    // ---------
    // Variables
    public:
    protected:
    private:
        std::vector<std::string> strings;
};

} // NS Utils
} // NS OpenEngine

#endif //_OE_COMMAND_LINE_PARSER_H_
