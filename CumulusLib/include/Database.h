/* 
	Copyright 2010 OpenRTMFP
 
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License received along this program for more
	details (or else see http://www.gnu.org/licenses/).

	This file is a part of Cumulus.
*/

#pragma once

#include "Cumulus.h"
#include "DataStream.h"
#include "Poco/Data/Session.h"
#include "Poco/RWLock.h"

namespace Cumulus {

class CUMULUS_API Database
{
public:
	Database();
	virtual ~Database();

	static bool Load(const std::string& connector,const std::string& connectionString);
	static bool Loaded();
	static void Unload();

	DataStream Database::reader();
	DataStream Database::writer();

private:
	Poco::Data::Session* _pSession;
	
	static Poco::RWLock	s_rwLock;
	static std::string	s_connector;
	static std::string	s_connectionString;
};

inline bool Database::Loaded() {
	return !s_connector.empty();
}


} // namespace Cumulus