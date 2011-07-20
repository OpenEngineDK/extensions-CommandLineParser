#include <Utils/CommandLineParser.h>
#include <Utils/Convert.h>

#include <Core/Exceptions.h>

#include <sstream>

namespace OpenEngine {
namespace Utils {

CommandLineParser::CommandLineParser(int argc, char* argv[])
{
    for(int x=1; x<argc; x++)
        strings.push_back(argv[x]);
}

bool CommandLineParser::registerModule(std::string s, bool &b)
{
    for(unsigned int x=0; x<strings.size(); x++)
    {
        std::string s2 = strings.at(x);
        if (s.compare(s2) == 0)
        {
            b = !b;
            return true;
        }
    }
    return false;
}

bool CommandLineParser::registerModule(std::string s, int &i)
{
    for(unsigned int x=0; x<strings.size(); x++)
    {
        std::string s2 = strings.at(x);
        if (s.compare(s2) == 0)
        {
            std::string integer_argument = strings.at(x+1);

            int temp;
            std::stringstream converter(integer_argument);
            
            if (!(converter >> temp))
            {
                std::string error_message = "Unable to convert string (";
                error_message.append(integer_argument);
                error_message.append(" to integer, at: ");
                error_message.append(__FILE__);
                error_message.append(" line: ");
                error_message.append(OpenEngine::Utils::Convert::ToString(__LINE__));
                throw OpenEngine::Core::InvalidArgument(error_message);
            }
            i = temp;
            return true;
        }
    }
    return false;
}

bool CommandLineParser::registerModule(std::string s, std::string &str)
{
    for(unsigned int x=0; x<strings.size(); x++)
    {
        std::string s2 = strings.at(x);
        if (s.compare(s2) == 0)
        {
            str = strings.at(x+1);
        }
    }
    return false;
}

} // NS Utils
} // NS OpenEngine

