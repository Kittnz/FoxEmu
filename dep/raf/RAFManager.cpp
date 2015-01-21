#include "RAFManager.h"
#include "tinydir.h"
#include "Stdafx.h"

using namespace std;

RAFManager* RAFManager::instance = 0;

bool RAFManager::init(const string& rootDirectory)
{
    tinydir_dir dir;

    if (tinydir_open_sorted(&dir, rootDirectory.c_str()) == -1)
        return false;

    for (size_t i = 0; i < dir.n_files; i++)
    {
        tinydir_file file;
        tinydir_readfile_n(&dir, &file, i);

        if (!file.is_dir || strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
            continue;

        tinydir_dir subDir;
        tinydir_open_sorted(&subDir, (rootDirectory + '/' + file.name).c_str());

        for (size_t j = 0; j < subDir.n_files; j++)
        {
            tinydir_file subFile;
            tinydir_readfile_n(&subDir, &subFile, j);

            string filename(subFile.name);
            string check = ".raf";

            if (filename.length() >= 5 && filename.find(check) && filename[filename.length()-1] == 'f')
            {
                string rafPath = rootDirectory + '/' + file.name + '/' + filename;
                RAFFile* raf = new RAFFile(rafPath);
                files.push_back(raf);
            }
        }

        tinydir_close(&subDir);
    }

    printf(">> Loaded %lu RAF files", files.size());

    tinydir_close(&dir);

    return true;
}

bool RAFManager::readFile(const std::string& path, vector<unsigned char>& toFill)
{
    for (vector<RAFFile*>::iterator it = files.begin(); it != files.end(); ++it)
    {
        RAFFile* f = *it;

        if (f->readFile(path, toFill))
            return true;
    }

   return false;
}
