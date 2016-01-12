// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
// Svi su include ovdje i u svaki fajl se includa samo "stdafx.h"
#include <iostream>
#include <consoleapi.h>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
#include <conio.h>
#include <functional>
#include <queue>
#include <mutex>
#include <future>
#include <chrono>
#include "json.h"
#include "WinHttpClient.h"
using namespace std;
using namespace string_literals;
using namespace Json;
#include "Weather.h"
#include "Helpers.h"
#include "ASCIIArt.h"
#include "Globals.h"
#include "JsonParse.h"
#include "Menu.h"