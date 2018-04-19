/*
 * Copyright 2018 Joe Turner
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
    void parse(const std::string &filename);

    //! \brief Parse an INI file formatted input stream
    //!
    //! \brief in	input stream.  Input stream can be cin, a stringstream, or istream.
    //!
    void parse(std::istream& in);

    //! \brief Returns a value
    std::string get_value(const std::string &section_name, const std::string &key_name);

    //! \returns number of sections loaded
    int get_number_of_sections() const;

private:

    std::unordered_map< std::string, std::unordered_map<std::string, std::string> > sections;

};


}; // namespace
#endif


