#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
private:
	unsigned writelog;
public:
	Settings()
	{
		writelog = 0;
	}
	bool setWritelogMode(unsigned mode)
	{
		if (mode == 2 || mode == 1 || mode == 0)
		{
			writelog = mode;
			return true;
		}
		return false;
	}

	unsigned WritelogMode() const
	{
		return writelog;
	}

	class SettingsLoader
	{
	private:

		static void createSettings();
	public:

		static void setupSettings(Settings*);
	private:
		static bool Load(Settings*);
	};

};

#endif