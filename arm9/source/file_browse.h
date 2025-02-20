/*-----------------------------------------------------------------
 Copyright (C) 2005 - 2010
	Michael "Chishm" Chisholm
	Dave "WinterMute" Murphy

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

------------------------------------------------------------------*/

#ifndef FILE_BROWSE_H
#define FILE_BROWSE_H

#include <string>
#include <vector>

struct DirEntry {
	DirEntry(std::string name, off_t size, bool isDirectory, bool isApp, bool selected = false) : name(name), size(size), isDirectory(isDirectory), isApp(isApp), selected(selected) {}
	DirEntry() {}

	std::string name;
	off_t size;
	bool isDirectory;
	bool isApp;
	bool selected = false;
};

enum class FileOperation {
	none,
	bootFile,
	bootstrapFile,
	mountNitroFS,
	ndsInfo,
	trimNds,
	mountImg,
	restoreSaveNds,
	restoreSaveGba,
	showInfo,
	copySdOut,
	copyFatOut,
	calculateSHA1,
	hexEdit,
	loadFont,
};

bool extension(const std::string_view filename, const std::vector<std::string_view> &extensions);

std::string browseForFile (void);
bool getDirectoryContents (std::vector<DirEntry>& dirContents);



#endif //FILE_BROWSE_H
