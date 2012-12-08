// ctor.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <string>
#include <tuple>
#include <exception>

using namespace std;

struct FileException : public exception {};

class FileResultStruct;

	typedef enum ReadWriteEnum
	{
		ReadOnly,
		WriteOnly,
		ReadWrite
	} ReadWriteType;

	typedef enum CreationEnum
	{
		CreateIfNotExists,
		DontCreateIfNotExists
	} CreationType;

	typedef enum WritingEnum
	{
		AppendWhenWriting,
		OverrideWhenWriting
	} WritingType;

	typedef enum AccessEnum
	{
		ExclusiveAccess,
		NonExclusiveAccess
	} AccessType;

struct FileOpenConfig
{
	std::string Path;
	ReadWriteType ReadWrite;
	CreationType CreationMethod;
	WritingType WriteMethod;
	AccessType Access;
};

struct ReadOnly
{
};
struct WriteOnly{};
// File wird mit Pfad und einer Konfiguration erzeugt.
// Die Konfiguration beinhaltet
// read-write
// createIfNotExist
// appendWhenWriting
// exclusiveAccess
class File
{
public:

	File(){}
	File(std::string path, std::string config) throw(FileException) {}
	File(std::string path, bool write, bool read, bool createIfNotExist, bool appendWhenWriting, bool exclusiveAccess) throw(FileException) {}
	File(std::string path, ReadWriteType readWrite, CreationType creation, WritingType writing, AccessType access) throw(FileException) {}

	static File createReadOnly(std::string path, AccessType access) throw(FileException) { return File(); }
	static bool createReadOnly(File& file, std::string path, AccessType access)
	{
		try
		{
			file = File(path, ReadOnly, CreateIfNotExists, AppendWhenWriting, access);
			return true;
		}
		catch(...)
		{
			return false;
		}
	}
	static File createWriteOnly(std::string path, CreationType creation, WritingType writing, AccessType access) throw(FileException) { return File(); }
	static File createReadWrite(std::string path, CreationType creation, WritingType writing, AccessType access) throw(FileException) { return File(); }

	static File* createReadOnlyFileAsPointerWithoutException(std::string path, AccessType access){ return 0; }
	typedef tr1::tuple<bool, File> FileResultTuple;
	static FileResultTuple createReadOnlyFileAsTupleWithoutException(std::string path, AccessType access){ return FileResultTuple(); }
	//static FileResultStruct createReadOnlyFileAsStructWithoutException(std::string path, AccessType access){ return FileResultStruct(); }
};

class FileResultStruct
{
public:
	File F;
	bool Created;
};

int _tmain(int argc, _TCHAR* argv[])
{
	// - 2x der Selbe Parametertyp (Vertauschung)
	// - konfiguration ist sehr umständlich zu parsen
	// - die Angabe von Kofiguration kann ungültig sein
	// - die Konfiguration kann unvollständig sein
	File f1("rwe", "myFile.txt");
	// - 6 Parameter sind zuviele Parameter
	// - 5x der Selbe Parametertyp (Vertauschung)
	// - konfiguration ist umständlich zu parsen
	// - Konfiguration nicht erkennbar
	//  - Header muss zur Verifikation herrangezogen werden
	File f2("myFile.txt", true, true, false, false, true);
	// - 5 Parameter sind zuviele Parameter
	// - Konfiguration ist umständlich zu parsen
	// - Parameter schließen sich gegenseitig aus
	//  - z.B. Angabe von WritingType sinnlos, wenn ReadWriteType ReadOnly ist
	// + keine Vertauschung möglich
	// + Konfiguration ist erkennbar
	File f3("myFile.txt", File::ReadWrite, File::CreateIfNotExists, File::AppendWhenWriting, File::ExclusiveAccess);
	// + nur 2 Parameter
	// + keine Vertauschung möglich
	// + Konfiguration ist erkennbar
	// + Parameter schließen sich nicht aus
	// + Konfiguration ist leicht zu parsen
	File f4  = File::createReadOnly("myFile.txt", File::ExclusiveAccess);
	// Exception Ja oder Nein
	// Die Entscheidung dem Kunden überlassen!
	try
	{
		File f5("myFile.txt", File::ReadWrite, File::CreateIfNotExists, File::AppendWhenWriting, File::ExclusiveAccess);
	}
	catch(const FileException& e)
	{
	}
	File f6; // erzeugt Null-Objekt
	if(File::createReadOnly(f6, "myFile.txt", File::ExclusiveAccess))
	{
	}
	else
	{
	}
	// oder createMethode gibt pointer zurück
	if(File* f7 = File::createReadOnlyFileAsPointerWithoutException("myFile.txt", File::ExclusiveAccess))
	{
	}
	else
	{
	}
	// oder createMethode gibt struct zurück
	/*
	FileResultStruct fileStruct = File::createReadOnlyFileAsStructWithoutException("myFile.txt", File::ExclusiveAccess);
	if(fileStruct.Created)
	{
		File f8 = fileStruct.F;
	}
	else
	{
	}
	*/
	// oder createMethode gibt tuple zurück
	File::FileResultTuple fileTuple = File::createReadOnlyFileAsTupleWithoutException("myFile.txt", File::ExclusiveAccess);
	if(tr1::get<0>(fileTuple))
	{
		File f9 = tr1::get<1>(fileTuple);
	}
	else
	{
	}
	// - Konfiguration ist umständlich zu parsen
	// + keine Vertauschung möglich
	// + Konfiguration ist erkennbar
	File f7 = File::createWriteOnly("myFile.txt", File::CreateIfNotExists, File::AppendWhenWriting, File::ExclusiveAccess);
	FileOpenConfig fileConfig = {};
	fileConfig.Access = 
	File f8 = File(fileConfig);

	File f9 = File(
		FileOpenConfig()
		.readWrite()
		.accessExclusive()
		.appendWhenWriting()
		.createIfNotExists());

	File f10 = File("myFile.txt", ReadOnly());
	File f10 = File("myFile.txt", WriteOnly());
	return 0;
}

