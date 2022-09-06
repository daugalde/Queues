#pragma once
#include <iostream>
#include <fstream>
#include "StaticQueue.h"

using namespace std;

class FileLoader {

private:
	StaticQueue files;

public:
	FileLoader() {
	}

	~FileLoader();

	int LoadFiles();

	List GetListToProcess();
};