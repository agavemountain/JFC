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
namespace Patterns
{

//! \brief Command pattern interface class
//!
//! The command pattern is a behavioral design pattern in which
//! an object is used to encapsulate all the information needed to
//! perform an action, now or later.
//!
//! Command decouples the object that invokes the operation from
//! the code that wishes to perform the action(s).
//!
//! To use, create one or more derived classes that encapsulate some
//! parameters and actions.
//!
//! Common usages:
//! - undo and redo actions
//! - asynchronous method invocations
//! - and more
class Command {
public:
    virtual void execute() = 0;
};

}
}

#endif /* COMMAND_HPP_ */
