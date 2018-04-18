/*
 * Copyright 2015 Atria Dynamics, LLC.
 *
 * Written by Joe Turner <joe@atriadynamics.com>
 #
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _CONFIGFILE_HPP_
#define _CONFIGFILE_HPP_
#include <fstream>
#include <regex>		// (C++11) regex library
#include <string>
#include <unordered_map>
#include <list>
#include <map>


//! JFC namespace
namespace JFC
{

//! \brief Configuration File class
//!
//! This is a simple read-only class to parse and
//! read a simple INI file.  This class does not support editing,
//! writing or creating INI files.
class ConfigurationFile
{

public:

	//! \brief Open and parse an ini file
	//!
	//! \param filename		filename to be opened and parsed.
	//!
	void parse(const std::string &filename) {
		   std::ifstream input_stream;
		   input_stream.open(filename);
		    if (!input_stream)
        throw std::invalid_argument(filename + " could not be opened");

		    parse(input_stream);
	}

	//! \brief Parse an INI file formatted input stream
	//!
	//! \brief in	input stream.  Input stream can be cin, a stringstream, or istream.
	//!
	void parse(std::istream& in) {
	    static const std::regex comment_regex{R"x(\s*[;#])x"};
	    static const std::regex section_regex{R"x(\s*\[([^\]]+)\])x"};
	    static const std::regex value_regex{R"x(\s*(\S[^ \t=]*)\s*=\s*((\s?\S+)+)\s*$)x"};
	    std::string current_section;
	    std::smatch pieces;
	    for (std::string line; std::getline(in, line);)
	    {
	        if (line.empty() || std::regex_match(line, pieces, comment_regex)) {
	            // skip comment lines and blank lines
	        }
	        else if (std::regex_match(line, pieces, section_regex)) {
	            if (pieces.size() == 2) { // exactly one match
	                current_section = pieces[1].str();
	                std::cout << "Current section = " << current_section << std::endl;
	            }
	        }
	        else if (std::regex_match(line, pieces, value_regex)) {
	            if (pieces.size() == 4) { // exactly enough matches
	                sections[current_section][pieces[1].str()] = pieces[2].str();
	            }
	        }
	    }
	}

	std::string get_value(const std::string &section_name, const std::string &key_name) {
		std::string return_value;
		return_value = sections[section_name][key_name];
		return return_value;
	}

	int get_number_of_sections()
	{
		return sections.size();
	}

private:

	std::unordered_map< std::string, std::unordered_map<std::string, std::string> > sections;

};


}; // namespace
#endif


