/*
 * Copyright (c) 2010-2012 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "otclient.h"
#include <framework/core/modulemanager.h>
#include "core/game.h"

OTClient::OTClient() : Application(Otc::AppCompactName)
{

}

void OTClient::init(const std::vector<std::string>& args)
{
    logInfo(Otc::AppName, " ", Otc::AppVersion);
    Application::init(args, Fw::AppEnableAll);

    g_modules.discoverModules();
    g_modules.autoLoadModules(100);
    g_modules.ensureModuleLoaded("client");
    g_modules.autoLoadModules(1000);
}

void OTClient::close()
{
    if(g_game.isOnline())
        g_game.logout(true);
    exit();
}
