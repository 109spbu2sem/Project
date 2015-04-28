#include "settings.h"
#include <fstream>
#include <string>
#include <stdexcept>

void Settings::SettingsLoader::createSettings()
{
	std::fstream setfile;
	setfile.open("config.ini", std::ios_base::out | std::ios_base::trunc);

	setfile << "logmode =0";

	setfile.close();
}

bool Settings::SettingsLoader::Load(Settings* var)
{
	std::fstream setfile;
	setfile.open("config.ini", std::ios_base::in);
	if (setfile.is_open())
	{
		bool ok = false;
		std::string s;
		while (!setfile.eof() && !ok)
		{
			char c;
			setfile.get(c);
			if (c != '\n' && c != '\t' && c != ' ')
				s.push_back(c);
			if (c == '\n')
				s.erase();
			if (c == '=')
			{
				if (s == std::string("logmode="))
				{
					setfile.get(c);
					ok = var->setWritelogMode(c - '0');
				}
			}
		}
		

		setfile.close();
		return ok;
	}
	else return false;
}

void Settings::SettingsLoader::setupSettings(Settings* var)
{
	if (!Load(var))
	{
		createSettings();
		Load(var);
	}
}