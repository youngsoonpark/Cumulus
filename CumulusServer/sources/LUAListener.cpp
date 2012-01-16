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

#include "LUAListener.h"
#include "Listener.h"
#include "LUAQualityOfService.h"

using namespace Cumulus;

const char*		LUAListener::Name="Cumulus::Listener";


int LUAListener::Get(lua_State *pState) {
	SCRIPT_CALLBACK(Listener,LUAListener,listener)
		SCRIPT_READ_STRING(name,"")
		if(name=="id") {
			SCRIPT_WRITE_NUMBER(listener.id)
		} else if(name=="audioQOS") {
			SCRIPT_WRITE_OBJECT(QualityOfService,LUAQualityOfService,listener.audioQOS())
		} else if(name=="videoQOS") {
			SCRIPT_WRITE_OBJECT(QualityOfService,LUAQualityOfService,listener.videoQOS())
		}
	SCRIPT_CALLBACK_RETURN
}

int LUAListener::Set(lua_State *pState) {
	SCRIPT_CALLBACK(Listener,LUAListener,listener)
		SCRIPT_READ_STRING(name,"")
		lua_rawset(pState,1); // consumes key and value
	SCRIPT_CALLBACK_RETURN
}