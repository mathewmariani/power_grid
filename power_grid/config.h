#pragma once
class CGameData;

class Config {
public:
	static void LoadGame(CGameData *data);
	static void SaveGame(CGameData *data);
};