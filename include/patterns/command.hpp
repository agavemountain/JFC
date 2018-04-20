/*
 * @(#) Command.hpp
 *
 * @author Joe Turner (joe@agavemountain.com)
 *
 * Copyright (c) 2013 Agave Mountain, Inc.
 * All rights reserved.
 *
 * This software is confidential and proprietary information of Agave Mountain
 * ("Confidential Information").  You shall not disclose such Confidential
 * Information and shall use it only in accordance with the terms of the
 * license agreement you entered into with Agave Mountain.
 *
 * Copyright (C) 2013 Agave Mountain, Inc.; All right reserved.
 */
#ifndef COMMAND_HPP_
#define COMMAND_HPP_
namespace JFC
{
namespace patterns
{

//! \brief Command pattern interface class
//!
class Command {
public:
    virtual void execute() = 0;
};

}
}

#endif /* COMMAND_HPP_ */
